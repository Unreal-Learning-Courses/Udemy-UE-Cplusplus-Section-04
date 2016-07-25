// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	
public:

	// -1 is max downward speed, and +1 is max up movement
	void Elevate(float relativeSpeed);

private:

	UPROPERTY(EditAnywhere, Category = Setup)
		float maxDegreesPerSecond = 20; // Sensible default

	UPROPERTY(EditAnywhere, Category = Setup)
		float minElevation = 0; // default

	UPROPERTY(EditAnywhere, Category = Setup)
		float maxElevation = 40; // default
	
};
