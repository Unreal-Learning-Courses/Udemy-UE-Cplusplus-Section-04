// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "Tank.h"
#include "TankAIController.h"

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


void ATankAIController::SetPawn(APawn * InPawn)
{
	Super::SetPawn(InPawn);

	if (InPawn) {

		possessedTank = Cast<ATank>(InPawn);
		if (!ensure(possessedTank)) { return; }

		// TDO Subscribe our local method to the tank's death event
		possessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::onPossedTankDeath);

	}

}

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
		if (aimComponent->GetFiringState() == EFiringStatus::Ready) {
			aimComponent->Fire();
			//UE_LOG(LogTemp,Warning,TEXT("AI Tank Ready and Firing!"))
		}


		
	}

}

void ATankAIController::onPossedTankDeath()
{
	UE_LOG(LogTemp, Warning, TEXT("%s Is Dead"), *GetPawn()->GetName())

	possessedTank->DetachFromControllerPendingDestroy();

}


