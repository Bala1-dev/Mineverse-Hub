// Copyright 2026 Emmanuel Bala
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "CoreMinimal.h"
#include "BitRobotSensorTypes.generated.h"

USTRUCT(BlueprintType)
struct MINEVERSEOPENCORE_API FBitRobotRawSensorReading
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mineverse|OpenCore|Sensor")
    int32 ResourceID = INDEX_NONE;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mineverse|OpenCore|Sensor")
    FString RawSpectralData;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mineverse|OpenCore|Sensor")
    FVector ScanLocation = FVector::ZeroVector;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mineverse|OpenCore|Sensor")
    FString ScanTimestamp;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mineverse|OpenCore|Sensor")
    FName SensorType = NAME_None;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mineverse|OpenCore|Sensor")
    int32 SeedValue = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mineverse|OpenCore|Sensor")
    double VarianceDelta = 0.0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mineverse|OpenCore|Sensor")
    FName ResourceName = NAME_None;
};
