// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/DynamicDataSubsystem.h"

#include "Data/DefinitionBase.h"
#include "Engine/AssetManager.h"

bool UDynamicDataSubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
    TArray<UClass*> ChildClasses;
    GetDerivedClasses(GetClass(), ChildClasses, false);

    return ChildClasses.Num() == 0;
}

TArray<UDefinitionBase*> UDynamicDataSubsystem::GetAllDefinitions(TSubclassOf<UDefinitionBase> DefinitionClass)
{
    TArray<UDefinitionBase*> Definitions;
    if (!DefinitionClass) return Definitions;

    UAssetManager& AssetManager = UAssetManager::Get();
    TArray<FAssetData> AssetDataList;
    AssetManager.GetPrimaryAssetDataList(DefinitionClass->GetFName(), AssetDataList);
    Definitions.Reserve(AssetDataList.Num());

    for (const FAssetData& AssetData : AssetDataList)
    {
        UDefinitionBase* Definition = Cast<UDefinitionBase>(AssetData.GetAsset());
        if (Definition) Definitions.Emplace(Definition);
    }

    return Definitions;
}

UDefinitionBase* UDynamicDataSubsystem::GetDefinitionByID(TSubclassOf<UDefinitionBase> DefinitionClass, int32 ID)
{
    if (!DefinitionClass || ID < 0) return nullptr;

    UAssetManager& AssetManager = UAssetManager::Get();
    FPrimaryAssetId AssetID = FPrimaryAssetId(DefinitionClass->GetFName(), FName(FString::FromInt(ID)));
    FAssetData AssetData;
    AssetManager.GetPrimaryAssetData(AssetID, AssetData);

    return Cast<UDefinitionBase>(AssetData.GetAsset());
}
