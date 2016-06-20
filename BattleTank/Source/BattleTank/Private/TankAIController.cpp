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

auto controlledTank = GetControlledTank();
if (!controlledTank) {
UE_LOG(LogTemp, Warning, TEXT("Control Pawn not found!"));
}
else {
UE_LOG(LogTemp, Warning, TEXT("Tank AI Controller is ready for %s"),*controlledTank->GetName());
}


}

