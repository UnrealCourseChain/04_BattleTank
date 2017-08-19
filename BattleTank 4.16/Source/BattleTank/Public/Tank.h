// Fill out your copyright notice in the Description page of Project Settings.


#pragma once


///TODO Introduce some self-righting of the tank, either by Mass/collision mesh and physics tweaks in BP, 
///or through some code mechanic moves the tank after a countdown if it detects that it has flipped.

#include "GameFramework/Pawn.h"
#include "Tank.generated.h" //new classes above


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
		
private:

	ATank();

};
