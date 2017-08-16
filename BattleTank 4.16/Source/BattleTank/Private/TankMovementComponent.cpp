// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"


/// Intended movement behavior: Movement is relative to cursor location. Forward = towards cursor.
/// Rotates toward movement direction then accelerates.

void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!ensure(LeftTrack && RightTrack)) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
	// TODO Prevent double speed from double input
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!ensure(LeftTrack && RightTrack)) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	// No need to call Super as we're replacing the functionality

	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();
	auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);


	IntendMoveForward(ForwardThrow);

	auto RightThrow = FVector::CrossProduct(TankForward, AIForwardIntention);

	IntendTurnRight(RightThrow.Z);

	//auto MoveVelocityString = MoveVelocity.GetSafeNormal().ToString();
	//UE_LOG(LogTemp, Warning, TEXT("Vectoring to %s"), *MoveVelocityString)

	///TODO Add instruction so that if tank is not on navmesh, that it generates a movevelocity towards 0,0,0

}
