// Ian MacLeod

#include "SuperOffRoadPawnTruckAI.h"
#include "SuperOffRoadAIController.h"


ASuperOffRoadPawnTruckAI::ASuperOffRoadPawnTruckAI()
{
	AIControllerClass = ASuperOffRoadAIController::StaticClass();
}

float ASuperOffRoadPawnTruckAI::GetSteeringAngle() const
{
	return SteeringAngle;
}

FVector ASuperOffRoadPawnTruckAI::GetSteeringTarget() const
{
	return SteeringTarget;
}

float ASuperOffRoadPawnTruckAI::GetThrottle() const
{
	return Throttle;
}

void ASuperOffRoadPawnTruckAI::SetSteeringAngle(const float SteerAngle)
{
	SteeringAngle = SteerAngle;
}

void ASuperOffRoadPawnTruckAI::SetSteeringTarget(const FVector Target)
{
	SteeringTarget = Target;
}

void ASuperOffRoadPawnTruckAI::SetThrottle(const float Throt)
{
	// Valid throttle range is 0-1
	Throttle = FMath::Clamp(Throt, 0.f, 1.f);
}
