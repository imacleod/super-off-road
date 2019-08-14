// Ian MacLeod

#include "SuperOffRoadPawnTruck.h"
#include "SuperOffRoadWheelFront.h"
#include "SuperOffRoadWheelRear.h"
#include "SuperOffRoadPlayerState.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/SkeletalMesh.h"
#include "UObject/ConstructorHelpers.h"
#include "WheeledVehicleMovementComponent4W.h"


ASuperOffRoadPawnTruck::ASuperOffRoadPawnTruck()
{
	// Skeletal mesh
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> TruckSkeletalMesh(TEXT("/Game/Vehicles/Meshes/SK_Truck"));
	GetMesh()->SetSkeletalMesh(TruckSkeletalMesh.Object);

	// Animation blueprint
	static ConstructorHelpers::FClassFinder<UObject> TruckAnimBP(TEXT("/Game/Vehicles/Blueprints/Truck_AnimBlueprint"));
	GetMesh()->SetAnimInstanceClass(TruckAnimBP.Class);

	// Movement component
	UWheeledVehicleMovementComponent4W* VehicleMC = CastChecked<UWheeledVehicleMovementComponent4W>(GetVehicleMovement());
	VehicleMC->Mass = 1500.f;
	check(VehicleMC->WheelSetups.Num() == 4);
	VehicleMC->WheelSetups[0].WheelClass = USuperOffRoadWheelFront::StaticClass();
	VehicleMC->WheelSetups[0].BoneName = FName("FL");
	VehicleMC->WheelSetups[1].WheelClass = USuperOffRoadWheelFront::StaticClass();
	VehicleMC->WheelSetups[1].BoneName = FName("FR");
	VehicleMC->WheelSetups[2].WheelClass = USuperOffRoadWheelRear::StaticClass();
	VehicleMC->WheelSetups[2].BoneName = FName("RL");
	VehicleMC->WheelSetups[3].WheelClass = USuperOffRoadWheelRear::StaticClass();
	VehicleMC->WheelSetups[3].BoneName = FName("RR");
}

void ASuperOffRoadPawnTruck::BeginPlay()
{
	Super::BeginPlay();
	SetPlayerNumber();
}

bool ASuperOffRoadPawnTruck::IsHandbrakeOverridden() const
{
	return bHandbrakeOverridden;
}

void ASuperOffRoadPawnTruck::SetPlayerNumber() const
{
	ASuperOffRoadPlayerState* PlayerState = CastChecked<ASuperOffRoadPlayerState>(this->PlayerState);
	if (this->ActorHasTag(FName(TEXT("P1"))))
	{
		PlayerState->SetPlayerNumber(1);
	}
	else if (this->ActorHasTag(FName(TEXT("P2"))))
	{
		PlayerState->SetPlayerNumber(2);
	}
	else if (this->ActorHasTag(FName(TEXT("P3"))))
	{
		PlayerState->SetPlayerNumber(3);
	}
	else if (this->ActorHasTag(FName(TEXT("P4"))))
	{
		PlayerState->SetPlayerNumber(4);
	}
}

void ASuperOffRoadPawnTruck::SetHandbrakeOverridden(const bool bIsOverridden)
{
	bHandbrakeOverridden = bIsOverridden;
}
