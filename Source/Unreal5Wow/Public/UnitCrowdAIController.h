// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "UnitCrowdAIController.generated.h"

/**
 * Identical to the DetourCrowdAIController
 */
UCLASS()
class UNREAL5WOW_API AUnitCrowdAIController : public AAIController
{
	GENERATED_BODY()

public:
	AUnitCrowdAIController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
};
