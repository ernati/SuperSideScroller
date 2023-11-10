// Fill out your copyright notice in the Description page of Project Settings.


#include "PickableActor_Base.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/RotatingMovementComponent.h"

// Sets default values
APickableActor_Base::APickableActor_Base()
{
 //	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(50.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("OverlapAllDynamic");
	RootComponent = CollisionComp;

	CollisionComp->OnComponentBeginOverlap.AddDynamic(this, &APickableActor_Base::OnBeginOverlap);

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	RotationComp = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("RotationComp"));

}

// Called when the game starts or when spawned
void APickableActor_Base::BeginPlay()
{
	Super::BeginPlay();
	
}

void APickableActor_Base::OnBeginOverlap(UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlap"));

	ASuperSideScroller_Player* Player = Cast<ASuperSideScroller_Player>(OtherActor);

	if (Player)
	{
		PlayerPickedUp(Player);
	}
}

void APickableActor_Base::PlayerPickedUp(class ASuperSideScroller_Player* Player)
{
	//UWorld* world = GetWorld(); 
	//사운드 출력

	Destroy();
}

//// Called every frame
//void APickableActor_Base::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}

