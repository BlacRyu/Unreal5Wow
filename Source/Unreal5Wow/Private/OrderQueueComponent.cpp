// Fill out your copyright notice in the Description page of Project Settings.


#include "OrderQueueComponent.h"

// Sets default values for this component's properties
UOrderQueueComponent::UOrderQueueComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	//PrimaryComponentTick.bCanEverTick = true;

	// ...
}


//// Called when the game starts
//void UOrderQueueComponent::BeginPlay()
//{
//	//Super::BeginPlay();
//
//	// ...
//	
//}
//
//
//// Called every frame
//void UOrderQueueComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
//{
//	//Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
//
//	// ...
//}

void UOrderQueueComponent::GiveOrder(UOrder* NewOrder, EOrderQueuePlacement Placement)
{
	if (NewOrder)
	{
		switch (Placement)
		{
		case EOrderQueuePlacement::Front:
			CurrentOrders.Insert(*NewOrder, 0);
			break;
		case EOrderQueuePlacement::ReplaceAll:
			CurrentOrders.Empty();
			CurrentOrders.Push(*NewOrder);
			break;
		case EOrderQueuePlacement::Back:
		default:
			CurrentOrders.Push(*NewOrder);
			break;
		}
	}
}

