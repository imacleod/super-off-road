// Ian MacLeod

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "SuperOffRoadLapTriggerBox.generated.h"


/** Final trigger box to complete a lap */
UCLASS()
class SuperOffRoad_API ASuperOffRoadLapTriggerBox : public ATriggerBox
{
	GENERATED_BODY()

public:
	ASuperOffRoadLapTriggerBox();

	// UFUNCTION to allow for delegate use in constructor/AddDynamic
	UFUNCTION()
	void OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor);
};
