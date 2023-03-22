// Copyright Michael Olson 2022

#include "GameplayAbilities/Attributes/HealthAttributeSet.h"
#include "Net/UnrealNetwork.h"


UHealthAttributeSet::UHealthAttributeSet(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	Health = MaxHealth = 1.f;
	HealthRegen = 0.f;
}

void UHealthAttributeSet::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	DISABLE_ALL_CLASS_REPLICATED_PROPERTIES(UHealthAttributeSet, EFieldIteratorFlags::IncludeSuper);
}

