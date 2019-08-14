// Ian MacLeod

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "SuperOffRoadAIChooseTarget.generated.h"


/** Old AI navigation using behavior tree and target points, leaving for reference 
 *  Behavior tree task to determine next target point on track for AI to head towards
 */
UCLASS()
class SuperOffRoad_API USuperOffRoadAIChooseTarget : public UBTTaskNode
{
	GENERATED_BODY()

public:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
	UPROPERTY(EditAnywhere, Category="RaceNavigation")
	struct FBlackboardKeySelector IndexKey;

	UPROPERTY(EditAnywhere, Category="RaceNavigation")
	struct FBlackboardKeySelector TargetKey;
};
