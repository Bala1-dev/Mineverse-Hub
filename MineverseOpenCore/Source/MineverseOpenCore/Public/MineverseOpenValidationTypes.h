// Copyright 2026 Emmanuel Bala
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "CoreMinimal.h"
#include "MineverseOpenValidationTypes.generated.h"

UENUM(BlueprintType)
enum class EMineverseOpenValidationStatus : uint8
{
    Accepted,
    RejectedMissingRequiredField,
    RejectedInvalidIdentifier,
    RejectedOutOfRange,
    RejectedUnsupportedVersion,
    RejectedExternalPolicy
};

USTRUCT(BlueprintType)
struct MINEVERSEOPENCORE_API FMineverseOpenValidationMessage
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mineverse|OpenCore|Validation")
    FName FieldName = NAME_None;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mineverse|OpenCore|Validation")
    EMineverseOpenValidationStatus Status = EMineverseOpenValidationStatus::Accepted;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mineverse|OpenCore|Validation")
    FString Message;
};

USTRUCT(BlueprintType)
struct MINEVERSEOPENCORE_API FMineverseOpenValidationResult
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mineverse|OpenCore|Validation")
    bool bAccepted = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mineverse|OpenCore|Validation")
    EMineverseOpenValidationStatus Status = EMineverseOpenValidationStatus::RejectedMissingRequiredField;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mineverse|OpenCore|Validation")
    FString ContractVersion;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mineverse|OpenCore|Validation")
    TArray<FMineverseOpenValidationMessage> Messages;
};

USTRUCT(BlueprintType)
struct MINEVERSEOPENCORE_API FMineverseOpenIntegrationDescriptor
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mineverse|OpenCore|Validation")
    FName ProviderId = NAME_None;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mineverse|OpenCore|Validation")
    FName ContractName = NAME_None;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mineverse|OpenCore|Validation")
    FString ContractVersion;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mineverse|OpenCore|Validation")
    bool bEnabled = true;
};
