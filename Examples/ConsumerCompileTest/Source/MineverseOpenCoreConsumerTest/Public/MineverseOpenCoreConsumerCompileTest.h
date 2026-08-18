// Copyright 2026 Emmanuel Bala
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "BitRobotSensorDriverInterface.h"
#include "BitRobotSensorTypes.h"
#include "BiomeResourceRow.h"
#include "DroneInterface.h"
#include "MineverseOpenCore.h"
#include "MineverseOpenValidationTypes.h"
#include "ResourceDefinitionRow.h"
#include "UNITInterface.h"
#include "WeaponDataRow.h"
#include "MineverseOpenCoreConsumerCompileTest.generated.h"

UCLASS()
class UMineverseOpenCoreConsumerSensorAdapter final : public UObject, public IBitRobotSensorDriverInterface
{
    GENERATED_BODY()

public:
    virtual void InitialiseSensor_Implementation() override;
    virtual void PerformScan_Implementation(const FVector& ScanLocation, FBitRobotRawSensorReading& OutReading) override;
    virtual FBitRobotRawSensorReading GetLastReading_Implementation() const override;
    virtual bool IsReady_Implementation() const override;
    virtual FName GetSensorType_Implementation() const override;

private:
    FBitRobotRawSensorReading LastReading;
    bool bReady = false;
};

UCLASS()
class UMineverseOpenCoreConsumerDroneAdapter final : public UObject, public IDroneInterface
{
    GENERATED_BODY()

public:
    virtual void InjectIntoBiome_Implementation(FName BiomeTag, FVector SpawnLocation) override;
    virtual void AssignSurveyMission_Implementation(int32 ResourceID, FName BiomeTag) override;
    virtual void ExtractFromBiome_Implementation() override;
    virtual FString GetMissionStatus_Implementation() const override;
    virtual bool IsInjected_Implementation() const override;
    virtual void ReportScanComplete_Implementation(int32 ResourceID, int32 QuantityObserved, bool bAnomalyDetected) override;

private:
    FName CurrentBiome = NAME_None;
    int32 CurrentResourceID = INDEX_NONE;
    bool bInjected = false;
    FString MissionStatus = TEXT("Idle");
};

UCLASS()
class UMineverseOpenCoreConsumerUnitAdapter final : public UObject, public IUNITInterface
{
    GENERATED_BODY()

public:
    virtual void RegisterWithNetwork_Implementation(const FString& NodeSignature) override;
    virtual void BroadcastResourceEvent_Implementation(int32 ResourceID, int32 Quantity, FName BiomeTag) override;
    virtual FString GetNodeSignature_Implementation() const override;
    virtual bool IsNetworkVerified_Implementation() const override;

private:
    FString RegisteredNodeSignature;
    bool bVerified = false;
};

UCLASS()
class UMineverseOpenCoreConsumerCompileTest final : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "Mineverse|OpenCore|ConsumerTest")
    static bool RunCompileSmokeTest();
};
