// Ian MacLeod

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "SuperOffRoadCheckpointTriggerBox.generated.h"


/**
 * Checkpoints must be reached before completing a lap.
 * Each checkpoint instance must be given a sequential tag,
 * eg. (C1, C2, C3, etc)
 */
UCLASS()
class SuperOffRoad_API ASuperOffRoadCheckpointTriggerBox : public ATriggerBox
{
	GENERATED_BODY()

public:
	ASuperOffRoadCheckpointTriggerBox();

	UFUNCTION()
	void OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor);
};
