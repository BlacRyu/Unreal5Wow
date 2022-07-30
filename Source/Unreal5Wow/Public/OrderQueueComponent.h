// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Containers/Array.h"
#include "Order.h"
#include "Components/ActorComponent.h"
#include "OrderQueueComponent.generated.h"

/** Dictates where this order should be placed in the queue and how the queue should respond. */
UENUM()
enum class EOrderQueuePlacement : uint8
{
	// Places the order at the back of the queue, to be executed last
	Back,
	// Places the order at the front of the queue, to be executed now
	Front,
	// Removes all other orders from the queue and executes this order now
	ReplaceAll,
};

/** 
	The Order Queue component allows a unit to maintain a list of orders that will be executed in order.
*/
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREAL5WOW_API UOrderQueueComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOrderQueueComponent();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Orders")
	TArray<UOrder*> CurrentOrders;

protected:
	// Called when the game starts
	//virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


public:	
	// Called every frame
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Orders")
	void GiveOrder(UOrder* NewOrder, EOrderQueuePlacement Placement = EOrderQueuePlacement::Back);

	UFUNCTION(BlueprintCallable, Category = "Orders", meta = (ShortTooltip = "Remove all queued orders"))
	void ClearOrders() { CurrentOrders.Empty(); }

	UFUNCTION(BlueprintCallable, Category = "Orders")
	const TArray<UOrder*>& GetOrders() const { return CurrentOrders; }

	UFUNCTION(BlueprintCallable, Category = "Orders")
	const UOrder* GetOrder(int32 index = 0) const { return CurrentOrders[index]; }
};
