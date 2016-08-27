// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank.h"
#include "TankPlayerController.h"
#include "TankAimingComponent.h"
#include "Tank.h"

ATank* ATankPlayerController::GetControlledTank() const {
	

	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	auto controlledTank = GetControlledTank();
	if (!ensure(controlledTank)) {
		UE_LOG(LogTemp, Warning, TEXT("Control Pawn not found!"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("%s has control!"),*controlledTank->GetName());
	}

	auto aimingComponent = GetControlledTank()->FindComponentByClass<UTankAimingComponent>();
	if (ensure(aimingComponent)) {
		FoundAimingComponent(aimingComponent);
	}
	else {

		UE_LOG(LogTemp, Warning, TEXT("No Aiming Component Found!"))
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
	
	if (!ensure(GetControlledTank())) { return; }

	FVector hitLocation; // Out parameter
	
	// Get world location if linetrace through crosshair
	if (ensure(GetSightRayHitLocation(hitLocation))) {
		// If it hits the landscape
		//UE_LOG(LogTemp, Warning, TEXT("hitLocation: %s"), *hitLocation.ToString());
		GetControlledTank()->AimAt(hitLocation);
	}


		//Tell controlled tank to aim at this point
	
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& hitLocation) const {
	
	/// Find the crosshair position
	int32 viewportSizeX, viewportSizeY;
	GetViewportSize(viewportSizeX, viewportSizeY);
	FVector2D screenLocation = FVector2D(viewportSizeX*crossHairXLocation, viewportSizeY*crossHairYLocation);
	//UE_LOG(LogTemp, Warning, TEXT("screenLocation: %s"), *screenLocation.ToString());

	FVector lookDirection;

	if (ensure(GetLookDirection(screenLocation,lookDirection))) {

		//UE_LOG(LogTemp, Warning, TEXT("Look direction:: %s"), *lookDirection.ToString());

		// Line-trace along that look direction, and see what we hit (up to max range)
		if (ensure(GetLookVectorHitLocation(hitLocation, lookDirection))) {
			return true;
		}
	}
	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D screenLocation, FVector& lookDirection) const {



	/// "De-project" the screen position of the crosshair to a world direction
	FVector cameraLocation;
	if (ensure(DeprojectScreenPositionToWorld(screenLocation.X, screenLocation.Y, cameraLocation, lookDirection))) {

		return true;
	}
	return false;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector& hitLocation, FVector& lookDirection) const{

	/// Line-trace out to reach distance
	auto startLocation = PlayerCameraManager->GetCameraLocation();
	FHitResult hitResult;
	FVector reachEnd = startLocation + lookDirection*reach;


	if (ensure(GetWorld()->LineTraceSingleByChannel(hitResult, startLocation, reachEnd, ECollisionChannel::ECC_Visibility))) {
		hitLocation = hitResult.ImpactPoint;
		//UE_LOG(LogTemp, Warning, TEXT("hitResult: %s"), *hitLocation.ToString());
		return true;
	}
	hitLocation = FVector(0);
	return false;
}