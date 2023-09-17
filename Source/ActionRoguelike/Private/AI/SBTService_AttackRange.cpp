// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/SBTService_AttackRange.h"
#include "AIModule/Classes/BehaviorTree/BlackboardComponent.h"
#include "AIModule/Classes/AIController.h"



USBTService_AttackRange::USBTService_AttackRange()
{
	MaxAttackRange = 2000.0f;
}


void USBTService_AttackRange::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (ensure(BlackboardComp))
	{
		AActor* TargetActor = Cast<AActor>(BlackboardComp->GetValueAsObject("TargetActor"));
		if (TargetActor)
		{
			AAIController* MyController = OwnerComp.GetAIOwner();

			APawn* AIPawn = MyController->GetPawn();
			if (ensure(AIPawn))
			{
				float DistanceTo = FVector::Distance(TargetActor->GetActorLocation(), AIPawn->GetActorLocation());

				bool bWithinRange = DistanceTo < MaxAttackRange;

				bool bHasLOS = false;
				if (bWithinRange)
				{
					bHasLOS = MyController->LineOfSightTo(TargetActor);
				}

				BlackboardComp->SetValueAsBool(AttackRangeKey.SelectedKeyName, (bWithinRange && bHasLOS));
			}
		}
	}
}
