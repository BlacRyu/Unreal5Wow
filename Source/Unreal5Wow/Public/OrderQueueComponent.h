// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Containers/Array.h"
#include "Order.h"
#include "Components/ActorComponent.h"
#include "OrderQueueComponent.generated.h"

UENUM()
enum class EOrderQueuePlacement : uint8
{
	Back,
	Front,
	ReplaceAll
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREAL5WOW_API UOrderQueueComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOrderQueueComponent();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Orders")
	TArray<UOrder> CurrentOrders;

protected:
	// Called when the game starts
	//virtual void BeginPlay() override;

public:	
	// Called every frame
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Orders")
	void GiveOrder(UOrder* NewOrder, EOrderQueuePlacement Placement = EOrderQueuePlacement::Back);


	UFUNCTION(BlueprintCallable, Category = "Orders", meta = (ShortTooltip = "Remove all queued orders"))
	void ClearOrders() { CurrentOrders.Empty(); }

	UFUNCTION(BlueprintCallable, Category = "Orders")
	const TArray<UOrder> GetOrders() const { return CurrentOrders; }

	UFUNCTION(BlueprintCallable, Category = "Orders")
	const UOrder* GetOrder(int32 index = 0) const { return &CurrentOrders[index]; }
	

};
