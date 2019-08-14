// Ian MacLeod

#pragma once

#include "CoreMinimal.h"
#include "SuperOffRoadPawnTruck.h"
#include "SuperOffRoadPawnTruckPlayer.generated.h"

class UInputComponent;
class UWheeledVehicleMovementComponent4W;


UCLASS()
class SuperOffRoad_API ASuperOffRoadPawnTruckPlayer : public ASuperOffRoadPawnTruck
{
	GENERATED_BODY()

public:
	/** Pawn movement forward/backward */
	void MoveForwardBackward(float Val);

	/** Pawn movement left/right */
	void MoveLeftRight(float Val);

	/** Pawn interface */
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

private:
	UWheeledVehicleMovementComponent4W* VehicleMC;
};
