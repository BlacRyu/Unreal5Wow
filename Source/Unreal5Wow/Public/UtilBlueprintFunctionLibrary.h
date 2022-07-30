// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UtilBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL5WOW_API UUtilBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Viewport")
	static bool ViewportHasFocus() 
	{ 
		return GEngine && GEngine->GameViewport && GEngine->GameViewport->Viewport && GEngine->GameViewport->Viewport->IsForegroundWindow();
	}
};
