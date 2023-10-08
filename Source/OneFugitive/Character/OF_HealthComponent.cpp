// Fill out your copyright notice in the Description page of Project Settings.


#include "OF_HealthComponent.h"

// Sets default values for this component's properties
UOF_HealthComponent::UOF_HealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOF_HealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void UOF_HealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

float UOF_HealthComponent::GetCurrentHealth()
{
	return Health;
}

void UOF_HealthComponent::SetCurrentHealth(float NewHealth)
{
	Health = NewHealth;
}

void UOF_HealthComponent::ChangeHealthValue(float ChangeValue)
{
	ChangeValue *= CoefDamage;

	Health += ChangeValue;

	if (bIsAlive)
	{
		if (Health > 100.0f)
		{
			Health = 100.0f;
		}
		else if (Health < 0.0f)
		{
			bIsAlive = false;
			OnDead.Broadcast();
		}
		else
		{
			OnHealthChange.Broadcast(Health, ChangeValue);
		}
	}
}
