// Fill out your copyright notice in the Description page of Project Settings.


#include "Orders/OrderQueueComponent.h"

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

		UOrder* ActiveOrder = CurrentOrders[0];

		if (!ActiveOrder->IsActivated())
		{
			ActiveOrder->Activate();
			ActiveOrder->OnBegin();
		}

		// Update the active order
		if (!ActiveOrder->IsCompleted())
		{
			ActiveOrder->OnActiveTick();
		}
		else
		{
			ActiveOrder->OnEnded();
			ActiveOrder->OnRemoved();
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
			CurrentOrders[0]->OnInterrupted();
			CurrentOrders[0]->OnEnded();
			CurrentOrders[0]->OnRemoved();
			CurrentOrders.RemoveAt(0);
			CurrentOrders.Insert(NewOrder, 0);
			break;
		case EOrderQueuePlacement::ReplaceAll:
			ClearOrders();
			CurrentOrders.Push(NewOrder);
			break;
		case EOrderQueuePlacement::Back:
		default:
			CurrentOrders.Push(NewOrder);
			break;
		}

		NewOrder->SetQueue(this);

		NewOrder->OnIssued();
		OrderIssuedEvent.Broadcast(NewOrder);
	}
}

void UOrderQueueComponent::ClearOrders()
{
	if (!CurrentOrders.IsEmpty())
	{
		CurrentOrders[0]->OnInterrupted();
		CurrentOrders[0]->OnEnded();
		for (UOrder* Order : CurrentOrders)
			Order->OnRemoved();

		CurrentOrders.Empty();
	}
}

