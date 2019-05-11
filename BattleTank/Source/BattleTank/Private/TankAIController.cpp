// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "GameFramework/Actor.h"

APawn* ATankAIController::GetPossessedAITank() const
{
	return GetPawn();
}

ATank* ATankAIController::GetPlayerController() const
{
	if (!GetWorld()->GetFirstPlayerController()->GetPawn()) { return nullptr; }
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("TankAIController possessed: %s"), *GetPossessedAITank()->GetName())

	ATank* PlayerController = GetPlayerController();

	if (!PlayerController)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController isn't returning anything"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("The player controller is %s"), *PlayerController->GetName())
	}
}
