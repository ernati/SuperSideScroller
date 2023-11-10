// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SuperSideScrollerCharacter.h"
#include "PlayerProjectile.h"
#include "Engine/World.h"
#include "Components/SphereComponent.h"
#include "BagComponent.h"
#include "SuperSideScroller_Player.generated.h"

/**
 * 
 */
UCLASS()
class SUPERSIDESCROLLER_API ASuperSideScroller_Player : public ASuperSideScrollerCharacter
{
	GENERATED_BODY()

public:
	ASuperSideScroller_Player();
	void SpawnProjectile();

	UFUNCTION(BlueprintPure)
		int32 GetCurrentNumberofCollectables() { return NumberofCollectables; }

	void IncreaseMovementPowerup();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Bag, meta = (AllowPrivateAccess = "true"))
		class UBagComponent* bagcomponent;


	
protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Sprint();
	void StopSprinting();
	void ThrowProjectile();


	/** MappingContext */
	UPROPERTY(EditAnywhere, Category = Input)
		class UInputMappingContext* IC_Character;
	
	UPROPERTY(EditAnywhere, Category = Input)
		class UInputAction* IA_Sprint;

	UPROPERTY(EditAnywhere, Category = Input)
		class UInputAction* IA_Throw;

	void EndPowerup();



private:
	bool bIsSprinting;

	UPROPERTY(EditAnywhere)
		class UAnimMontage* ThrowMontage;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class APlayerProjectile> PlayerProjectile;
	

	int32 NumberofCollectables=0;

	FTimerHandle PowerupHandle;
	bool bHasPowerupActive;


};

