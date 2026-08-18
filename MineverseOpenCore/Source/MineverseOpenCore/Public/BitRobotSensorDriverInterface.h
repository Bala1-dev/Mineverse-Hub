// Copyright 2026 Emmanuel Bala
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "BitRobotSensorTypes.h"
#include "BitRobotSensorDriverInterface.generated.h"

UINTERFACE(BlueprintType)
class MINEVERSEOPENCORE_API UBitRobotSensorDriverInterface : public UInterface
{
    GENERATED_BODY()
};

class MINEVERSEOPENCORE_API IBitRobotSensorDriverInterface
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Mineverse|OpenCore|Sensor")
    void InitialiseSensor();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Mineverse|OpenCore|Sensor")
    void PerformScan(const FVector& ScanLocation, FBitRobotRawSensorReading& OutReading);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Mineverse|OpenCore|Sensor")
    FBitRobotRawSensorReading GetLastReading() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Mineverse|OpenCore|Sensor")
    bool IsReady() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Mineverse|OpenCore|Sensor")
    FName GetSensorType() const;
};
