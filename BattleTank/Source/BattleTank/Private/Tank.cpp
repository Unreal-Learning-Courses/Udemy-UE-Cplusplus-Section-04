// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"
#include "Tank.h"




// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// No need to protect points as added at construction
	tankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));

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

/*
UTankBarrel* ATank::meshToBarrel(UStaticMeshComponent * barrelToSet)
{
return Cast<UTankBarrel>(barrelToSet);
}
*/




void ATank::AimAt(FVector hitLocation) {

tankAimingComponent->AimAt(hitLocation, launchSpeed);
//auto ourTankName = GetName();

//UE_LOG(LogTemp, Warning, TEXT("%s is aiming at: %s"),*ourTankName, *hitLocation.ToString());
}

void ATank::SetBarrelReference(UTankBarrel * barrelToSet)
{
	//UTankBarrel* barrel = meshToBarrel(barrelToSet);
	tankAimingComponent->SetBarrelReference(barrelToSet);
}

