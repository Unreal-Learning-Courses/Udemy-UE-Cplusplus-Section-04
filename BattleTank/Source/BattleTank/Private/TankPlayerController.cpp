// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"


ATank* ATankPlayerController::GetControlledTank() const {
	

	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	auto controlledTank = GetControlledTank();
	if (!controlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("Control Pawn not found!"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("%s has control!"),*controlledTank->GetName());
	}

	//void Tick();
	
}

// Tick
void ATankPlayerController::Tick(float DeltaTime){

	// Super
	Super::Tick(DeltaTime);

	//UE_LOG(LogTemp, Warning, TEXT("Ticking"));

	AimTowardsCrosshair();

}

void ATankPlayerController::AimTowardsCrosshair() {
	
	if (!GetControlledTank()) { return; }

	FVector hitLocation; // Out parameter
	
	// Get world location if linetrace through crosshair
	if (GetSightRayHitLocation(hitLocation)) {
		// If it hits the landscape
		UE_LOG(LogTemp, Warning, TEXT("hitLocation: %s"), *hitLocation.ToString());
	}


		//Tell controlled tank to aim at this point
	
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& hitLocation) const {
	//GetWorld()->LineTraceSingle();
	hitLocation = FVector(1.0);
	if(!&hitLocation) {
		return false;
	}
	else {
		return true;
	}
}