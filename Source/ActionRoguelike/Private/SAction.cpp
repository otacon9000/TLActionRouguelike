// Fill out your copyright notice in the Description page of Project Settings.


#include "SAction.h"
#include "SActionComponent.h"

void USAction::StartAction_Implementation(AActor* Instigator)
{
	UE_LOG(LogTemp, Log, TEXT("Start action: %s"), *GetNameSafe(this));

	USActionComponent* Comp = GetOwningComponent();

	Comp->ActiveGameplayTags.AppendTags(GrantTags);
}

void USAction::StopAction_Implementation(AActor* Instigator)
{
	UE_LOG(LogTemp, Log, TEXT("Stop action: %s"), *GetNameSafe(this));

	USActionComponent* Comp = GetOwningComponent();

	Comp->ActiveGameplayTags.RemoveTags(GrantTags);
}

UWorld* USAction::GetWorld() const
{
	UActorComponent* Comp = Cast<UActorComponent>(GetOuter());
	if (Comp)
	{
		return Comp->GetWorld();
	}

	return nullptr;
}

USActionComponent* USAction::GetOwningComponent() const
{
	return Cast<USActionComponent>(GetOuter());
}
