// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SAction.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class ACTIONROGUELIKE_API USAction : public UObject
{
	GENERATED_BODY()
	

public:

	UPROPERTY(EditDefaultsOnly, Category = "Actions")
	FName ActionName; 

	UFUNCTION(BlueprintNativeEvent, Category = "Actions")
	void StartAction(AActor* Instigator);

	UFUNCTION(BlueprintNativeEvent, Category = "Actions")
	void StopAction(AActor* Instigator);

	UWorld* GetWorld() const override;
};
