// Fill out your copyright notice in the Description page of Project Settings.


#include "SHealthPotion_Powerup.h"
#include "SAttributeComponent.h"
#include "SPlayerState.h"

// Sets default values
ASHealthPotion_Powerup::ASHealthPotion_Powerup()
{
	CreditCost = 50;
}



void ASHealthPotion_Powerup::Interact_Implementation(APawn* InstigatorPawn)
{
	if (!ensure(InstigatorPawn))
	{
		return;
	}

	USAttributeComponent* AttributeComp = USAttributeComponent::GetAttributes(InstigatorPawn);
	// Check if not already at max health
	if (ensure(AttributeComp) && !AttributeComp->IsFullHealth())
	{
		if (ASPlayerState* PS = InstigatorPawn->GetPlayerState<ASPlayerState>())
		{
			// Only activate if healed successfully
			if (PS->RemoveCredits(CreditCost) && AttributeComp->ApplyHealthChange(this, AttributeComp->GetHealthMax()))
			{
				HidePowerup();
			}
		}
		
	}
}

