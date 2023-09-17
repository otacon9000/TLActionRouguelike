// Fill out your copyright notice in the Description page of Project Settings.


#include "SBasePowerup.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"


ASBasePowerup::ASBasePowerup()
{
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereComp->SetCollisionProfileName("Powerup"); // add profile colliosin in project settings 
	RootComponent = SphereComp;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	// Disable collision, instead we use SphereComp to handle interaction queries
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	MeshComp->SetupAttachment(RootComponent);

	RespawnTime = 10.0f;

	SetReplicates(true);
}

void ASBasePowerup::ShowPowerup()
{
	SetPowerupState(true);
}

void ASBasePowerup::HidePowerup()
{
	SetPowerupState(false);

	GetWorldTimerManager().SetTimer(TimerHandle_RespawnTimer, this, &ASBasePowerup::ShowPowerup, RespawnTime);
}

void ASBasePowerup::SetPowerupState(bool bNewIsActive)
{
	SetActorEnableCollision(bNewIsActive);

	// Set visibility on root and all children
	RootComponent->SetVisibility(bNewIsActive, true);
}



void ASBasePowerup::Interact_Implementation(APawn* InstigatorPawn)
{
	// logic in derived class
}

