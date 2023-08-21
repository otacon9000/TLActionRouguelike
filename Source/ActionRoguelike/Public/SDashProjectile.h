// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SBaseProjectile.h"
#include "SDashProjectile.generated.h"

UCLASS()
class ACTIONROGUELIKE_API ASDashProjectile : public ASBaseProjectile
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASDashProjectile();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Teleport")
	float TeleportDelay; 

	UPROPERTY(EditDefaultsOnly, Category = "Teleport")
	float DetonateDelay;

	FTimerHandle TimerHandle_DelayedDetonate;

	void Explode_Implementation() override;

	void TeleportInstigator();

	virtual void BeginPlay() override;

};
