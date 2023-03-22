// Copyright Michael Olson 2022

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "AbilitySystemInterface.h"
#include "UnitBase.generated.h"

class UAbilitySystemComponent;

UCLASS()
class UNREAL5WOW_API AUnitBase : public APawn, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AUnitBase();

	// Ability System Component
	UPROPERTY(Category = AbilitySystem, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UAbilitySystemComponent* ASC;

public:
	//~ Begin IAbilitySystemInterface
	/** Returns AbilitySystemComponent subobject **/
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override { return ASC; }
	//~ End IAbilitySystemInterface
};
