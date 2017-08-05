// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"



void UTankTrack::SetThrottle(float Throttle)
{
	//bool IsFalling = UNavMovementComponent::IsFalling();

	//while ( IsFalling == false)
	{
		//TODO clamp throttle so can't be overriden by player.
		auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
		auto ForceLocation = GetComponentLocation(); //TODO Check if tracks in contact with ground
		auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
		TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
	}
	
}



