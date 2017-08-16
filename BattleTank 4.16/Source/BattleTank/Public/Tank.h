// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


///TODO Introduce some self-righting of the tank, either by Mass/collision mesh and physics tweaks in BP, 
///or through some code mechanic moves the tank after a countdown if it detects that it has flipped.

#include "GameFramework/Pawn.h"
#include "Tank.generated.h" //new classes above

// forward declarations
class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable)
	void Fire();

protected:

	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;
	
private:

	virtual void BeginPlay() override;

	//Local reference for spawning projectiles TODO remove
	UTankBarrel* Barrel = nullptr;

	// Sets default values for this pawn's properties
	ATank();

	UPROPERTY(EditAnywhere, Category = "Firing")
	float LaunchSpeed = 8000; //Sensible starting value of 1000 m/s TODO Verify sensibility

	UPROPERTY(EditAnywhere, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	float ReloadTimeInSeconds = 3;

	double LastFireTime = 0;

};
