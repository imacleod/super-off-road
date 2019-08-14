// Ian MacLeod

#include "SuperOffRoadGameModeBase.h"
#include "SuperOffRoadGameStateBase.h"
#include "SuperOffRoadPawnTruck.h"
#include "SuperOffRoadPlayerController.h"
#include "SuperOffRoadPlayerState.h"
#include "Engine/World.h"
#include "TimerManager.h"


ASuperOffRoadGameModeBase::ASuperOffRoadGameModeBase()
{
	GameStateClass = ASuperOffRoadGameStateBase::StaticClass();
	PlayerControllerClass = ASuperOffRoadPlayerController::StaticClass();
	PlayerStateClass = ASuperOffRoadPlayerState::StaticClass();
}

void ASuperOffRoadGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	GameState = GetGameState<ASuperOffRoadGameStateBase>();
}

void ASuperOffRoadGameModeBase::EndRace() const
{
	if (GameState != nullptr)
	{
		GameState->SetRaceEndTime(GetWorld()->GetTimeSeconds());
		GameState->SetRaceInactive();
		LockPawnMovement(true);
		ASuperOffRoadPlayerController* PlayerController = Cast<ASuperOffRoadPlayerController>(GetWorld()->GetFirstPlayerController());
		PlayerController->Pause();
	}
}

FString ASuperOffRoadGameModeBase::GetRaceCountdownText()
{
	if (RaceCountdownTime > 0)
	{
		return FString::FromInt(RaceCountdownTime);
	}
	else
	{
		return FString("GO!");
	}
}

void ASuperOffRoadGameModeBase::LockPawnMovement(const bool bIsLocked) const
{
	for (FConstControllerIterator Itr = GetWorld()->GetControllerIterator(); Itr; ++Itr)
	{
		if (AController* TruckController = Cast<AController>(*Itr))
		{
			ASuperOffRoadPawnTruck* TruckPawn = CastChecked<ASuperOffRoadPawnTruck>(TruckController->GetPawn());
			TruckPawn->SetHandbrakeOverridden(bIsLocked);
		}
	}
}

void ASuperOffRoadGameModeBase::RaceCountdownComplete() const
{
	// Clear countdown timer
	GetWorldTimerManager().ClearTimer(RaceCountdownHandle);

	// Broadcast countdown complete
	RaceCountdownCompleteDelegate.Broadcast();

	// Start race
	if (GameState != nullptr)
	{
		if (!GameState->IsRaceActive())
		{
			GameState->SetRaceActive();
			GameState->SetRaceStartTime(GetWorld()->GetTimeSeconds());
			LockPawnMovement(false);
		}
	}
}

void ASuperOffRoadGameModeBase::StartRaceCountdown()
{
	GetWorldTimerManager().SetTimer(RaceCountdownHandle, this, &ASuperOffRoadGameModeBase::UpdateCountdownTime, 1.f, true);
}

void ASuperOffRoadGameModeBase::UpdateCountdownTime()
{
	--RaceCountdownTime;

	if (RaceCountdownTime < 1)
	{
		// Countdown finished
		RaceCountdownComplete();
	}
}
