// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SBasePowerup.h"
#include "SCredits_Powerup.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API ASCredits_Powerup : public ASBasePowerup
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere, Category = "Credits")
	int32 CreditsAmount; 
public:
	void Interact_Implementation(APawn* InstigatorPawn) override;


	ASCredits_Powerup();
};
