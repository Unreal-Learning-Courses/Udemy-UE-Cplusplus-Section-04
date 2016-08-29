// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

//ENUM for aiming state

UENUM()
enum class EFiringStatus: uint8
{
	Ready,
	Aiming,
	Reloading
};

//Forward Declaration
class UTankBarrel;
class UTankTurret;

// Holds barrel's properties and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	/// Sets default values for this component's properties
	UTankAimingComponent();

	//void SetBarrelReference(UTankBarrel* barrelToSet);

	//void SetTurretReference(UTankTurret * turretToSet);

	void AimAt(FVector hitLocation);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void Initialize(UTankBarrel * barrelToSet, UTankTurret * turretToSet);

protected:

	UPROPERTY(BlueprintReadOnly, Category = State)
		EFiringStatus firingState = EFiringStatus::Reloading;
	
private:

	//UPROPERTY(BlueprintReadOnly, Category = Setup)
		UTankBarrel* barrel = nullptr;
	//UPROPERTY(BlueprintReadOnly, Category = Setup)
		UTankTurret* turret = nullptr;

	void MoveBarrelTowards(FVector aimDirection);
	void MoveTurretTowards(FVector aimDirection);

	UPROPERTY(EditAnywhere, Category = Firing)
		float launchSpeed = 1000000; // TODO find Sensible starting value.
	
};
