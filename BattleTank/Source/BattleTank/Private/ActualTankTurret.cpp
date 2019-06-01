// Fill out your copyright notice in the Description page of Project Settings.

#include "ActualTankTurret.h"
#include "Engine/World.h"

void UActualTankTurret::RotateTurret(float RelativeTurretRotation)
{
	auto ClampedRelativeRotation = FMath::Clamp<float>(RelativeTurretRotation, -1.f, 1.f);
	auto RotationChange = ClampedRelativeRotation * MaxRotationSpeedDegrees * GetWorld()->DeltaTimeSeconds;
	auto NewTurretRotation = RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator(0, NewTurretRotation, 0));
}


