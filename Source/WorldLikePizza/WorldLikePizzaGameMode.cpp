// Copyright Epic Games, Inc. All Rights Reserved.

#include "WorldLikePizzaGameMode.h"
#include "WorldLikePizzaCharacter.h"
#include "UObject/ConstructorHelpers.h"

AWorldLikePizzaGameMode::AWorldLikePizzaGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
