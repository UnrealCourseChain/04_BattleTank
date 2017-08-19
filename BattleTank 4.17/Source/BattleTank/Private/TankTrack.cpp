// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"

//TODO BUG Disable track movement while not in contact with ground.
//TODO BUG Remove sidewards sliding from movement

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankTrack::BeginPlay()
{
	OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);
}

void UTankTrack::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	//Super::TickComponent();
	

	//calculate the slippage speed
	auto SlipSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	//work-out the requried acceleration this frame to correct
	auto CorrectionAcceleration = -SlipSpeed / DeltaTime * GetRightVector();
		//Calculate and apply sideways for F = m a
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = TankRoot->GetMass() *CorrectionAcceleration / 2;
	TankRoot->AddForce(CorrectionForce);
}

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

void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("On Hit"))
}
