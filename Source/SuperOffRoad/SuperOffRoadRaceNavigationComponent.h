// Ian MacLeod

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SuperOffRoadRaceNavigationComponent.generated.h"


/** Old AI navigation using behavior tree and target points, leaving for reference
 *  ActorComponent used by AI players to navigate racetrack via target points
*/
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SuperOffRoad_API USuperOffRoadRaceNavigationComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	TArray<AActor*> GetRaceTargetPoints() const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RaceNavigation")
	TArray<AActor*> RaceTargetPoints;
};
