// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:
	
	void BeginPlay() override;

	void Tick(float DeltaTime) override;

protected:
	// How close the AI can get to the player in centimeters
	UPROPERTY(EditAnywhere, Category = "Setup")
	float AcceptanceRadius = 8000;

private:

};