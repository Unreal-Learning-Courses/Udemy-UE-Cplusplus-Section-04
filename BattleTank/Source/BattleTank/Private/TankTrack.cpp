// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"

UTankTrack::UTankTrack() {
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankTrack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)
{

	// Calculate the slippage speed
	//FVector OUTdirection;
	//float OUTspeed;
	auto slippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	//GetOwner()->GetVelocity().ToDirectionAndLength(OUTdirection, OUTspeed);
	//UE_LOG(LogTemp,Warning, TEXT("direction is %s, speed is %f"),*OUTdirection.ToString(),OUTspeed)
	//UE_LOG(LogTemp, Warning, TEXT("slippage speed is %f"), slippageSpeed)

	// Work-out the required acceleration this frame to correct
	
	auto correctionAcceleration = -(slippageSpeed / DeltaTime * GetRightVector());
	
	// Calculate and apply sidways (F = ma)
	auto tankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto correctionForce = (tankRoot->GetMass() * correctionAcceleration)/2; //Two Tracks
	tankRoot->AddForce(correctionForce);

}

void UTankTrack::SetThrottle(float throttle) {

	// TODO clamp actual throttle value so player can't over-drive
	auto forceApplied = GetForwardVector()*throttle*trackMaxDrivingForce;
	auto forceLocation = GetComponentLocation();
	auto tankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	tankRoot->AddForceAtLocation(forceApplied, forceLocation);
}
	