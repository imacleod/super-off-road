// Ian MacLeod

#include "SuperOffRoadLapTriggerBox.h"
#include "SuperOffRoadPawnTruck.h"
#include "SuperOffRoadPlayerState.h"


ASuperOffRoadLapTriggerBox::ASuperOffRoadLapTriggerBox()
{
	// Add delegate for overlap event
	OnActorBeginOverlap.AddDynamic(this, &ASuperOffRoadLapTriggerBox::OnOverlapBegin);
}

void ASuperOffRoadLapTriggerBox::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	if ((OtherActor != nullptr) && (OtherActor != this))
	{
		if (ASuperOffRoadPawnTruck* PawnTruck = Cast<ASuperOffRoadPawnTruck>(OtherActor))
		{
			ASuperOffRoadPlayerState* PlayerState = CastChecked<ASuperOffRoadPlayerState>(PawnTruck->PlayerState);
			PlayerState->CheckLapComplete();
		}
	}
}
