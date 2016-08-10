// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Projectile.h"


// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	projectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Movement Component"));
	projectileMovement->bAutoActivate = false;
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectile::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AProjectile::LaunchProjectile(float launchSpeed)
{
	//UE_LOG(LogTemp, Warning, TEXT("Projectile Launched!"));

	projectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector * launchSpeed);
	projectileMovement->Activate();
}

