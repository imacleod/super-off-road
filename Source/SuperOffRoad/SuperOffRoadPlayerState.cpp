// Ian MacLeod

#include "SuperOffRoadPlayerState.h"
#include "SuperOffRoadGameStateBase.h"
#include "SuperOffRoadCheckpointTriggerBox.h"
#include "Engine/World.h"


ASuperOffRoadPlayerState::ASuperOffRoadPlayerState()
{
	ResetCheckpoints();
}

void ASuperOffRoadPlayerState::BeginPlay()
{
	GameState = CastChecked<ASuperOffRoadGameStateBase>(GetWorld()->GetGameState());
}

void ASuperOffRoadPlayerState::CheckLapComplete()
{
	if (bCheckpoint1Complete && bCheckpoint2Complete && bCheckpoint3Complete)
	{
		LapComplete();
		ResetCheckpoints();
	}
	else
	{
		ResetCheckpoints();
	}
}

void ASuperOffRoadPlayerState::CheckpointReached(const ASuperOffRoadCheckpointTriggerBox* Checkpoint)
{
	if (Checkpoint->ActorHasTag(FName(TEXT("C1"))))
	{
		SetCheckpoint(1);
	}
	else if (Checkpoint->ActorHasTag(FName(TEXT("C2"))))
	{
		if (bCheckpoint1Complete)
		{
			SetCheckpoint(2);
		}
	}
	else if (Checkpoint->ActorHasTag(FName(TEXT("C3"))))
	{
		if (bCheckpoint1Complete && bCheckpoint2Complete)
		{
			SetCheckpoint(3);
		}
	}
}

void ASuperOffRoadPlayerState::LapComplete()
{
	if (GameState != nullptr)
	{
		if (GameState->IsRaceActive())
		{
			GameState->UpdateLap(PlayerNumber, ++LapCurrent);
		}
	}
}

void ASuperOffRoadPlayerState::ResetCheckpoints()
{
	bCheckpoint1Complete = false;
	bCheckpoint2Complete = false;
	bCheckpoint3Complete = false;
}

void ASuperOffRoadPlayerState::SetCheckpoint(const int32 Checkpoint)
{
	switch(Checkpoint) {
		case 1:
			bCheckpoint1Complete = true;
			break;
		case 2:
			bCheckpoint2Complete = true;
			break;
		case 3:
			bCheckpoint3Complete = true;
			break;
		default:
			break;
	}
}

void ASuperOffRoadPlayerState::SetPlayerNumber(const int32 PlayerNum)
{
	PlayerNumber = PlayerNum;
}
