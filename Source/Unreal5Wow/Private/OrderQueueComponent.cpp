// Fill out your copyright notice in the Description page of Project Settings.


#include "OrderQueueComponent.h"

UOrderQueueComponent::UOrderQueueComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.SetTickFunctionEnable(true);
}


//// Called when the game starts
//void UOrderQueueComponent::BeginPlay()
//{
//	//Super::BeginPlay();
//
//	// ...
//	
//}

void UOrderQueueComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!CurrentOrders.IsEmpty())
	{
		// Send tick event to all orders
		for (UOrder*& Order : CurrentOrders) 
		{
			Order->OnTick();
		}

		// Update the active order
		if (!CurrentOrders[0]->IsCompleted())
		{
			CurrentOrders[0]->OnActiveTick();
		}
		else
		{
			CurrentOrders[0]->OnEnded();
			CurrentOrders[0]->OnRemoved();
			CurrentOrders.RemoveAt(0);
		}	
	}
}

void UOrderQueueComponent::GiveOrder(UOrder* NewOrder, EOrderQueuePlacement Placement)
{
	if (NewOrder)
	{
		switch (Placement)
		{
		case EOrderQueuePlacement::Front:
			CurrentOrders.Insert(NewOrder, 0);
			break;
		case EOrderQueuePlacement::ReplaceAll:
			CurrentOrders.Empty();
			CurrentOrders.Push(NewOrder);
			break;
		case EOrderQueuePlacement::Back:
		default:
			CurrentOrders.Push(NewOrder);
			break;
		}

		NewOrder->OnIssued();
	}
}

