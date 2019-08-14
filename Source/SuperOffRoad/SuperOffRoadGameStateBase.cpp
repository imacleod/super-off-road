// Ian MacLeod

#include "SuperOffRoadGameStateBase.h"
#include "SuperOffRoadGameModeBase.h"
#include "SuperOffRoadPlayerState.h"
#include "Engine/World.h"


ASuperOffRoadGameStateBase::ASuperOffRoadGameStateBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASuperOffRoadGameStateBase::BeginPlay()
{
	Super::BeginPlay();
	GameMode = CastChecked<ASuperOffRoadGameModeBase>(GetWorld()->GetAuthGameMode());
	InitializePlayerLaps();
}

int32 ASuperOffRoadGameStateBase::GetPlayerLap(const int32 PlayerNum) const
{
	return PlayerLaps.FindRef(PlayerNum);
}

float ASuperOffRoadGameStateBase::GetRaceTime() const
{
	return RaceCurrentTime;
}

void ASuperOffRoadGameStateBase::InitializePlayerLaps()
{
	PlayerLaps.Add(1, 1);
	PlayerLaps.Add(2, 1);
	PlayerLaps.Add(3, 1);
	PlayerLaps.Add(4, 1);
}

bool ASuperOffRoadGameStateBase::IsRaceActive() const
{
	return bIsRaceActive;
}

void ASuperOffRoadGameStateBase::SetRaceActive()
{
	bIsRaceActive = true;
}

void ASuperOffRoadGameStateBase::SetRaceEndTime(const float EndTime)
{
	RaceEndTime = EndTime;
}

void ASuperOffRoadGameStateBase::SetRaceInactive()
{
	bIsRaceActive = false;
}

void ASuperOffRoadGameStateBase::SetRaceStartTime(const float StartTime)
{
	RaceStartTime = StartTime;
}

void ASuperOffRoadGameStateBase::SetRaceTime(const float CurrentTime)
{
	RaceCurrentTime = CurrentTime;
}

void ASuperOffRoadGameStateBase::Tick(float DeltaSeconds)
{
	const float CurrentTime = IsRaceActive() ? GetWorld()->GetTimeSeconds() : RaceEndTime;
	SetRaceTime(CurrentTime - RaceStartTime);
}

void ASuperOffRoadGameStateBase::UpdateLap(const int32 PlayerNum, const int32 Lap)
{
	if (GameMode != nullptr)
	{
		int32 MaxLaps = GameMode->LapsMax;

		if (Lap <= MaxLaps)
		{
			PlayerLaps.Add(PlayerNum, Lap);
		}
		else if (Lap > MaxLaps)
		{
			// Race finished
			SetRaceInactive();
			RaceWonDelegate.Broadcast(PlayerNum);
			GameMode->EndRace();
		}
	}
}
