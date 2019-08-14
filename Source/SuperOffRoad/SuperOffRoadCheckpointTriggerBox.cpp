// Ian MacLeod

#include "SuperOffRoadCheckpointTriggerBox.h"
#include "SuperOffRoadPawnTruck.h"
#include "SuperOffRoadPlayerState.h"


ASuperOffRoadCheckpointTriggerBox::ASuperOffRoadCheckpointTriggerBox()
{
	// Add delegate for overlap event
	OnActorBeginOverlap.AddDynamic(this, &ASuperOffRoadCheckpointTriggerBox::OnOverlapBegin);
}

void ASuperOffRoadCheckpointTriggerBox::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	if ((OtherActor != nullptr) && (OtherActor != this))
	{
		if (ASuperOffRoadPawnTruck* PawnTruck = Cast<ASuperOffRoadPawnTruck>(OtherActor))
		{
			ASuperOffRoadPlayerState* PlayerState = CastChecked<ASuperOffRoadPlayerState>(PawnTruck->PlayerState);
			PlayerState->CheckpointReached(this);
		}
	}
}
