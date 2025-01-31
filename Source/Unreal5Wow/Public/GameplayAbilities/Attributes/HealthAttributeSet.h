// Copyright Michael Olson 2022

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "GameplayAbilities/Attributes/AttributesCommon.h"
#include "AbilitySystemComponent.h"
#include "HealthAttributeSet.generated.h"

#define HEALTH_ATTRIBUTE_ACCESSORS(PropertyName) \
	ATTRIBUTE_ACCESSORS(UHealthAttributeSet, PropertyName)

/**
 * Attributes related to a unit's health.
 */
UCLASS()
class UNREAL5WOW_API UHealthAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

	private:
	UHealthAttributeSet(const FObjectInitializer& ObjectInitializer);

	protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category = "Health")
	FGameplayAttributeData MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category = "Health")
	FGameplayAttributeData Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category = "Health")
	FGameplayAttributeData HealthRegen;


	public:
	HEALTH_ATTRIBUTE_ACCESSORS(MaxHealth)
	HEALTH_ATTRIBUTE_ACCESSORS(Health)
	HEALTH_ATTRIBUTE_ACCESSORS(HealthRegen)
};
