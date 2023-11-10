// Fill out your copyright notice in the Description page of Project Settings.


#include "PickableActor_Collectable.h"
#include "BagComponent.h"
#include "SuperSideScroller_Player.h"
#include "SuperSideScroller_Controller.h"

void APickableActor_Collectable::PlayerPickedUp(class ASuperSideScroller_Player* Player)
{
	if (Player != nullptr) {
		UBagComponent* BagComponent = Player->FindComponentByClass<UBagComponent>();

		if (BagComponent != nullptr)
		{
			BagComponent->GetCoin();

			ASuperSideScroller_Controller* PlayerController = Cast<ASuperSideScroller_Controller>(Player->GetController());

			if (PlayerController)
			{
				PlayerController->UpdateCoin( BagComponent->returncoin() );
			}
		}

		Super::PlayerPickedUp(Player);
	}
}

void APickableActor_Collectable::BeginPlay() {
	Super::BeginPlay();
}

