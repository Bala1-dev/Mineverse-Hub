// Copyright 2026 Emmanuel Bala
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DroneInterface.generated.h"

UINTERFACE(BlueprintType)
class MINEVERSEOPENCORE_API UDroneInterface : public UInterface
{
    GENERATED_BODY()
};

class MINEVERSEOPENCORE_API IDroneInterface
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Mineverse|OpenCore|Drone")
    void InjectIntoBiome(FName BiomeTag, FVector SpawnLocation);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Mineverse|OpenCore|Drone")
    void AssignSurveyMission(int32 ResourceID, FName BiomeTag);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Mineverse|OpenCore|Drone")
    void ExtractFromBiome();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Mineverse|OpenCore|Drone")
    FString GetMissionStatus() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Mineverse|OpenCore|Drone")
    bool IsInjected() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Mineverse|OpenCore|Drone")
    void ReportScanComplete(int32 ResourceID, int32 QuantityObserved, bool bAnomalyDetected);
};
