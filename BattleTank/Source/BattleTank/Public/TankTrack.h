// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * Tank Track is used to apply driving forces to the tank via its tracks.
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetTrackThrottle(float Throttle);
	
	//The force in Newtons applied to a single track
	UPROPERTY(EditDefaultsOnly)
		float TrackMaxDrivingForce = 400000;

protected:
	virtual void OnRegister() override;

private:
	virtual void BeginPlay() override;

	UTankTrack();

	void ApplySidewaysForce();

	UFUNCTION()
	void OnHit(UPrimitiveComponent *HitComponent, AActor *OtherActor, UPrimitiveComponent *OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	void DriveTrack();

	float CurrentThrottle = 0;
};