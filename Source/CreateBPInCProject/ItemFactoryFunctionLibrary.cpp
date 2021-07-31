// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemFactoryFunctionLibrary.h"

void UItemFactoryFunctionLibrary::CreateBPItemAndAddList(UObject* Outer, UListView* TargetListView)
{
	const TSubclassOf<class UObject> BPObject =
		TSoftClassPtr<UObject>(FSoftClassPath(TEXT("/Game/BP_Item.BP_Item_C"))).LoadSynchronous();
	if (BPObject == nullptr)
	{
		return;;
	}
	
	UObject* CreatedObject = NewObject<UObject>(Outer, BPObject);
	if (CreatedObject == nullptr)
	{
		return;
	}
	
	FTextProperty* Property = FindFProperty<FTextProperty>(BPObject, TEXT("Label"));
	if (Property != nullptr)
	{
		 Property->SetPropertyValue(
		 	Property->ContainerPtrToValuePtr<FText>(CreatedObject),
		 	FText::FromString("Created in C++"));
	}
	
	TargetListView->AddItem(CreatedObject);
}
