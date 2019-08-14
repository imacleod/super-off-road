// Ian MacLeod

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehicle.h"
#include "SuperOffRoadPawnTruck.generated.h"

class UInputComponent;


/** Base class for player and AI controlled trucks */
UCLASS()
class SuperOffRoad_API ASuperOffRoadPawnTruck : public AWheeledVehicle
{
	GENERATED_BODY()

public:
	ASuperOffRoadPawnTruck();

	/** Is handbrake being forced on */
	bool IsHandbrakeOverridden() const;

	/** Set handbrake forced status */
	void SetHandbrakeOverridden(const bool bIsOverridden);

protected:
	/** Status of handbrake forced on */
	bool bHandbrakeOverridden = true;

	virtual void BeginPlay() override;

	/** Set player number from tag */
	void SetPlayerNumber() const;
};
