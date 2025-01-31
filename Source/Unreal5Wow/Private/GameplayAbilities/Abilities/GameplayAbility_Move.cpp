// Copyright Michael Olson 2022


#include "GameplayAbilities/Abilities/GameplayAbility_Move.h"

bool UGameplayAbility_Move::CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags, const FGameplayTagContainer* TargetTags, OUT FGameplayTagContainer* OptionalRelevantTags) const
{
    return Super::CanActivateAbility(Handle, ActorInfo, SourceTags, TargetTags, OptionalRelevantTags);
}

void UGameplayAbility_Move::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
    Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if (!CommitAbility(Handle, ActorInfo, ActivationInfo))
	{
		constexpr bool bReplicateEndAbility = true;
		constexpr bool bWasCancelled = true;
		EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
	}
	UGameplayAbility* OwningAbility = this;
	FName TaskInstanceName;
	FVector Location = TriggerEventData->Target->GetActorLocation() + FVector(100, 0, 0);
	float Duration = 1.0;

	MoveTask = UAbilityTask_MoveToLocation::MoveToLocation(OwningAbility, TaskInstanceName, Location, Duration, NULL, NULL);
}
