// Copyright Michael Olson 2022

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
//#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Components/SphereComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameplayAbilities/Attributes/HealthAttributeSet.h"
#include "GameplayAbilities/Attributes/MovementAttributeSet.h"
#include "UnitBase.generated.h"

class UAbilitySystemComponent;

UCLASS()
class UNREAL5WOW_API AUnitBase : public APawn, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(Category = Physics, VisibleAnywhere, BlueprintReadOnly)
	UCapsuleComponent* CapsuleCollider;

	UPROPERTY(Category = Physics, VisibleAnywhere, BlueprintReadOnly)
	USphereComponent* SeparationArea;
	/*UPROPERTY(Category = Physics, VisibleAnywhere, BlueprintReadOnly)
	USphereComponent* AlignmentArea;*/

	// Ability System Component
	UPROPERTY(Category = AbilitySystem, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UAbilitySystemComponent* ASC;

	UPROPERTY(Category = AbilitySystem, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	const UHealthAttributeSet* HealthAttributeSet;

	UPROPERTY(Category = AbilitySystem, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	const UMovementAttributeSet* MovementAttributeSet;

public:
	// Sets default values for this pawn's properties
	AUnitBase();

	//~ Begin IAbilitySystemInterface
	/** Returns AbilitySystemComponent subobject **/
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override { return ASC; }
	//~ End IAbilitySystemInterface

public:
	void PossessedBy(AController* NewController);

	void BeginPlay();

	void Tick(float DeltaSeconds);
};
