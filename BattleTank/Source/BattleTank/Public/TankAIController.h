// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "Tank.h"
#include "AIController.h"
#include "TankAIController.generated.h"

//class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	//ATank* GetControlledTank() const;
	virtual void BeginPlay() override;

	virtual void SetPawn(APawn* InPawn) override;

	//ATank* GetPlayerTank() const;
	virtual void Tick(float DeltaSeconds) override;
	
	// How close can the AI tank get
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float acceptanceRadius = 8000;

	UFUNCTION()
		void onPossedTankDeath();

	ATank* possessedTank = nullptr;
};
