// Fill out your copyright notice in the Description page of Project Settings.


#include "UnitCrowdAIController.h"
#include "Navigation/CrowdFollowingComponent.h"



AUnitCrowdAIController::AUnitCrowdAIController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UCrowdFollowingComponent>(TEXT("PathFollowingComponent")))
{

}
