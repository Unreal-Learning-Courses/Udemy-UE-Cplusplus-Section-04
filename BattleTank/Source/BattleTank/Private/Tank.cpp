// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank.h"
//#include "TankBarrel.h"
#include "Tank.h"
//#include "Projectile.h"
//#include "TankAimingComponent.h"
//#include "TankMovementComponent.h"



float ATank::GetHealthPercent() const
{
	return (float)currentHealth/(float)startingHealth;
}

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// No need to protect points as added at construction
	//tankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
	//tankMovementComponent = CreateDefaultSubobject<UTankMovementComponent>(FName("Movement Component"));

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay(); // needed for BP to work

	currentHealth = startingHealth;
	//UE_LOG(LogTemp,Warning,TEXT("f7da5eb6: C++ Tank constructed"))
	//tankAimingComponent = FindComponentByClass<UTankAimingComponent>();
	//barrel = FindComponentByClass<UTankBarrel>();
}

void tick() {


}

/*
// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

*/


/*
void ATank::AimAt(FVector hitLocation) {

if (!ensure(tankAimingComponent)) { return; }
tankAimingComponent->AimAt(hitLocation, launchSpeed);
//auto ourTankName = GetName();

//UE_LOG(LogTemp, Warning, TEXT("%s is aiming at: %s"),*ourTankName, *hitLocation.ToString());
}
*/


/*
void ATank::SetBarrelReference(UTankBarrel * barrelToSet)
{
//UTankBarrel* barrel = meshToBarrel(barrelToSet);
tankAimingComponent->SetBarrelReference(barrelToSet);
barrel = barrelToSet;
}

void ATank::SetTurretReference(UTankTurret * turretToSet) {
tankAimingComponent->SetTurretReference(turretToSet);

}
*/

/*
void ATank::Fire()
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

*/

float ATank::TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser) {
	//const float actualDamange = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	
	//if (!GetOwner()) { return 0; }
	auto currrentTankName = GetName();
	
	int32 damanagePoints = FPlatformMath::RoundToInt(DamageAmount);
	auto damageToApply = FMath::Clamp<int32>(damanagePoints, 0, currentHealth);
	


	if (currentHealth <= 0) {

		//UE_LOG(LogTemp, Warning, TEXT("%s is dead!"), *currrentTankName)
		OnDeath.Broadcast();
	}
	else {
		currentHealth -= damageToApply;
		UE_LOG(LogTemp, Warning, TEXT("%s is receiving %i damage!"), *currrentTankName, damageToApply)
			if (currentHealth <= 0) {

				OnDeath.Broadcast();
			}
	}
	
	return DamageAmount;
}

