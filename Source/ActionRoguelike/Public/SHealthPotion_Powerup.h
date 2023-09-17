// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SBasePowerup.h"
#include "SHealthPotion_Powerup.generated.h"

UCLASS()
class ACTIONROGUELIKE_API ASHealthPotion_Powerup : public ASBasePowerup
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASHealthPotion_Powerup();

protected:

	UPROPERTY(EditAnywhere, Category = "HealthPotion")
	int32 CreditCost;


public:
	void Interact_Implementation(APawn* InstigatorPawn) override;


};
