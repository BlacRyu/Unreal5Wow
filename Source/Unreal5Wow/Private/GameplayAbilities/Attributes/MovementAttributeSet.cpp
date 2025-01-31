// Copyright Michael Olson 2022

#include "GameplayAbilities/Attributes/MovementAttributeSet.h"
#include "Net/UnrealNetwork.h"


UMovementAttributeSet::UMovementAttributeSet(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	MoveSpeed = 300.0;
}

void UMovementAttributeSet::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	DISABLE_ALL_CLASS_REPLICATED_PROPERTIES(UMovementAttributeSet, EFieldIteratorFlags::IncludeSuper);
}