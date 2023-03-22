// Copyright Michael Olson 2022


#include "Units/UnitBase.h"
#include "AbilitySystemComponent.h"

// Sets default values
AUnitBase::AUnitBase()
{
	ASC = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	ASC->SetIsReplicated(true);
}
