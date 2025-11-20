// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacterController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputAction.h"

#include "Blueprint/AIBlueprintHelperLibrary.h"

AMainCharacterController::AMainCharacterController()
{
}

void AMainCharacterController::BeginPlay()
{
	Super::BeginPlay();
	SetShowMouseCursor(true);
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
		EnhancedInputComponent->BindAction(ClickAction, ETriggerEvent::Completed,this,&AMainCharacterController::OnClick);
	}
	
}

void AMainCharacterController::OnClick()
{
	//StopMovement();
	FHitResult HitResult;
	GetHitResultUnderCursor(ECC_Visibility,false,HitResult);
	if (HitResult.bBlockingHit)
	{
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this,HitResult.ImpactPoint);
	}
	
}
