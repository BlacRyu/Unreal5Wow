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

protected:

	UOrderQueueComponent* OwnerQueue;

	/** The name of this type of order. */
	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	FName OrderName;

	/** True if this order has started its execution. */
	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	uint32 bActivated:1;

	/** True if this order has completed its execution. */
	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	uint32 bCompleted:1;


public:
	UOrder(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	UFUNCTION(BlueprintCallable, Category = "RTS|Orders")
	FName GetName() { return OrderName; } const

	/** True if this order has started its execution. */
	UFUNCTION(BlueprintCallable, Category = "RTS|Orders")
	bool IsActivated() { return bActivated; } const

	/** Lets this order know it is the currently active order. */
	UFUNCTION(BlueprintCallable, Category = "RTS|Orders")
	void Activate() { bActivated = true; } const

	/** True if this order has completed its execution. */
	UFUNCTION(BlueprintCallable, Category = "RTS|Orders")
	bool IsCompleted() { return bCompleted; } const


	UFUNCTION(BlueprintCallable, Category = "RTS|Orders")
	void SetQueue(UOrderQueueComponent* Queue) { OwnerQueue = Queue; }

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

	/** Called any time this order ends execution. */
	UFUNCTION(BlueprintImplementableEvent, Category = "RTS|Orders")
	void OnEnded();

	/** Called when this order is removed from the queue. */
	UFUNCTION(BlueprintImplementableEvent, Category = "RTS|Orders")
	void OnRemoved();
};
