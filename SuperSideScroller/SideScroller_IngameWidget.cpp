// Fill out your copyright notice in the Description page of Project Settings.


#include "SideScroller_IngameWidget.h"
#include "GameFramework/PlayerController.h"

void USideScroller_IngameWidget::UpdateCoins(int32 coin)
{
	FString strText;
	strText = FString::Printf(TEXT("Coin : %d"), coin);

	cointext->SetText(FText::FromString(strText));
}