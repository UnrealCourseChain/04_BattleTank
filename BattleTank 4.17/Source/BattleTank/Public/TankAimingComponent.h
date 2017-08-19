// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;
class UTankTurret;
class AProjectile;

//Enum for aiming state
UENUM()
enum class EFiringState :uint8 
{
	Reloading,
	Aiming,
	Locked,
	OutOfAmmo
};

//Holds barrel's properties and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

	void AimAt(FVector HitLocation);

	//Template for retriving private variable from another class
	//Keep in mind for TODOs & AimDirection
	//Currently Used in AI Controller
	EFiringState GetFiringState() const;

	UFUNCTION(BlueprintCallable, Category = "Firing")
	int GetRoundsLeft() const;

protected:

	UPROPERTY(BlueprintReadOnly, Category = "Status")
	EFiringState FiringState = EFiringState::Aiming;

private:
	// Sets default values for this component's properties
	UTankAimingComponent();

	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	void MoveBarrelTowards();

	bool IsBarrelMoving();

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;
	
	UPROPERTY(EditAnywhere, Category = "Firing")
	float LaunchSpeed = 8000; //Sensible starting value

	UPROPERTY(EditAnywhere, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditAnywhere, Category = "Firing")
	float ReloadTimeInSeconds = 3;

	double LastFireTime = 0;

	FVector AimDirection;

	int RoundsLeft = 3;
};
