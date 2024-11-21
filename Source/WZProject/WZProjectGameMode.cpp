// Copyright Epic Games, Inc. All Rights Reserved.

#include "WZProjectGameMode.h"
#include "WZProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AWZProjectGameMode::AWZProjectGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
