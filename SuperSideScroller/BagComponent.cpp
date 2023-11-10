// Fill out your copyright notice in the Description page of Project Settings.


#include "BagComponent.h"
#include "GameFramework/Actor.h"
#include "Kismet/KismetSystemLibrary.h"
#include "SuperSideScroller_Controller.h"
#include "SuperSideScroller_Player.h"

// Sets default values for this component's properties
UBagComponent::UBagComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UBagComponent::GetCoin()
{
	coin++;

	if (coin == 10) {
		//Player의 Playercontroller를 구해서, 화면을 띄운다.

		ASuperSideScroller_Player* Player = Cast<ASuperSideScroller_Player>(GetOwner());

		if (Player) {
			ASuperSideScroller_Controller* PlayerController = Cast<ASuperSideScroller_Controller>(Player->GetController());

			if (PlayerController)
			{
				PlayerController->ShowRestartWidget();
			}
		}
		
	}
}

int32 UBagComponent::returncoin()
{
	return coin;
}


// Called when the game starts
void UBagComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UBagComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


