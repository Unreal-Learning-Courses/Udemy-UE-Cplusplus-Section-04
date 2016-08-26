// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"
#include "TankMovementComponent.h"


void UTankMovementComponent::Initialize(UTankTrack * leftTrackToSet, UTankTrack * rightTrackToSet) {

	if (!leftTrackToSet || !rightTrackToSet) { return; }
	leftTrack = leftTrackToSet;
	rightTrack = rightTrackToSet;

}

void UTankMovementComponent::IntendMoveForward(float controlThrow) {

	
	//UE_LOG(LogTemp, Warning, TEXT("Intend move forward throw: %f"), controlThrow);

	leftTrack->SetThrottle(controlThrow);
	rightTrack->SetThrottle(controlThrow);

	// TODO prevent double-speed due to dual control input
}

void UTankMovementComponent::IntendTurnRight(float controlThrow) {


	//UE_LOG(LogTemp, Warning, TEXT("Intend move forward throw: %f"), controlThrow);

	leftTrack->SetThrottle(controlThrow);
	rightTrack->SetThrottle(-controlThrow);

	// TODO prevent double-speed due to dual control input
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	auto tankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto aiForwardIntention = MoveVelocity.GetSafeNormal();

	auto cosThrow = FVector::DotProduct(tankForward, aiForwardIntention);
	auto sinThrow = FVector::CrossProduct(tankForward, aiForwardIntention).Z;

	IntendMoveForward(cosThrow);
	IntendTurnRight(sinThrow);

	//UE_LOG(LogTemp, Warning, TEXT("cosThrow is %f"), cosThrow);
	//UE_LOG(LogTemp, Warning, TEXT("sinThrow is %f"), sinThrow);
}
