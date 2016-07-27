// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurret.h"




void UTankTurret::Rotate(float direction) {


	//Rotate the turret the right amount this frame
	//UE_LOG(LogTemp, Warning, TEXT("Rotate method availble"));

	auto rotateChange = FMath::Clamp<float>(direction, -1, 1) * maxRotationSpeed * GetWorld()->GetDeltaSeconds();
	auto rotationAmount = RelativeRotation.Yaw + rotateChange;
	auto rotation = FRotator(0, rotationAmount, 0);

	UE_LOG(LogTemp, Warning, TEXT("Rotation: %s"),*rotation.ToString());

	SetRelativeRotation(rotation);
}
