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

		if (PlatformParticle)
		{
			PlatformParticleComponent = Cast<UParticleSystemComponent>(
				ThisPlatform->AddComponentByClass(
					UParticleSystemComponent::StaticClass(), 
					false,
					Transform_PC,
					bManualAttachment_PC));

			PlatformParticleComponent->SetTemplate(PlatformParticle);
		}

		if (PlatformNiagaraTemplate)
		{
			PlatformNiagaraComponent = UNiagaraFunctionLibrary::SpawnSystemAttached(
				PlatformNiagaraTemplate, 
				ThisPlatform->SceneComponent, 
				NAME_None, 
				Transform_NC.GetLocation(),
				FRotator(Transform_NC.GetRotation()),
				EAttachLocation::Type::KeepRelativeOffset, 
				bAutoDestroy_NC,
				bAutoActivate_NC);

			PlatformNiagaraComponent->SetRelativeScale3D(Transform_NC.GetScale3D());
		}
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
void UOF_PlatformActionComponent::PlatformBeginOverlap(AOneFugitiveCharacter* MyCharacter)
{
	StandingCharacters.AddUnique(MyCharacter);

	PlatformBeginOverlap_BP(MyCharacter);
}

void UOF_PlatformActionComponent::PlatformBeginOverlap_BP_Implementation(AOneFugitiveCharacter* MyCharacter)
{
	// in BP
}

//
void UOF_PlatformActionComponent::PlatformEndOverlap(AOneFugitiveCharacter* MyCharacter)
{
	StandingCharacters.Remove(MyCharacter);

	PlatformEndOverlap_BP(MyCharacter);
}

void UOF_PlatformActionComponent::PlatformEndOverlap_BP_Implementation(AOneFugitiveCharacter* MyCharacter)
{
	// in BP
}

//
void UOF_PlatformActionComponent::PlatformHit(bool bTopHit, AOneFugitiveCharacter* MyCharacter, const FHitResult& Hit)
{
	PlatformHit_BP(bTopHit, MyCharacter, Hit);
}

void UOF_PlatformActionComponent::PlatformHit_BP_Implementation(bool bTopHit, AOneFugitiveCharacter* MyCharacter, const FHitResult& Hit)
{
	// in BP
}
// ----------------------------------------------------------------------------------------------------