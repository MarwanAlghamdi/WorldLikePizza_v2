// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/WLP_Base_Character.h"

#include <rpclib/2.2.1/include/rpc/detail/log.h>

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

// Sets default values
AWLP_Base_Character::AWLP_Base_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWLP_Base_Character::BeginPlay()
{
	Super::BeginPlay();
	
	// Get the player controller
	APlayerController* PC = Cast<APlayerController>(GetController());
	if (PC)

	{
		// NOTE 1.1: Here, what we have done is, When the game starts ULocalPlayerSubsystem Initialize then UEnhancedInputLocalPlayerSubsystem will initialize too
		// NOTE 1.2: Now every player has its own LocalPlayer class which we can get the system out of it then cast it to our system.
		// Get the local player subsystem
		UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer());
		
		// Clear existing mapping, and add ours
		Subsystem->ClearAllMappings();
		Subsystem->AddMappingContext(InputMappingContext,0);
	}
}


// Called every frame
void AWLP_Base_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AWLP_Base_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	UEnhancedInputComponent* PlayerEnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (PlayerEnhancedInput)
	{
		PlayerEnhancedInput->BindAction(Input_Jump, ETriggerEvent::Started, this, &AWLP_Base_Character::OnJump_Start);
		PlayerEnhancedInput->BindAction(Input_Jump, ETriggerEvent::Canceled, this, &AWLP_Base_Character::OnJump_End);
	}

}

void AWLP_Base_Character::OnJump_Start(const FInputActionValue& Value)
{
	const bool InputState = Value.Get<bool>();
	UE_LOG(LogTemp,Display,TEXT("The current value for Jump is %s"), InputState);
}

void AWLP_Base_Character::OnJump_End(const FInputActionValue& Value)
{
	const bool InputState = Value.Get<bool>();
	UE_LOG(LogTemp,Display,TEXT("The current value for Jump is %d"), InputState);
}

void AWLP_Base_Character::OnMovement_Start(const FInputActionValue& Value)
{
}

void AWLP_Base_Character::OnMovement_End(const FInputActionValue& Value)
{
}

void AWLP_Base_Character::OnLooking_Start(const FInputActionValue& Value)
{
}

void AWLP_Base_Character::OnLooking_End(const FInputActionValue& Value)
{
}
