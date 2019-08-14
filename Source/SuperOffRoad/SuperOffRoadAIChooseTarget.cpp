// Ian MacLeod

#include "SuperOffRoadAIChooseTarget.h"
#include "SuperOffRoadPawnTruckAI.h"
#include "SuperOffRoadRaceNavigationComponent.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type USuperOffRoadAIChooseTarget::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// Set current race target point and increment next race target point index before calling MoveTo
	AAIController* AIController = OwnerComp.GetAIOwner();
	ASuperOffRoadPawnTruckAI* ControlledPawn = Cast<ASuperOffRoadPawnTruckAI>(AIController->GetPawn());

	if (ControlledPawn == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("ChooseTarget: No controlled pawn available on AI controller"));
		return EBTNodeResult::Failed;
	}

	USuperOffRoadRaceNavigationComponent* RaceNavComponent = ControlledPawn->FindComponentByClass<USuperOffRoadRaceNavigationComponent>();
	if (RaceNavComponent != nullptr)
	{
		// Get all race target points from pawn
		TArray<AActor*> RaceTargetPoints = RaceNavComponent->GetRaceTargetPoints();
		if (RaceTargetPoints.Num() == 0)
		{
			UE_LOG(LogTemp, Error, TEXT("ChooseTarget: Race navigation component has empty race target points array"));
			return EBTNodeResult::Failed;
		}

		// Set race target point
		UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
		int32 TargetPointIndex = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
		BlackboardComp->SetValueAsObject(TargetKey.SelectedKeyName, RaceTargetPoints[TargetPointIndex]);

		// Increment next race target point index
		int32 NextTargetPointIndex = ++TargetPointIndex % RaceTargetPoints.Num();
		BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextTargetPointIndex);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("ChooseTarget: No race navigation component found on pawn"));
		return EBTNodeResult::Failed;
	}

	return EBTNodeResult::Succeeded;
}
