// Ian MacLeod

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "SuperOffRoadAIController.generated.h"

class ASuperOffRoadPawnTruckAI;
class UWheeledVehicleMovementComponent4W;


UCLASS()
class SuperOffRoad_API ASuperOffRoadAIController : public AAIController
{
	GENERATED_BODY()

public:
	ASuperOffRoadAIController();

	virtual void Tick(float DeltaSeconds) override;

protected:
	virtual void BeginPlay() override;

private:
	/** Calculate steering angle of wheels towards navigation target */
	void CalculateSteering() const;

	/** Calculate throttle rate based on current steering angle */
	void CalculateThrottle() const;

	/** Drive while managing steering angle and throttle */
	void Drive() const;

	/** Controlled pawn */
	ASuperOffRoadPawnTruckAI* PawnTruck;

	/** Controlled pawn's movement component */
	UWheeledVehicleMovementComponent4W* PawnTruckMC;
};
