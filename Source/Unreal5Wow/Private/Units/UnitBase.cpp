// Copyright Michael Olson 2022


#include "Units/UnitBase.h"
#include "AbilitySystemComponent.h"

// Sets default values
AUnitBase::AUnitBase()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
}