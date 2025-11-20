// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainCharacterController.generated.h"

class UInputAction;
class UInputMappingContext;
/**
 * 
 */
UCLASS()
class COMPLEXDESIGNPROJECT_API AMainCharacterController : public APlayerController
{
	GENERATED_BODY()
public:
	AMainCharacterController();
private:
	void BeginPlay() override;
	virtual void SetupInputComponent() override;
	void OnClick();
protected:
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Input")
	TObjectPtr<UInputMappingContext> MappingContext;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Input")
	TObjectPtr<UInputAction> ClickAction;
	
};
