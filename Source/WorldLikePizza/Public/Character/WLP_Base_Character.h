// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WLP_Base_Character.generated.h"

UCLASS()
class WORLDLIKEPIZZA_API AWLP_Base_Character : public ACharacter
{
	GENERATED_BODY()

public:
	AWLP_Base_Character();

	/** Start of Inputs */
	
	// Is where we put our rules for each input
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category="EnhancedInput")
	class UInputMappingContext* InputMappingContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "EnhancedInput")
	class UInputAction* Input_Jump;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "EnhancedInput")
	class UInputAction* Input_Movement;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "EnhancedInput")
	class UInputAction* Input_Look;

	
	void OnJump_Start(const struct FInputActionValue& Value);
	void OnJump_End(const struct FInputActionValue& Value);
	
	void OnMovement_Start(const struct FInputActionValue& Value);
	void OnMovement_End(const struct FInputActionValue& Value);
	
	void OnLooking_Start(const struct FInputActionValue& Value);
	void OnLooking_End(const struct FInputActionValue& Value);
	
	
protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
