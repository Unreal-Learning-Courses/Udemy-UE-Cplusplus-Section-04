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

	// AimTowardsCrosshair();

}

void ATankPlayerController::AimTowardsCrosshair() {
	
	if (!GetControlledTank()) { return; }

	// Get world location if linetrace through crosshair

	// If it hits the landscape
		
		//Tell controlled tank to aim at this point
	
}