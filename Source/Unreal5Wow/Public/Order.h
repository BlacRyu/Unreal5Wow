// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Order.generated.h"

class UOrderQueueComponent;

/**
 * Represents an order that can be given to any unit with an OrderQueue component
 */
UCLASS(config = Game, BlueprintType, Blueprintable)
class UNREAL5WOW_API UOrder : public UObject
{
	GENERATED_BODY()
private:
	UOrder(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	/** The name of this type of order. */
	FString Name;

	/** True if this order has started its execution. */
	uint32 Activated : 1;

	/** True if this order has completed its execution. */
	uint32 Completed:1;


public:

	// Blueprint Events

	/** Called when this order is first added to the order queue. */
	UFUNCTION(BlueprintImplementableEvent, Category = "RTS|Orders")
	void OnIssued();

	/** Called when this order begins execution. */
	UFUNCTION(BlueprintImplementableEvent, Category = "RTS|Orders")
	void OnBegin();

	/** Called every game tick, regardless of if this order is executing or not. */
	UFUNCTION(BlueprintImplementableEvent, Category = "RTS|Orders")
	void OnTick();

	/** Called every game tick while this order is executing. */
	UFUNCTION(BlueprintImplementableEvent, Category = "RTS|Orders")
	void OnActiveTick();

	/** Called when this order's execution is stopped due to external factors. */
	UFUNCTION(BlueprintImplementableEvent, Category = "RTS|Orders")
	void OnInterrupted();

	/** Called when this order ends execution. */
	UFUNCTION(BlueprintImplementableEvent, Category = "RTS|Orders")
	void OnEnded();

	/** Called when this order is removed from the queue. */
	UFUNCTION(BlueprintImplementableEvent, Category = "RTS|Orders")
	void OnRemoved();

	/** Called when another order is added to the queue. */
	UFUNCTION(BlueprintImplementableEvent, Category = "RTS|Orders")
	void OnOtherOrderIssued(UOrder* IssuedOrder);

	/** Called when another order is removed from the queue. */
	UFUNCTION(BlueprintImplementableEvent, Category = "RTS|Orders")
	void OnOtherOrderRemoved(UOrder* RemovedOrder);

	/** True if this order has completed its execution. */
	UFUNCTION(BlueprintCallable, Category = "RTS|Orders")
	bool IsCompleted() { return Completed; }
};
