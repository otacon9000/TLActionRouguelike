// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/SAICharacter.h"
#include "AIModule/Classes/Perception/PawnSensingComponent.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "DrawDebugHelpers.h"
#include "SAttributeComponent.h"
#include "BrainComponent.h"
#include "SWorld_UserWidget.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "SActionComponent.h"

// Sets default values
ASAICharacter::ASAICharacter()
{
	AttributeComp = CreateDefaultSubobject<USAttributeComponent>(TEXT("AttributeComp"));

	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));

	ActionComp = CreateDefaultSubobject<USActionComponent>(TEXT("ActionComp"));

	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Ignore);
	GetMesh()->SetGenerateOverlapEvents(true);

	TimeToHitParamName = "TimeToHit";
	TargetActorKey = "TargetActor";
}


void ASAICharacter::OnHealthChanged(AActor* InstigatorActor, USAttributeComponent* OwningComp, float NewHealth, float Delta)
{
	if (Delta < 0)
	{

		if (InstigatorActor != this)
		{
			SetTargetActor(InstigatorActor);
		}

		if (ActiveHealthBar == nullptr)
		{

			ActiveHealthBar = CreateWidget<USWorld_UserWidget>(GetWorld(), HealthBarWidgetClass);
			if (ActiveHealthBar)
			{
				ActiveHealthBar->AttachedActor = this;
				ActiveHealthBar->AddToViewport();
			}

		}

		GetMesh()->SetScalarParameterValueOnMaterials(TimeToHitParamName, GetWorld()->TimeSeconds);

		//died
		if(NewHealth <= 0.0f) 
		{
			AAIController* AIC = Cast<AAIController>(GetController());
			if(AIC)
			{
				AIC->GetBrainComponent()->StopLogic("Killed");

			}

			//ragdoll
			GetMesh()->SetAllBodiesSimulatePhysics(true);
			GetMesh()->SetCollisionProfileName("Ragdoll");

			GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
			GetCharacterMovement()->DisableMovement();

			//lifespan
			SetLifeSpan(10.0f);
		}
	}
}

void ASAICharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	PawnSensingComp->OnSeePawn.AddDynamic(this, &ASAICharacter::OnPawnSeen);
	AttributeComp->OnHealthChanged.AddDynamic(this, &ASAICharacter::OnHealthChanged);
}


void ASAICharacter::SetTargetActor(AActor* NewTarget)
{
	AAIController* AIC = Cast<AAIController>(GetController());
	if (AIC)
	{
		AIC->GetBlackboardComponent()->SetValueAsObject("TargetActor", NewTarget);
	}

}

AActor* ASAICharacter::GetTargetActor() const
{
	AAIController* AIC = Cast<AAIController>(GetController());
	if (AIC)
	{
		return Cast<AActor>(AIC->GetBlackboardComponent()->GetValueAsObject(TargetActorKey));
	}

	return nullptr;
}

void ASAICharacter::OnPawnSeen(APawn* Pawn)
{
	// Ignore if target already set
	if (GetTargetActor() != Pawn)
	{
		SetTargetActor(Pawn);

		USWorld_UserWidget* NewWidget = CreateWidget<USWorld_UserWidget>(GetWorld(), SpottedWidgetClass);
		if (NewWidget)
		{
			NewWidget->AttachedActor = this;
			// Index of 10 (or anything higher than default of 0) places this on top of any other widget.
			// May end up behind the minion health bar otherwise.
			NewWidget->AddToViewport(10);
		}
	}
	//DrawDebugString(GetWorld(), GetActorLocation(), "PLAYER SPOTTED", nullptr, FColor::White, 0.5f, true);
}