// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerCharacter.h"
#include "BruteCharacter.generated.h"

UCLASS()
class BRUTE_API ABruteCharacter : public APlayerCharacter
{
	GENERATED_BODY()

public:
	ABruteCharacter();

protected:
	virtual void BeginPlay() override;

public:
	
	virtual void Tick(float DeltaTime) override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
