#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PlayerMovementComponent.generated.h"


UENUM(BlueprintType)
enum ECustomMovementMode : uint8
{
	Walk,
	Jog,
	Sprint
};

class ABasePlayerController;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BRUTE_API UPlayerMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:
	
	UPlayerMovementComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	void BindDependencies();
	virtual void BeginPlay() override;


#pragma region WALK / SPRINT

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player Custom Movement")
	TObjectPtr<ABasePlayerController> BasePlayerController; 

	float InitialGroundSpeed;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Player Custom Movement")
	float WalkMaxWalkSpeed = 200.f;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Player Custom Movement")
	bool bWantsToWalk = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Player Custom Movement")
	float SprintMaxWalkSpeed = 200.f;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Player Custom Movement")
	bool bWantsToSprint = false;

	ECustomMovementMode CurrentCustomMovementMode = Jog;
	ECustomMovementMode PrevCustomMovementMode = Jog;

public:

	UFUNCTION()	
	void HandleCustomMovement(const ECustomMovementMode& DesiredCustomMovementMode);


	UFUNCTION()
	FORCEINLINE void SetWantsToSprint(bool InbWantsToSprint) { bWantsToSprint = InbWantsToSprint; }

#pragma endregion
	
	
};
