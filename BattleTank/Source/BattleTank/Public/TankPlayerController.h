// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // Must be the last include

//class ATank;
class UTankAimingComponent;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	//UFUNCTION(BlueprintCallable, Category = Setup)
		//ATank* GetControlledTank() const;
	UFUNCTION(BlueprintImplementableEvent, Category = Setup)
		void FoundAimingComponent(UTankAimingComponent* aimCompRef);


private:
	FVector hitLocation;
	//FVector cameraLocation;

	
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

