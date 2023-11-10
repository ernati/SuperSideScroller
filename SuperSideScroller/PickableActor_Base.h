// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SuperSideScroller_Player.h"
#include "PickableActor_Base.generated.h"

UCLASS()
class SUPERSIDESCROLLER_API APickableActor_Base : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickableActor_Base();

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	UFUNCTION(BlueprintCallable, Category = "Move")
	virtual void PlayerPickedUp(class ASuperSideScroller_Player* Player);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly, Category = PickableItem)
		class USphereComponent* CollisionComp;

	UPROPERTY(VisibleDefaultsOnly, Category = PickableItem)
		class UStaticMeshComponent* MeshComp;

	UPROPERTY(VisibleDefaultsOnly, Category = PickableItem)
		class URotatingMovementComponent* RotationComp;

public:	
	//// Called every frame
	//virtual void Tick(float DeltaTime) override;

private:

};