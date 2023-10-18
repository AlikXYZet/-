// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

// UE4:
#include "Particles/ParticleSystemComponent.h"
// Plugins:
#include "NiagaraComponent.h"
// My:
#include "OF_BasicPlatform.h"

// Generated:
#include "OF_PlatformActionComponent.generated.h"



UCLASS(ClassGroup = (Custom), BlueprintType, Blueprintable, EditInlineNew, meta = (BlueprintSpawnableComponent))
class ONEFUGITIVE_API UOF_PlatformActionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UOF_PlatformActionComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	// ----------------------------------------------------------------------------------------------------



	/* ---   Event   --- */
	//
	UFUNCTION()
		void PlatformBeginOverlap(AOneFugitiveCharacter* MyCharacter);
	UFUNCTION(BlueprintNativeEvent)
		void PlatformBeginOverlap_BP(AOneFugitiveCharacter* MyCharacter);

	UFUNCTION()
		void PlatformEndOverlap(AOneFugitiveCharacter* MyCharacter);
	UFUNCTION(BlueprintNativeEvent)
		void PlatformEndOverlap_BP(AOneFugitiveCharacter* MyCharacter);

	UFUNCTION()
		void PlatformHit(AOneFugitiveCharacter* MyCharacter, const FHitResult& Hit);
	UFUNCTION(BlueprintNativeEvent)
		void PlatformHit_BP(AOneFugitiveCharacter* MyCharacter, const FHitResult& Hit);
	// ----------------------------------------------------------------------------------------------------



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlatformAction")
		bool bActionLogicIsActive = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlatformAction")
		AOF_BasicPlatform* ThisPlatform = Cast<AOF_BasicPlatform>(GetOwner());

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlatformAction")
		TArray<AOneFugitiveCharacter*> StandingCharacters;

	/* ---   Particle   --- */

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlatformAction|Particle")
		UParticleSystem* PlatformParticle = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = "PlatformAction|Particle")
		UParticleSystemComponent* PlatformParticleComponent = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlatformAction|Particle")
		FTransform Transform_PC = FTransform();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlatformAction|Particle")
		bool bManualAttachment_PC = false;
	// ----------------------------------------------------------------------------------------------------



	/* ---   Niagara   --- */

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlatformAction|Niagara")
		UNiagaraSystem* PlatformNiagaraTemplate = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = "PlatformAction|Niagara")
		UNiagaraComponent* PlatformNiagaraComponent = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlatformAction|Niagara")
		FTransform Transform_NC = FTransform();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlatformAction|Niagara")
		bool bAutoDestroy_NC = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlatformAction|Niagara")
		bool bAutoActivate_NC = false;
	// ----------------------------------------------------------------------------------------------------
};
