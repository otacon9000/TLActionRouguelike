// Fill out your copyright notice in the Description page of Project Settings.


#include "SBasePowerup.h"
#include "Components/SphereComponent.h"


ASBasePowerup::ASBasePowerup()
{
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereComp->SetCollisionProfileName("Powerup"); // add profile colliosin in project settings 
	RootComponent = SphereComp;

	RespawnTime = 10.0f;
}

void ASBasePowerup::ShowPowerup()
{
	SetPowerupState(true);
}

void ASBasePowerup::HidePowerup()
{
	SetPowerupState(false);

	FTimerHandle TimerHandle_Respawn;
	GetWorldTimerManager().SetTimer(TimerHandle_Respawn, this, &ASBasePowerup::ShowPowerup, RespawnTime);
}

void ASBasePowerup::SetPowerupState(bool bNewIsActive)
{
	SetActorEnableCollision(bNewIsActive);

	// Set visibility on root and all children
	RootComponent->SetVisibility(bNewIsActive, true);
}



void ASBasePowerup::Interact_Implementation(APawn* InstigatorPawn)
{
	
}

