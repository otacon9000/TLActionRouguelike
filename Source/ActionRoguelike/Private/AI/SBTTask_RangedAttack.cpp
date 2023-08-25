// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/SBTTask_RangedAttack.h"
#include "AIModule/Classes/AIController.h"
#include "GameFramework/Character.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "SAttributeComponent.h"



USBTTask_RangedAttack::USBTTask_RangedAttack()
{
	BulletSpread = 2.0f;
}


EBTNodeResult::Type USBTTask_RangedAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* MyController = OwnerComp.GetAIOwner();
	if (ensure(MyController))
	{

		ACharacter* MyPawn = Cast<ACharacter>(MyController->GetPawn());
		if (MyPawn == nullptr)
		{
			return EBTNodeResult::Failed;
		}

		FVector MuzzleLocation = MyPawn->GetMesh()->GetSocketLocation("Muzzle_01");

		AActor* TargetActor = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValueAsObject("TargetActor"));
		if (TargetActor == nullptr)
		{
			return EBTNodeResult::Failed;
		}

		if (!USAttributeComponent::IsActorLive(TargetActor))
		{
			return EBTNodeResult::Failed;
		}

		FVector Direction = TargetActor->GetActorLocation() - MuzzleLocation; 
		FRotator MuzzleRotation = Direction.Rotation();

		MuzzleRotation.Pitch += FMath::RandRange(0.0f, BulletSpread);
		MuzzleRotation.Yaw += FMath::RandRange(-BulletSpread, BulletSpread);

		FActorSpawnParameters Params; 
		Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		Params.Instigator = MyPawn;

		AActor* NewProjectile = GetWorld()->SpawnActor <AActor>(ProjectileClass, MuzzleLocation, MuzzleRotation, Params);

		return NewProjectile ? EBTNodeResult::Succeeded : EBTNodeResult::Failed;
	}

	return EBTNodeResult::Failed;
}
