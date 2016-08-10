// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank.h"
#include "TankBarrel.h"
#include "Tank.h"
#include "Projectile.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"



// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// No need to protect points as added at construction
	tankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
	//tankMovementComponent = CreateDefaultSubobject<UTankMovementComponent>(FName("Movement Component"));

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}


void ATank::AimAt(FVector hitLocation) {

tankAimingComponent->AimAt(hitLocation, launchSpeed);
//auto ourTankName = GetName();

//UE_LOG(LogTemp, Warning, TEXT("%s is aiming at: %s"),*ourTankName, *hitLocation.ToString());
}

void ATank::SetBarrelReference(UTankBarrel * barrelToSet)
{
	//UTankBarrel* barrel = meshToBarrel(barrelToSet);
	tankAimingComponent->SetBarrelReference(barrelToSet);
	barrel = barrelToSet;
}

void ATank::SetTurretReference(UTankTurret * turretToSet) {
	tankAimingComponent->SetTurretReference(turretToSet);

}

void ATank::Fire()
{
	//UE_LOG(LogTemp, Warning, TEXT("Firing!"));
	bool isReloaded = (FPlatformTime::Seconds() - lastFireTime) > reloadTimeInSeconds;
	if (barrel && isReloaded) { 

		// Spawn a projectile at the socket location
		auto projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, barrel->GetSocketLocation(FName("canonTip")), barrel->GetSocketRotation(FName("canonTip")));

		projectile->LaunchProjectile(launchSpeed);
		lastFireTime = FPlatformTime::Seconds();
	}
}

