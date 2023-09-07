// Fill out your copyright notice in the Description page of Project Settings.


#include "SCredits_Powerup.h"
#include "SPlayerState.h"


ASCredits_Powerup::ASCredits_Powerup()
{
	CreditsAmount = 80;
}

void ASCredits_Powerup::Interact_Implementation(APawn* InstigatorPawn)
{
	if(!ensure(InstigatorPawn))
	{
		return;
	}

	if(ASPlayerState* PS = InstigatorPawn->GetPlayerState<ASPlayerState>())
	{

		PS->AddCredits(CreditsAmount);
		HidePowerup();
	}
}
