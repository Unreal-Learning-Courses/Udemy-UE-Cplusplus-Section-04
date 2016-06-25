// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"
//#include "GameFramework/PlayerController.h"
//#include "TankPlayerController.generated.h"
//#include "TankPlayerController.h"


ATank* ATankAIController::GetControlledTank() const {

return Cast<ATank>(GetPawn());
}


void ATankAIController::BeginPlay()
{
Super::BeginPlay();

//auto controlledTank = GetControlledTank();
auto playerTank = GetPlayerTank();
if (!playerTank) {
UE_LOG(LogTemp, Warning, TEXT("Player Tank not found!"));
}
else {
UE_LOG(LogTemp, Warning, TEXT("Player Controller %s found!"),*playerTank->GetName());
}


}

ATank * ATankAIController::GetPlayerTank() const
{
	auto playerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	
	return Cast<ATank>(playerTank);
}
