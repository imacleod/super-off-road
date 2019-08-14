// Ian MacLeod

#include "SuperOffRoadPawnTruckPlayer.h"
#include "Components/InputComponent.h"
#include "WheeledVehicleMovementComponent4W.h"


void ASuperOffRoadPawnTruckPlayer::BeginPlay()
{
	Super::BeginPlay();
	VehicleMC = CastChecked<UWheeledVehicleMovementComponent4W>(GetVehicleMovement());
}

void ASuperOffRoadPawnTruckPlayer::MoveForwardBackward(float Val)
{
	if ((VehicleMC == nullptr) || IsHandbrakeOverridden())
	{
		return;
	}
	else if (VehicleMC != nullptr)
	{
		VehicleMC->SetThrottleInput(Val);
	}
}

void ASuperOffRoadPawnTruckPlayer::MoveLeftRight(float Val)
{
	if ((VehicleMC == nullptr) || IsHandbrakeOverridden())
	{
		return;
	}
	else if (VehicleMC != nullptr)
	{
		VehicleMC->SetSteeringInput(Val);
	}
}

void ASuperOffRoadPawnTruckPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Setup input key bindings
	check(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForwardBackward", this, &ASuperOffRoadPawnTruckPlayer::MoveForwardBackward);
	PlayerInputComponent->BindAxis("MoveLeftRight", this, &ASuperOffRoadPawnTruckPlayer::MoveLeftRight);
}
