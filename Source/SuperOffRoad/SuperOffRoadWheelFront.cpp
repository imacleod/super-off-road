// Ian MacLeod

#include "SuperOffRoadWheelFront.h"


USuperOffRoadWheelFront::USuperOffRoadWheelFront()
{
	bAffectedByHandbrake = false;
	DampingRate = 0.25f;
	LatStiffMaxLoad = 5.f;
	LatStiffValue = 1000.f;
	LongStiffValue = 1000.f;
	Mass = 20.f;
	MaxBrakeTorque = 4000.f;
	MaxHandBrakeTorque = 6000.f;
	Offset = FVector(0.f, -58.f, 0.f);
	ShapeRadius = 130.f;
	ShapeWidth = 58.f;
	SteerAngle = 50.f;
	SuspensionDampingRatio = 1.1f;
	SuspensionForceOffset = 0.f;
	SuspensionMaxDrop = 40.f;
	SuspensionMaxRaise = 20.f;
	SuspensionNaturalFrequency = 10.f;
	TireConfig = FrontTireConfig;
}
