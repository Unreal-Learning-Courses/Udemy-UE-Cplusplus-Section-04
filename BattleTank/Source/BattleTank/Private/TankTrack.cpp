// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"




void UTankTrack::SetThrottle(float throttle) {

	auto name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s Throttle at %f"), *name, throttle);

	// TODO clamp actual throttle value so player can't over-drive
	auto forceApplied = GetForwardVector()*throttle*trackMaxDrivingForce;
	auto forceLocation = GetComponentLocation();
	auto tankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	tankRoot->AddForceAtLocation(forceApplied, forceLocation);
}
	