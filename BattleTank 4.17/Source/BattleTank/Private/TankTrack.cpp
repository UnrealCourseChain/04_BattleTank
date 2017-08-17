// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"

//TODO BUG Disable track movement while not in contact with ground.
//TODO BUG Remove sidewards sliding from movement

void UTankTrack::SetThrottle(float Throttle)
{
	{

		//TODO clamp throttle so can't be overriden by player.
	
		auto ForceLocation = GetSocketLocation(FName("ForceLocation"));
		auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
		auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
		TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
	}
	
}



