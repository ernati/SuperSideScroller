// Fill out your copyright notice in the Description page of Project Settings.


#include "RestartWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"
#include "SuperSideScroller_Controller.h"

void URestartWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	if (RestartButton != nullptr) {
		RestartButton->OnClicked.AddDynamic(this, &URestartWidget::OnRestartClicked);
	}

	if (MainMenuButton != nullptr) {
		MainMenuButton->OnClicked.AddDynamic(this, &URestartWidget::OnMainMenuButtonClicked);
	}
}

void URestartWidget::OnRestartClicked()
{
	ASuperSideScroller_Controller* PlayerController = Cast<ASuperSideScroller_Controller>(GetOwningPlayer());

	if (PlayerController != nullptr)
	{
		PlayerController->HideRestartWidget();
	}

	UGameplayStatics::OpenLevel(this, FName(*UGameplayStatics::GetCurrentLevelName(this)));
}

void URestartWidget::OnMainMenuButtonClicked()
{

	ASuperSideScroller_Controller* PlayerController = Cast<ASuperSideScroller_Controller>(GetOwningPlayer());

	if (PlayerController != nullptr)
	{
		PlayerController->HideRestartWidget();
	}

	UGameplayStatics::OpenLevel(this, TEXT("Start"));
	//UGameplayStatics::OpenLevel(this, FName(*UGameplayStatics::GetCurrentLevelName(this)));
}