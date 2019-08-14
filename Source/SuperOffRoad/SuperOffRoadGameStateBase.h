// Ian MacLeod

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "SuperOffRoadGameStateBase.generated.h"

class ASuperOffRoadGameModeBase;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRaceWonDelegate, int32, PlayerNum);


UCLASS()
class SuperOffRoad_API ASuperOffRoadGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

public:
	ASuperOffRoadGameStateBase();

	/** Get lap counts for all players */
	UFUNCTION(BlueprintCallable, Category="RaceStatus")
	int32 GetPlayerLap(const int32 PlayerNum) const;

	/** Get time elapsed since race start */
	UFUNCTION(BlueprintCallable, Category="RaceStatus")
	float GetRaceTime() const;

	/** Is race in progress? */
	UFUNCTION(BlueprintCallable, Category="RaceStatus")
	bool IsRaceActive() const;

	/** Delegate for race won */
	UPROPERTY(BlueprintAssignable, Category="RaceEvent")
	FOnRaceWonDelegate RaceWonDelegate;

	/** Set race status to in progress */
	void SetRaceActive();

	/** Set time race ended */
	void SetRaceEndTime(const float EndTime);

	/** Set race status to finished */
	void SetRaceInactive();

	/** Set time race began */
	void SetRaceStartTime(const float StartTime);

	virtual void Tick(float DeltaSeconds) override;

	/** Update lap count for PlayerNumber */
	void UpdateLap(const int32 PlayerNum, const int32 Lap);

protected:
	virtual void BeginPlay() override;

private:
	/** Game mode */
	ASuperOffRoadGameModeBase* GameMode;

	/** Is race in progress? */
	UPROPERTY(Transient)
	bool bIsRaceActive = false;

	/** Fill PlayerLaps map */
	void InitializePlayerLaps();

	/** Map of <PlayerNumber, current lap> */
	TMap<int32, int32> PlayerLaps;

	/** Total race time */
	UPROPERTY(Transient)
	float RaceCurrentTime = 0.f;

	/** Timestamp of race end */
	float RaceEndTime = 0.f;

	/** Timestamp of race start */
	float RaceStartTime = 0.f;

	/** Update current race time */
	void SetRaceTime(const float CurrentTime);
};
