// Copyright Michael Olson 2022

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "GameplayAbilities/Attributes/AttributesCommon.h"
#include "AbilitySystemComponent.h"
#include "MovementAttributeSet.generated.h"

#define MOVE_ATTRIBUTE_ACCESSORS(PropertyName) \
	ATTRIBUTE_ACCESSORS(UMovementAttributeSet, PropertyName)

/**
 * Attributes related to movement and collision
 */
UCLASS()
class UNREAL5WOW_API UMovementAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

private:
	UMovementAttributeSet(const FObjectInitializer& ObjectInitializer);


protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category = "Movement")
	FGameplayAttributeData MoveSpeed;
	
public:
	MOVE_ATTRIBUTE_ACCESSORS(MoveSpeed)
};
