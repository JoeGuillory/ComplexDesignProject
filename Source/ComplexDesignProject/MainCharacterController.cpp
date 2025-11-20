// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacterController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "NavigationSystem.h"

AMainCharacterController::AMainCharacterController()
{
}

void AMainCharacterController::BeginPlay()
{
	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(MappingContext,0);
	}
}

void AMainCharacterController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(ClickAction, ETriggerEvent::Completed,this,OnClick);
	}
	
}

void AMainCharacterController::OnClick()
{
	UEngine::AddOnScreenDebugMessage(0,10,FColor::Red,TEXT("Input Setup Works"));
}
