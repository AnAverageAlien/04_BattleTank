// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	// Move the barrel the correct amount this frame,
	// Given a max elevation speed and the frame time
	auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f Elevate method called at %f"), Time, RelativeSpeed)
}


