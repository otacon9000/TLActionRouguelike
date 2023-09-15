// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "SAction.generated.h"

class UWorld;
class USActionComponent;
/**
 * 
 */
UCLASS(Blueprintable)
class ACTIONROGUELIKE_API USAction : public UObject
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditDefaultsOnly, Category = "Actions")
	bool bAutoStart;

	UPROPERTY(EditDefaultsOnly, Category = "Actions")
	FName ActionName; 

	UFUNCTION(BlueprintNativeEvent, Category = "Actions")
	bool CanStart(AActor* Instigator);

	UFUNCTION(BlueprintNativeEvent, Category = "Actions")
	void StartAction(AActor* Instigator);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Actions")
	void StopAction(AActor* Instigator);

	UFUNCTION(BlueprintCallable, Category = "Actions")
	bool IsRunning() const;

	UWorld* GetWorld() const override;

protected:

	bool bIsRunning;

	UPROPERTY(EditDefaultsOnly, Category = "Tags")
	FGameplayTagContainer GrantTags;

	UPROPERTY(EditDefaultsOnly, Category = "Tags")
	FGameplayTagContainer BlockedTags;

	UFUNCTION(BlueprintCallable, Category = "Actions")
	USActionComponent* GetOwningComponent() const;

};
