// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "SideScroller_IngameWidget.generated.h"

/**
 * 
 */
UCLASS()
class SUPERSIDESCROLLER_API USideScroller_IngameWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* cointext;

	void UpdateCoins(int32 coin);
};
