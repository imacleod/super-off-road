// Ian MacLeod

#pragma once

#include "CoreMinimal.h"
#include "VehicleWheel.h"
#include "SuperOffRoadTireConfig.h"
#include "SuperOffRoadWheelRear.generated.h"


UCLASS()
class USuperOffRoadWheelRear : public UVehicleWheel
{
	GENERATED_BODY()

public:
	USuperOffRoadWheelRear();

	USuperOffRoadTireConfig* RearTireConfig = NewObject<USuperOffRoadTireConfig>();
};
