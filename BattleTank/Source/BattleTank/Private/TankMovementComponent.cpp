// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetTrackThrottle(Throw);
	RightTrack->SetTrackThrottle(Throw);
}

void UTankMovementComponent::IntendRotateRight(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetTrackThrottle(Throw);
	RightTrack->SetTrackThrottle(-Throw);
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();

	auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);
	IntendMoveForward(ForwardThrow);

	auto RotateThrow = FVector::CrossProduct(TankForward, AIForwardIntention);
	IntendRotateRight(RotateThrow.Z);
}
