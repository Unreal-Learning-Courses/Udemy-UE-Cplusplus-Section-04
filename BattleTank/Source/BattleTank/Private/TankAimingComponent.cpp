// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.

	// ...
}

void UTankAimingComponent::Initialize(UTankBarrel* barrelToSet, UTankTurret *turretToSet) {
	if (!ensure(barrelToSet && turretToSet)) { return; }
	barrel = barrelToSet;
	turret = turretToSet;

}

void UTankAimingComponent::AimAt(FVector hitLocation) {

	auto ourTankName = GetOwner()->GetName();
	//FVector barrelLocation = barrel->GetComponentLocation();
	if (!ensure(barrel)) { 
		UE_LOG(LogTemp, Warning, TEXT("barrel not found"));
		return; 
	}

	if (!ensure(turret)) { 
		UE_LOG(LogTemp, Warning, TEXT("turret not found"));
		return; 
	}
	FVector OUTlaunchVelocity;
	FVector startLocation = barrel->GetSocketLocation(FName("canonTip"));
	
	// Calculate the OUTlaunchVelocity
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(this, OUTlaunchVelocity, startLocation, hitLocation, launchSpeed, false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace);

	if (ensure(bHaveAimSolution)) {
		auto aimDirection = OUTlaunchVelocity.GetSafeNormal();

		//UE_LOG(LogTemp, Warning, TEXT("%s is aiming at %s"),*ourTankName, *aimDirection.ToString());
		MoveBarrelTowards(aimDirection);
		MoveTurretTowards(aimDirection);
		auto time = GetWorld()->GetTimeSeconds();
		//UE_LOG(LogTemp, Warning, TEXT("%f: Aim solution found"), time);

	}
	else {
		
		auto time = GetWorld()->GetTimeSeconds();
		//UE_LOG(LogTemp, Warning, TEXT("%f: No aim solve found"), time);

	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector aimDirection)
{
	// Work-out difference between current barrel rotation and aimDirection
	FRotator barrelRotator = barrel->GetForwardVector().Rotation();
	FRotator aimAsRotator = aimDirection.Rotation();
	FRotator deltaRotator = aimAsRotator - barrelRotator;

	//UE_LOG(LogTemp, Warning, TEXT("deltaRotator is %f"), deltaRotator.Pitch);

	barrel->Elevate(deltaRotator.Pitch); //TODO remove magic number
}

void UTankAimingComponent::MoveTurretTowards(FVector aimDirection)
{
	FRotator turretRotator = turret->GetForwardVector().Rotation();
	FRotator aimAsRotator = aimDirection.Rotation();
	FRotator deltaRotator = aimAsRotator - turretRotator;

	//UE_LOG(LogTemp, Warning, TEXT("deltaRotator is %f"), deltaRotator.Yaw);
	turret->Rotate(deltaRotator.Yaw);
}

/*
void UTankAimingComponent::SetBarrelReference(UTankBarrel* barrelToSet)
{
barrel = barrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTankTurret* turretToSet) {

turret = turretToSet;
}
*/

void UTankAimingComponent::Fire()
{
	//UE_LOG(LogTemp, Warning, TEXT("Firing!"));
	bool isReloaded = (FPlatformTime::Seconds() - lastFireTime) > reloadTimeInSeconds;
	if (ensure(barrel) && isReloaded) {

		// Spawn a projectile at the socket location
		auto projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, barrel->GetSocketLocation(FName("canonTip")), barrel->GetSocketRotation(FName("canonTip")));

		projectile->LaunchProjectile(launchSpeed);
		lastFireTime = FPlatformTime::Seconds();
	}
}