// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OF_HealthComponent.generated.h"

/* ---   Delegate   --- */

// ������� ������ ���������
/** Character death delegate */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDead);

/** ������� ��������� �������� ��������� */
/** Character health change delegate */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthChange, float, Health, float, Damage);
// ----------------------------------------------------------------------------------------------------

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ONEFUGITIVE_API UOF_HealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UOF_HealthComponent();

	/* ---   Delegate   --- */

	/** ������� ������ ��������� */
	/** Character death delegate */
	UPROPERTY(BlueprintAssignable, EditAnywhere, BlueprintReadWrite, Category = "Health")
		FOnDead OnDead;

	/** ������� ��������� �������� ��������� */
	/** Character health change delegate */
	UPROPERTY(BlueprintAssignable, EditAnywhere, BlueprintReadWrite, Category = "Health")
		FOnHealthChange OnHealthChange;
	// ----------------------------------------------------------------------------------------------------


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	float Health = 100.0f;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		bool bIsAlive = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float CoefDamage = 1.0f;

	UFUNCTION(BlueprintCallable, Category = "Health")
		float GetCurrentHealth();
	UFUNCTION(BlueprintCallable, Category = "Health")
		void SetCurrentHealth(float NewHealth);

	UFUNCTION(BlueprintCallable, Category = "Health")
		virtual void ChangeHealthValue(float ChangeValue);
};
