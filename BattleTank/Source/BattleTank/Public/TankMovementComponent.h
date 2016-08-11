// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;

/**
 *  Responsible form driving the tank tracks
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:

	
	UFUNCTION(BlueprintCallable, Category = Setup)
		void Initialize(UTankTrack * leftTrackToSet, UTankTrack * rightTrackToSet);

	UFUNCTION(BlueprintCallable, Category = Input)
		void IntendMoveForward(float controlThrow);
	
	UFUNCTION(BlueprintCallable, Category = Input)
		void IntendTurnRight(float controlThrow);




private:

	UTankTrack* leftTrack = nullptr;
	UTankTrack* rightTrack = nullptr;

	// Called from the pathfinding logic by the AI controller
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
	


};

