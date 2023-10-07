// Copyright Epic Games, Inc. All Rights Reserved.

#include "OneFugitiveGameMode.h"
#include "OneFugitiveCharacter.h"
#include "UObject/ConstructorHelpers.h"

AOneFugitiveGameMode::AOneFugitiveGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/OF/Blueprints/Character/BP_Character"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
