// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "SBTService_AttackRange.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API USBTService_AttackRange : public UBTService
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, Category = "AI")
	FBlackboardKeySelector AttackRangeKey;

	/* Max desired attack range of AI pawn */
	UPROPERTY(EditAnywhere, Category = "AI")
	float MaxAttackRange;

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

public:
	USBTService_AttackRange();
};

