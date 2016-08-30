// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank.h"
#include "TankAIController.h"
#include "TankAimingComponent.h"
//#include "Tank.h"
//#include "GameFramework/PlayerController.h"
//#include "TankPlayerController.generated.h"
//#include "TankPlayerController.h"



void ATankAIController::BeginPlay()
{
Super::BeginPlay();

}


/*
ATank * ATankAIController::GetPlayerTank() const
{
	auto playerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	
	return Cast<ATank>(playerTank);
}
*/

/*
ATank* ATankAIController::GetControlledTank() const {

return Cast<ATank>(GetPawn());
}

*/


void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	auto aiTank = GetPawn();
	auto playerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (ensure(playerTank)) {

		// TODO Move towards the player
		MoveToActor(playerTank, acceptanceRadius); // TODO check radius is in cm

		// Aim towards the player
		auto aimComponent = aiTank->FindComponentByClass<UTankAimingComponent>();
		aimComponent->AimAt(playerTank->GetActorLocation());
		

		//GetPawn().reloadTimeInSeconds = 10;
		// Fire if ready
		
		//aimComponent->Fire(); //TODO not firing every frame

		
	}

}

