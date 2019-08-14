// Ian MacLeod

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "SuperOffRoadPlayerState.generated.h"

class ASuperOffRoadCheckpointTriggerBox;
class ASuperOffRoadGameStateBase;


UCLASS()
class SuperOffRoad_API ASuperOffRoadPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	ASuperOffRoadPlayerState();

	/** Confirm all checkpoints reached */
	void CheckLapComplete();

	/** Confirm checkpoint reached in correct order */
	void CheckpointReached(const ASuperOffRoadCheckpointTriggerBox* Checkpoint);

	/** Set player number from tag */
	void SetPlayerNumber(const int32 PlayerNum);

protected:
	virtual void BeginPlay() override;

private:
	bool bCheckpoint1Complete;
	bool bCheckpoint2Complete;
	bool bCheckpoint3Complete;

	/** Game state */
	ASuperOffRoadGameStateBase* GameState;

	/** Lap completed */
	void LapComplete();

	int32 LapCurrent = 1;

	/** Player number 1-4 */
	int32 PlayerNumber;

	void ResetCheckpoints();

	/** Set checkpoint as completed */
	void SetCheckpoint(const int32 CheckpointNum);
};
