// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SWorld_UserWidget.generated.h"


class USizeBox;
/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API USWorld_UserWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(meta = (BindWidget))
	USizeBox* ParentSizeBox;

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime);


public:

	UPROPERTY(EditAnywhere, Category = "UI")
	FVector HealthbarOffest;

	UPROPERTY(BlueprintReadOnly, Category = "UI")
	AActor* AttachedActor;
};
