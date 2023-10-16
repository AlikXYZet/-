// Fill out your copyright notice in the Description page of Project Settings.


#include "OF_BasicPlatform.h"

// Sets default values
AOF_BasicPlatform::AOF_BasicPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Platform"));
	PlatformMesh->SetupAttachment(RootComponent);
	PlatformMesh->SetCanEverAffectNavigation(false);
	RootComponent = PlatformMesh;

	BoxTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	BoxTrigger->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AOF_BasicPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	if (BoxTrigger)
	{
		BoxTrigger->OnComponentBeginOverlap.AddDynamic(this, &AOF_BasicPlatform::PlatformBeginOverlap);
		BoxTrigger->OnComponentEndOverlap.AddDynamic(this, &AOF_BasicPlatform::PlatformEndOverlap);
	}

	if (PlatformMesh)
	{
		PlatformMesh->OnComponentHit.AddDynamic(this, &AOF_BasicPlatform::PlatformHit);
	}
}

// Called every frame
void AOF_BasicPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
// ----------------------------------------------------------------------------------------------------



/* ---   Event   --- */
//
void AOF_BasicPlatform::PlatformBeginOverlap(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	AOneFugitiveCharacter* MyCharacter = Cast<AOneFugitiveCharacter>(OtherActor);

	if (MyCharacter)
	{
		OnPlatformBeginOverlap.Broadcast(MyCharacter);
	}
}

//
void AOF_BasicPlatform::PlatformEndOverlap(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	AOneFugitiveCharacter* MyCharacter = Cast<AOneFugitiveCharacter>(OtherActor);

	if (MyCharacter)
	{
		OnPlatformEndOverlap.Broadcast(MyCharacter);
	}
}

//
void AOF_BasicPlatform::PlatformHit(
	UPrimitiveComponent* HitComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	FVector NormalImpulse,
	const FHitResult& Hit)
{
	AOneFugitiveCharacter* MyCharacter = Cast<AOneFugitiveCharacter>(OtherActor);

	if (MyCharacter)
	{
		OnPlatformHit.Broadcast(MyCharacter, Hit);
	}
}
// ----------------------------------------------------------------------------------------------------