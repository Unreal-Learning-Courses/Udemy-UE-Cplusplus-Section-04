// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"




void UTankBarrel::Elevate(float relativeSpeed) {


	// Move the barrel the right amount this frame

	// Given a max elevation speed and the frame time
	relativeSpeed = FMath::Clamp<float>(relativeSpeed, -1, 1);
	auto elevationChange = relativeSpeed * maxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto rawNewElevation = RelativeRotation.Pitch + elevationChange;
	auto elevation = FRotator(FMath::Clamp<float>(rawNewElevation, minElevation, maxElevation),0,0);
	SetRelativeRotation(elevation);
}