// Fill out your copyright notice in the Description page of Project Settings.


#include "SHealthPotion_Powerup.h"
#include "SAttributeComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ASHealthPotion_Powerup::ASHealthPotion_Powerup()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	MeshComp->SetupAttachment(RootComponent);

}



void ASHealthPotion_Powerup::Interact_Implementation(APawn* InstigatorPawn)
{
	if (!ensure(InstigatorPawn))
	{
		return;
	}

	USAttributeComponent* AttributeComp = Cast<USAttributeComponent>(InstigatorPawn->GetComponentByClass(USAttributeComponent::StaticClass()));
	// Check if not already at max health
	if (ensure(AttributeComp) && !AttributeComp->IsFullHealth())
	{
		// Only activate if healed successfully
		if (AttributeComp->ApplyHealthChange(this, AttributeComp->GetHealthMax()))
		{
			HidePowerup();
		}
	}
}

