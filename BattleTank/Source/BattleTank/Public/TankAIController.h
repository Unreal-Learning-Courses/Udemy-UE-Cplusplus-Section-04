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
	//ATank* GetPlayerTank() const;
	virtual void Tick(float DeltaSeconds) override;
	
	// How close can the AI tank get 
	float acceptanceRadius = 3000;
};
