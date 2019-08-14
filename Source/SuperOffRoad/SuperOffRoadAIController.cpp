// Ian MacLeod

#include "SuperOffRoadAIController.h"
#include "SuperOffRoadPawnTruckAI.h"
#include "Kismet/KismetMathLibrary.h"
#include "WheeledVehicleMovementComponent4W.h"


ASuperOffRoadAIController::ASuperOffRoadAIController()
{
	// Use ASuperOffRoadPlayerState
	bWantsPlayerState = true;
}

void ASuperOffRoadAIController::BeginPlay()
{
	Super::BeginPlay();
	PawnTruck = CastChecked<ASuperOffRoadPawnTruckAI>(GetPawn());
	PawnTruckMC = CastChecked<UWheeledVehicleMovementComponent4W>(PawnTruck->GetMovementComponent());
}

void ASuperOffRoadAIController::CalculateSteering() const
{
	if (PawnTruck != nullptr)
	{
		FRotator NewRotation = UKismetMathLibrary::FindLookAtRotation(PawnTruck->GetActorLocation(), PawnTruck->GetSteeringTarget());
		FRotator NormalizedRotation = UKismetMathLibrary::NormalizedDeltaRotator(NewRotation, PawnTruck->GetActorRotation());

		// Out parameters
		float OutBreakRotatorRoll;
		float OutBreakRotatorPitch;
		float OutBreakRotatorYaw;
		UKismetMathLibrary::BreakRotator(NormalizedRotation, OutBreakRotatorRoll, OutBreakRotatorPitch, OutBreakRotatorYaw);

		float NewSteerAngle = UKismetMathLibrary::MapRangeUnclamped(OutBreakRotatorYaw, -90.f, 90.f, -1.f, 1.f);
		PawnTruck->SetSteeringAngle(NewSteerAngle);
	}
}

void ASuperOffRoadAIController::CalculateThrottle() const
{
	if (PawnTruck != nullptr)
	{
		// Negate steering for inverse relationship with throttle
		float SteeringAngle = PawnTruck->GetSteeringAngle();
		if (SteeringAngle > 0)
		{
			SteeringAngle *= -1;
		}

		// Use minimum non-zero throttle to prevent getting stuck
		float NewThrottle = UKismetMathLibrary::MapRangeClamped(SteeringAngle, -1.5, 0.f, 0.3, 1.f);
		PawnTruck->SetThrottle(NewThrottle);
	}
}

void ASuperOffRoadAIController::Drive() const
{
	if ((PawnTruck != nullptr) && (PawnTruckMC != nullptr))
	{
		CalculateSteering();
		PawnTruckMC->SetSteeringInput(PawnTruck->GetSteeringAngle());
		CalculateThrottle();
		PawnTruckMC->SetThrottleInput(PawnTruck->GetThrottle());
	}
}

void ASuperOffRoadAIController::Tick(float DeltaSeconds)
{
	if (PawnTruck == nullptr)
	{
		return;
	}
	else if (PawnTruck->IsHandbrakeOverridden() && (PawnTruckMC != nullptr))
	{
		PawnTruckMC->SetThrottleInput(0.f);
		return;
	}
	Drive();
}
