// Copyright 2026 Emmanuel Bala
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "BiomeResourceRow.generated.h"

USTRUCT(BlueprintType)
struct MINEVERSEOPENCORE_API FBiomeResourceRow : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mineverse|OpenCore|Biome")
    FName BiomeTag = NAME_None;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mineverse|OpenCore|Biome")
    TArray<int32> ValidResourceIDs;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mineverse|OpenCore|Biome")
    FString BiomeDisplayName;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mineverse|OpenCore|Biome")
    FString BiomeDescription;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mineverse|OpenCore|Biome")
    bool bIsHazardous = false;
};
