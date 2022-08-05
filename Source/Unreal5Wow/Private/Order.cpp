// Fill out your copyright notice in the Description page of Project Settings.


#include "Order.h"

UOrder::UOrder(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	OrderName = TEXT("unnamed order");
	bActivated = false;
	bCompleted = false;
}