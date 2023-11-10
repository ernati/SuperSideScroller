// Fill out your copyright notice in the Description page of Project Settings.


#include "SuperSideScroller_Controller.h"
#include "SideScroller_IngameWidget.h"
#include "RestartWidget.h"

void ASuperSideScroller_Controller::BeginPlay()
{
	Super::BeginPlay();

	SetPause(false);

	SetInputMode(FInputModeGameOnly());
	bShowMouseCursor = false;

	if (BP_IngameWidget != nullptr)
	{
		SideScroller_IngameWidget = CreateWidget<USideScroller_IngameWidget>(this, BP_IngameWidget);
		SideScroller_IngameWidget->AddToViewport();
		UpdateCoin(0);
	}
}


void ASuperSideScroller_Controller::ShowRestartWidget()
{
	if (BP_RestartWidget != nullptr)
	{
		SetPause(true);

		SetInputMode(FInputModeUIOnly());
		bShowMouseCursor = true;

		RestartWidget = CreateWidget<URestartWidget>(this, BP_RestartWidget);
		RestartWidget->AddToViewport();
	}
}


void ASuperSideScroller_Controller::HideRestartWidget()
{
	RestartWidget->RemoveFromParent();
	RestartWidget->Destruct();

	SetPause(false);

	SetInputMode(FInputModeGameOnly());
	bShowMouseCursor = false;
}

void ASuperSideScroller_Controller::UpdateCoin(int32 coin)
{
	if (SideScroller_IngameWidget != nullptr)
	{
		SideScroller_IngameWidget->UpdateCoins(coin);
	}
}