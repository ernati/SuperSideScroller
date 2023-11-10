// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SuperSideScroller_Controller.generated.h"

/**
 * 
 */
UCLASS()
class SUPERSIDESCROLLER_API ASuperSideScroller_Controller : public APlayerController
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class USideScroller_IngameWidget> BP_IngameWidget;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class URestartWidget> BP_RestartWidget;

	void ShowRestartWidget();
	void HideRestartWidget();
	void UpdateCoin( int32 coin );

private:
	UPROPERTY()
		class USideScroller_IngameWidget* SideScroller_IngameWidget;

	UPROPERTY()
		class URestartWidget* RestartWidget;

protected:
	virtual void BeginPlay() override;

};
