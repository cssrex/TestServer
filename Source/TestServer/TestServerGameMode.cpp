// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestServerGameMode.h"
#include "TestServerCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATestServerGameMode::ATestServerGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
