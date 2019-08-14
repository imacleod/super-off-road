// Ian MacLeod

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SuperOffRoadGameModeBase.generated.h"

class ASuperOffRoadGameStateBase;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRaceCountdownCompleteDelegate);


UCLASS()
class SuperOffRoad_API ASuperOffRoadGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASuperOffRoadGameModeBase();

	/** Ends race */
	void EndRace() const;

	/** Get current race countdown text for HUD */
	UFUNCTION(BlueprintCallable, Category="RaceStatus")
	FString GetRaceCountdownText();

	/** Number of laps required to finish race */
	UPROPERTY(EditDefaultsOnly, Category="RaceRules")
	int32 LapsMax = 3;

	/** Delegate for race countdown */
	UPROPERTY(BlueprintAssignable, Category="RaceEvent")
	FOnRaceCountdownCompleteDelegate RaceCountdownCompleteDelegate;

	/** Begin countdown to race start */
	UFUNCTION(BlueprintCallable, Category="RaceEvent")
	void StartRaceCountdown();

protected:
	virtual void BeginPlay() override;

private:
	/** Game state */
	ASuperOffRoadGameStateBase* GameState;

	/** Lock/unlock pawn movement */
	void LockPawnMovement(const bool bIsLocked) const;

	/** Called once race countdown is complete */
	UFUNCTION(Category="RaceEvent")
	void RaceCountdownComplete() const;

	/** Timer handle used for race countdown */
	FTimerHandle RaceCountdownHandle;

	/** Time remaining in race countdown */
	int32 RaceCountdownTime = 3;

	/** Update countdown time as it progresses */
	void UpdateCountdownTime();
};
