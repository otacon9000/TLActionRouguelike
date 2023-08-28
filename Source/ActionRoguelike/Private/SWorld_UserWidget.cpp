// Fill out your copyright notice in the Description page of Project Settings.


#include "SWorld_UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "UMG/Public/Blueprint/WidgetLayoutLibrary.h"
#include "Components/SizeBox.h"




void USWorld_UserWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (!IsValid(AttachedActor))
	{
		RemoveFromParent();
		
		return;
	}


	FVector2D ScreenPosition;

	if(UGameplayStatics::ProjectWorldToScreen(GetOwningPlayer(), AttachedActor->GetActorLocation() + HealthbarOffest, ScreenPosition))
	{
		float Scale = UWidgetLayoutLibrary::GetViewportScale(this);

		ScreenPosition /= Scale;

		if(ParentSizeBox)
		{
			ParentSizeBox->SetRenderTranslation(ScreenPosition);
		}

	}
}
