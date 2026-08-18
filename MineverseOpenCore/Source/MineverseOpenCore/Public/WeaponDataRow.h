// Copyright 2026 Emmanuel Bala
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "WeaponDataRow.generated.h"

class UStaticMesh;

UENUM(BlueprintType)
enum class EMineverseOpenWeaponClass : uint8
{
    Pistol,
    Revolver,
    SMG,
    Rifle,
    Shotgun,
    Sniper,
    LMG,
    Launcher,
    Minigun
};

UENUM(BlueprintType)
enum class EMineverseOpenFireMode : uint8
{
    Single,
    Burst,
    Auto
};

UENUM(BlueprintType)
enum class EMineverseOpenAnimStance : uint8
{
    Pistol,
    Rifle,
    Heavy
};

USTRUCT(BlueprintType)
struct MINEVERSEOPENCORE_API FMineverseOpenWeaponDataRow : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mineverse|OpenCore|Weapon")
    TSoftObjectPtr<UStaticMesh> WeaponMesh;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mineverse|OpenCore|Weapon")
    FName WeaponName = NAME_None;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mineverse|OpenCore|Weapon")
    FName WeaponRowName = NAME_None;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mineverse|OpenCore|Weapon")
    EMineverseOpenWeaponClass WeaponClass = EMineverseOpenWeaponClass::Rifle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mineverse|OpenCore|Weapon")
    EMineverseOpenFireMode FireMode = EMineverseOpenFireMode::Auto;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mineverse|OpenCore|Weapon")
    EMineverseOpenAnimStance AnimStance = EMineverseOpenAnimStance::Rifle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mineverse|OpenCore|Weapon", meta = (ClampMin = "1.0", UIMin = "1.0"))
    float FireRate = 600.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mineverse|OpenCore|Weapon", meta = (ClampMin = "0.0", UIMin = "0.0"))
    float WeaponMass = 3.5f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mineverse|OpenCore|Weapon")
    FVector MuzzleOffset = FVector::ZeroVector;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mineverse|OpenCore|Weapon")
    FVector AimOffset = FVector::ZeroVector;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mineverse|OpenCore|Weapon", meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
    float AssistStrength = 0.4f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mineverse|OpenCore|Weapon", meta = (ClampMin = "0.0", UIMin = "0.0"))
    float RecoilStrength = 0.6f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mineverse|OpenCore|Weapon", meta = (ClampMin = "0.0", UIMin = "0.0"))
    float SwayMultiplier = 0.5f;
};
