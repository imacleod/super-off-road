// Ian MacLeod

#pragma once

#include "CoreMinimal.h"
#include "VehicleWheel.h"
#include "SuperOffRoadTireConfig.h"
#include "SuperOffRoadWheelFront.generated.h"


UCLASS()
class USuperOffRoadWheelFront : public UVehicleWheel
{
	GENERATED_BODY()

public:
	USuperOffRoadWheelFront();

	USuperOffRoadTireConfig* FrontTireConfig = NewObject<USuperOffRoadTireConfig>();
};
