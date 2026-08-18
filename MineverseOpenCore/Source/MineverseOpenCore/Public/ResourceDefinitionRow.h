// Copyright 2026 Emmanuel Bala
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ResourceDefinitionRow.generated.h"

USTRUCT(BlueprintType)
struct MINEVERSEOPENCORE_API FResourceDefinitionRow : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mineverse|OpenCore|Resource")
    int32 ResourceID = INDEX_NONE;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mineverse|OpenCore|Resource")
    FString DisplayName;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mineverse|OpenCore|Resource")
    FName Rarity = NAME_None;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mineverse|OpenCore|Resource")
    FName FamilyTag = NAME_None;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mineverse|OpenCore|Resource")
    FString ActivityGlyph;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mineverse|OpenCore|Resource")
    FString Description;
};
