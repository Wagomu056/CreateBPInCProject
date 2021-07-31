// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Components/ListView.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "ItemFactoryFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class CREATEBPINCPROJECT_API UItemFactoryFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	/**
	 * @brief BP_Itemを作成してリストに追加する
	 * @param Outer BP_Itemの持ち主
	 * @param TargetListView 追加するリスト
	 */
	UFUNCTION(BlueprintCallable, Category="ItemFactoryFunctionLibrary")
	static void CreateBPItemAndAddList(UObject* Outer, UListView* TargetListView);
};
