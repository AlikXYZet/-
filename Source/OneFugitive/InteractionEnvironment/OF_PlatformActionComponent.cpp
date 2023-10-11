// Fill out your copyright notice in the Description page of Project Settings.


#include "OF_PlatformActionComponent.h"

// Sets default values for this component's properties
UOF_PlatformActionComponent::UOF_PlatformActionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOF_PlatformActionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	if (ThisPlatform)
	{
		ThisPlatform->OnPlatformBeginOverlap.AddDynamic(this, &UOF_PlatformActionComponent::PlatformBeginOverlap);
		ThisPlatform->OnPlatformEndOverlap.AddDynamic(this, &UOF_PlatformActionComponent::PlatformEndOverlap);
		ThisPlatform->OnPlatformHit.AddDynamic(this, &UOF_PlatformActionComponent::PlatformHit);
	}
}


// Called every frame
void UOF_PlatformActionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}



/* ---   Event   --- */
//
void UOF_PlatformActionComponent::PlatformBeginOverlap_Implementation(AOneFugitiveCharacter* MyCharacter)
{
	// in BP
}

void UOF_PlatformActionComponent::PlatformEndOverlap_Implementation(AOneFugitiveCharacter* MyCharacter)
{
	// in BP
}

void UOF_PlatformActionComponent::PlatformHit_Implementation(AOneFugitiveCharacter* MyCharacter)
{
	// in BP
}
// ----------------------------------------------------------------------------------------------------