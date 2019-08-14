// Ian MacLeod

#pragma once

#include "CoreMinimal.h"
#include "SuperOffRoadPawnTruck.h"
#include "SuperOffRoadPawnTruckAI.generated.h"


UCLASS()
class SuperOffRoad_API ASuperOffRoadPawnTruckAI : public ASuperOffRoadPawnTruck
{
	GENERATED_BODY()

public:
	ASuperOffRoadPawnTruckAI();

	/** Get current steering angle */
	float GetSteeringAngle() const;

	/** Get navigation steering target */
	FVector GetSteeringTarget() const;

	/** Get current throttle */
	float GetThrottle() const;

	/** Set current steering angle */
	void SetSteeringAngle(const float SteerAngle);

	/** Set current throttle */
	void SetThrottle(const float Throt);

	/** Update navigation steering target */
	UFUNCTION(BlueprintCallable, Category="RaceNavigation")
	void SetSteeringTarget(const FVector Target);

private:
	/** Current steering angle */
	float SteeringAngle;

	/** Location AI will steer towards */
	FVector SteeringTarget;

	/** Current throttle */
	float Throttle;
};
