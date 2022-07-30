// Fill out your copyright notice in the Description page of Project Settings.


#include "Order.h"

UOrder::UOrder(const FObjectInitializer& ObjectInitializer)
	:
	Super(ObjectInitializer),
	Name(TEXT("unnamed order")),
	Activated(false),
	Completed(false)
{

}