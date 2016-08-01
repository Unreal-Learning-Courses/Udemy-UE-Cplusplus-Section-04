// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // Must be the last include

class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	FVector hitLocation;
	//FVector cameraLocation;

	ATank* GetControlledTank() const;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& hitLocation) const;

	bool GetLookDirection(FVector2D screenLocation, FVector& lookDirection) const;

	bool GetLookVectorHitLocation(FVector& hitLocation, FVector& lookDirection) const;
	

	UPROPERTY(EditDefaultsOnly)
		float crossHairXLocation = 0.5;
	UPROPERTY(EditDefaultsOnly)
		float crossHairYLocation = 0.33333;
	UPROPERTY(EditDefaultsOnly)
		float reach = 10000000.0;

	
};

