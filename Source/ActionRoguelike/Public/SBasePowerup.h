// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SGameplayInterface.h"
#include "SBasePowerup.generated.h"

class USphereComponent;
class UStaticMehComponent;

UCLASS()
class ACTIONROGUELIKE_API ASBasePowerup : public AActor, public ISGameplayInterface
{
	GENERATED_BODY()

public:
	ASBasePowerup();

protected:

	UPROPERTY(EditAnywhere)
	float RespawnTime;

	FTimerHandle TimerHandle_RespawnTimer;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USphereComponent* SphereComp;
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* MeshComp;

	UFUNCTION()
	void ShowPowerup();

	void HidePowerup();

	void SetPowerupState(bool bNewIsActive);


public:
	void Interact_Implementation(APawn* InstigatorPawn) override;

};
