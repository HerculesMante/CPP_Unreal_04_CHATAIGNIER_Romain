// Copyright Epic Games, Inc. All Rights Reserved.


#include "CPP_UE_04_RomainPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "CPP_UE_04_RomainCameraManager.h"
#include "Blueprint/UserWidget.h"
#include "CPP_UE_04_Romain.h"
#include "Widgets/Input/SVirtualJoystick.h"

ACPP_UE_04_RomainPlayerController::ACPP_UE_04_RomainPlayerController()
{
	// set the player camera manager class
	PlayerCameraManagerClass = ACPP_UE_04_RomainCameraManager::StaticClass();
}

void ACPP_UE_04_RomainPlayerController::BeginPlay()
{
	Super::BeginPlay();

	
	// only spawn touch controls on local player controllers
	if (SVirtualJoystick::ShouldDisplayTouchInterface() && IsLocalPlayerController())
	{
		// spawn the mobile controls widget
		MobileControlsWidget = CreateWidget<UUserWidget>(this, MobileControlsWidgetClass);

		if (MobileControlsWidget)
		{
			// add the controls to the player screen
			MobileControlsWidget->AddToPlayerScreen(0);

		} else {

			UE_LOG(LogCPP_UE_04_Romain, Error, TEXT("Could not spawn mobile controls widget."));

		}

	}
}

void ACPP_UE_04_RomainPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// only add IMCs for local player controllers
	if (IsLocalPlayerController())
	{
		// Add Input Mapping Context
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
			{
				Subsystem->AddMappingContext(CurrentContext, 0);
			}

			// only add these IMCs if we're not using mobile touch input
			if (!SVirtualJoystick::ShouldDisplayTouchInterface())
			{
				for (UInputMappingContext* CurrentContext : MobileExcludedMappingContexts)
				{
					Subsystem->AddMappingContext(CurrentContext, 0);
				}
			}
		}
	}
	
}
