// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

// UE4:
#include "Components/BoxComponent.h"
// My:
#include "OneFugitive/OneFugitiveCharacter.h"

// Generated:
#include "OF_BasicPlatform.generated.h"



/* ---   Delegate   --- */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlatformBeginOverlap, AOneFugitiveCharacter*, MyCharacter);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlatformEndOverlap, AOneFugitiveCharacter*, MyCharacter);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlatformHit, AOneFugitiveCharacter*, MyCharacter);
// ----------------------------------------------------------------------------------------------------



UCLASS()
class ONEFUGITIVE_API AOF_BasicPlatform : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AOF_BasicPlatform();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = Components)
		class USceneComponent* SceneComponent = nullptr;

	UPROPERTY(Category = PlatformMesh, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* PlatformMesh = nullptr;

	UPROPERTY(Category = PlatformMesh, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UBoxComponent* BoxTrigger = nullptr;
	// ----------------------------------------------------------------------------------------------------



	/* ---   Delegate   --- */
	UPROPERTY(BlueprintAssignable, EditAnywhere, BlueprintReadWrite, Category = "PlatformEvent")
		FOnPlatformBeginOverlap OnPlatformBeginOverlap;
	UPROPERTY(BlueprintAssignable, EditAnywhere, BlueprintReadWrite, Category = "PlatformEvent")
		FOnPlatformEndOverlap OnPlatformEndOverlap;
	UPROPERTY(BlueprintAssignable, EditAnywhere, BlueprintReadWrite, Category = "PlatformEvent")
		FOnPlatformHit OnPlatformHit;
	// ----------------------------------------------------------------------------------------------------


	/* ---   Event   --- */
	//
	UFUNCTION()
		void PlatformBeginOverlap(
			UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult& SweepResult);

	//
	UFUNCTION()
		void PlatformEndOverlap(
			UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex);

	//
	UFUNCTION()
		void PlatformHit(
			UPrimitiveComponent* HitComponent, 
			AActor* OtherActor, 
			UPrimitiveComponent* OtherComp, 
			FVector NormalImpulse, 
			const FHitResult& Hit);
	// ----------------------------------------------------------------------------------------------------



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};


