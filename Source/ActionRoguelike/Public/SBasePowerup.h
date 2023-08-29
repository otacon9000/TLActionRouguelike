// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SGameplayInterface.h"
#include "SBasePowerup.generated.h"

class USphereComponent;

UCLASS()
class ACTIONROGUELIKE_API ASBasePowerup : public AActor, public ISGameplayInterface
{
	GENERATED_BODY()

public:
	ASBasePowerup();

protected:

	UPROPERTY(EditAnywhere)
	float RespawnTime;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USphereComponent* SphereComp;

	UFUNCTION()
	void ShowPowerup();

	void HidePowerup();

	void SetPowerupState(bool bNewIsActive);


public:
	void Interact_Implementation(APawn* InstigatorPawn) override;

};
