// Fill out your copyright notice in the Description page of Project Settings.


#include "Brute/Public/Characters/BruteCharacter.h"


// Sets default values
ABruteCharacter::ABruteCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ABruteCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABruteCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABruteCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

