// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SGameplayInterface.h"
#include "Components/StaticMeshComponent.h"
#include "SItemChest.generated.h"

class UStaticMeshComponent;

UCLASS()
class ACTIONROGUELIKE_API ASItemChest : public AActor, public ISGameplayInterface
{
	GENERATED_BODY()
public:

	ASItemChest();

	UPROPERTY(EditAnywhere)
		float TargetPitch;

	void Interact_Implementation(APawn* InstigatorPawn);


protected:

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* BaseMesh;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		UStaticMeshComponent* LidMesh;

	//Rep Notify
	UPROPERTY(ReplicatedUsing = "OnRep_LidOpened", BlueprintReadOnly)
		bool bLidOpened;

	UFUNCTION()
		void OnRep_LidOpened();

};
