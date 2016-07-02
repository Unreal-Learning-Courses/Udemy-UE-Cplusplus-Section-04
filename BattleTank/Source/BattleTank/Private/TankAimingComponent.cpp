// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.

	// ...
}

void UTankAimingComponent::AimAt(FVector hitLocation,float launchSpeed) {

	auto ourTankName = GetOwner()->GetName();
	//FVector barrelLocation = barrel->GetComponentLocation();
	if (!barrel) { return; }

	FVector OUTlaunchVelocity;
	FVector startLocation = barrel->GetSocketLocation(FName("canonTip"));
	
	// Calculate the OUTlaunchVelocity

	if (UGameplayStatics::SuggestProjectileVelocity(this, OUTlaunchVelocity, startLocation, hitLocation, launchSpeed,false,0,0,ESuggestProjVelocityTraceOption::DoNotTrace)) {
		auto aimDirection = OUTlaunchVelocity.GetSafeNormal();

		//UE_LOG(LogTemp, Warning, TEXT("%s is aiming at %s"),*ourTankName, *aimDirection.ToString());
		MoveBarrelTowards(aimDirection);

	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector aimDirection)
{
	// Work-out difference between current barrel rotation and aimDirection
	FRotator barrelRotator = barrel->GetForwardVector().Rotation();
	FRotator aimAsRotator = aimDirection.Rotation();
	FRotator deltaRotator = aimAsRotator - barrelRotator;

	UE_LOG(LogTemp, Warning, TEXT("aimRotator is %s"), *aimAsRotator.ToString());
	// Move the barrel the right amount this frame

	// Given a max elevation speed and the frame time
}

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent* barrelToSet)
{
	barrel = barrelToSet;
}