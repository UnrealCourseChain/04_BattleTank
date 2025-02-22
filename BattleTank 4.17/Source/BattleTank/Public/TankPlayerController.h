// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UTankAimingComponent;

/**
 *  Responsible for helping the player aim
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:

	UFUNCTION(BlueprintImplementableEvent, Category = "setup")
	void FoundAimingComponent(UTankAimingComponent* AimCompRef);

private:

	virtual void BeginPlay() override;

	virtual void SetPawn(APawn* InPawn) override;

	virtual void Tick(float DeltaTime) override;

	//Start moving the tank barrel such that the shot hits at intersection of crosshair & world
	void AimTowardsCrosshair();

	// Return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = 0.5;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 0.3333;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000.0;

	UFUNCTION()
	void OnPossessedTankDeath();
	
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;


};
