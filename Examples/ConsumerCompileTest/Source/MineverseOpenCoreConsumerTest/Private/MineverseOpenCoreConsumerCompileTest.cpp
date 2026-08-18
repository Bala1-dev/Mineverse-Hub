// Copyright 2026 Emmanuel Bala
// SPDX-License-Identifier: Apache-2.0

#include "MineverseOpenCoreConsumerCompileTest.h"

void UMineverseOpenCoreConsumerSensorAdapter::InitialiseSensor_Implementation()
{
    LastReading.SensorType = GetSensorType_Implementation();
    bReady = true;
}

void UMineverseOpenCoreConsumerSensorAdapter::PerformScan_Implementation(const FVector& ScanLocation, FBitRobotRawSensorReading& OutReading)
{
    OutReading.ResourceID = 101;
    OutReading.RawSpectralData = TEXT("public-test-spectrum");
    OutReading.ScanLocation = ScanLocation;
    OutReading.ScanTimestamp = TEXT("2026-01-01T00:00:00Z");
    OutReading.SensorType = GetSensorType_Implementation();
    OutReading.SeedValue = 7;
    OutReading.VarianceDelta = 0.25;
    OutReading.ResourceName = TEXT("PublicTestResource");
    LastReading = OutReading;
}

FBitRobotRawSensorReading UMineverseOpenCoreConsumerSensorAdapter::GetLastReading_Implementation() const
{
    return LastReading;
}

bool UMineverseOpenCoreConsumerSensorAdapter::IsReady_Implementation() const
{
    return bReady;
}

FName UMineverseOpenCoreConsumerSensorAdapter::GetSensorType_Implementation() const
{
    return TEXT("PublicConsumerSensor");
}

void UMineverseOpenCoreConsumerDroneAdapter::InjectIntoBiome_Implementation(FName BiomeTag, FVector SpawnLocation)
{
    CurrentBiome = BiomeTag;
    bInjected = true;
    MissionStatus = FString::Printf(TEXT("Injected:%s:%.1f"), *BiomeTag.ToString(), SpawnLocation.Z);
}

void UMineverseOpenCoreConsumerDroneAdapter::AssignSurveyMission_Implementation(int32 ResourceID, FName BiomeTag)
{
    CurrentResourceID = ResourceID;
    CurrentBiome = BiomeTag;
    MissionStatus = TEXT("SurveyAssigned");
}

void UMineverseOpenCoreConsumerDroneAdapter::ExtractFromBiome_Implementation()
{
    bInjected = false;
    MissionStatus = TEXT("Extracted");
}

FString UMineverseOpenCoreConsumerDroneAdapter::GetMissionStatus_Implementation() const
{
    return MissionStatus;
}

bool UMineverseOpenCoreConsumerDroneAdapter::IsInjected_Implementation() const
{
    return bInjected;
}

void UMineverseOpenCoreConsumerDroneAdapter::ReportScanComplete_Implementation(int32 ResourceID, int32 QuantityObserved, bool bAnomalyDetected)
{
    CurrentResourceID = ResourceID;
    MissionStatus = FString::Printf(TEXT("Scan:%d:%d:%s"), ResourceID, QuantityObserved, bAnomalyDetected ? TEXT("review") : TEXT("accepted"));
}

void UMineverseOpenCoreConsumerUnitAdapter::RegisterWithNetwork_Implementation(const FString& NodeSignature)
{
    RegisteredNodeSignature = NodeSignature;
    bVerified = !NodeSignature.IsEmpty();
}

void UMineverseOpenCoreConsumerUnitAdapter::BroadcastResourceEvent_Implementation(int32 ResourceID, int32 Quantity, FName BiomeTag)
{
    bVerified = bVerified && ResourceID > INDEX_NONE && Quantity >= 0 && !BiomeTag.IsNone();
}

FString UMineverseOpenCoreConsumerUnitAdapter::GetNodeSignature_Implementation() const
{
    return RegisteredNodeSignature;
}

bool UMineverseOpenCoreConsumerUnitAdapter::IsNetworkVerified_Implementation() const
{
    return bVerified;
}

bool UMineverseOpenCoreConsumerCompileTest::RunCompileSmokeTest()
{
    FBitRobotRawSensorReading SensorReading;
    SensorReading.ResourceID = 101;
    SensorReading.RawSpectralData = TEXT("public-test-spectrum");
    SensorReading.ScanLocation = FVector(1.0, 2.0, 3.0);
    SensorReading.ScanTimestamp = TEXT("2026-01-01T00:00:00Z");
    SensorReading.SensorType = TEXT("PublicConsumerSensor");
    SensorReading.SeedValue = 7;
    SensorReading.VarianceDelta = 0.25;
    SensorReading.ResourceName = TEXT("PublicTestResource");

    FBiomeResourceRow BiomeRow;
    BiomeRow.BiomeTag = TEXT("PublicBiome");
    BiomeRow.ValidResourceIDs = { 101 };
    BiomeRow.BiomeDisplayName = TEXT("Public Test Biome");
    BiomeRow.BiomeDescription = TEXT("Sanitized consumer compile-test biome.");
    BiomeRow.bIsHazardous = false;

    FResourceDefinitionRow ResourceRow;
    ResourceRow.ResourceID = 101;
    ResourceRow.DisplayName = TEXT("Public Test Resource");
    ResourceRow.Rarity = TEXT("Common");
    ResourceRow.FamilyTag = TEXT("Public");
    ResourceRow.ActivityGlyph = TEXT("PT");
    ResourceRow.Description = TEXT("Sanitized consumer compile-test resource.");

    FMineverseOpenWeaponDataRow WeaponRow;
    WeaponRow.WeaponName = TEXT("PublicTestTool");
    WeaponRow.WeaponRowName = TEXT("PublicTestToolRow");
    WeaponRow.WeaponClass = EMineverseOpenWeaponClass::Rifle;
    WeaponRow.FireMode = EMineverseOpenFireMode::Single;
    WeaponRow.AnimStance = EMineverseOpenAnimStance::Rifle;
    WeaponRow.FireRate = 120.0f;
    WeaponRow.WeaponMass = 2.0f;
    WeaponRow.MuzzleOffset = FVector(10.0, 0.0, 2.0);
    WeaponRow.AimOffset = FVector(0.0, 1.0, 0.0);
    WeaponRow.AssistStrength = 0.2f;
    WeaponRow.RecoilStrength = 0.1f;
    WeaponRow.SwayMultiplier = 0.3f;

    FMineverseOpenValidationMessage ValidationMessage;
    ValidationMessage.FieldName = TEXT("ProviderId");
    ValidationMessage.Status = EMineverseOpenValidationStatus::Accepted;
    ValidationMessage.Message = TEXT("Sanitized consumer contract accepted.");

    FMineverseOpenValidationResult ValidationResult;
    ValidationResult.bAccepted = true;
    ValidationResult.Status = EMineverseOpenValidationStatus::Accepted;
    ValidationResult.ContractVersion = TEXT("0.1.0");
    ValidationResult.Messages.Add(ValidationMessage);

    FMineverseOpenIntegrationDescriptor IntegrationDescriptor;
    IntegrationDescriptor.ProviderId = TEXT("PublicProvider");
    IntegrationDescriptor.ContractName = TEXT("ConsumerCompileTest");
    IntegrationDescriptor.ContractVersion = TEXT("0.1.0");
    IntegrationDescriptor.bEnabled = true;

    const bool bSchemasValid =
        SensorReading.ResourceID == 101 &&
        BiomeRow.ValidResourceIDs.Contains(101) &&
        ResourceRow.ResourceID == SensorReading.ResourceID &&
        WeaponRow.FireRate > 0.0f &&
        ValidationResult.bAccepted &&
        ValidationResult.Messages.Num() == 1 &&
        !IntegrationDescriptor.ProviderId.IsNone();

    const bool bInterfacesReflected =
        UMineverseOpenCoreConsumerSensorAdapter::StaticClass()->ImplementsInterface(UBitRobotSensorDriverInterface::StaticClass()) &&
        UMineverseOpenCoreConsumerDroneAdapter::StaticClass()->ImplementsInterface(UDroneInterface::StaticClass()) &&
        UMineverseOpenCoreConsumerUnitAdapter::StaticClass()->ImplementsInterface(UUNITInterface::StaticClass());

    UMineverseOpenCoreConsumerSensorAdapter* SensorAdapter = NewObject<UMineverseOpenCoreConsumerSensorAdapter>();
    UMineverseOpenCoreConsumerDroneAdapter* DroneAdapter = NewObject<UMineverseOpenCoreConsumerDroneAdapter>();
    UMineverseOpenCoreConsumerUnitAdapter* UnitAdapter = NewObject<UMineverseOpenCoreConsumerUnitAdapter>();

    FBitRobotRawSensorReading ScanReading;
    SensorAdapter->InitialiseSensor_Implementation();
    SensorAdapter->PerformScan_Implementation(FVector(4.0, 5.0, 6.0), ScanReading);
    DroneAdapter->InjectIntoBiome_Implementation(TEXT("PublicBiome"), FVector::ZeroVector);
    DroneAdapter->AssignSurveyMission_Implementation(101, TEXT("PublicBiome"));
    UnitAdapter->RegisterWithNetwork_Implementation(TEXT("public-consumer-node"));
    UnitAdapter->BroadcastResourceEvent_Implementation(101, 5, TEXT("PublicBiome"));

    const bool bImplementationsValid =
        SensorAdapter->IsReady_Implementation() &&
        ScanReading.ResourceID == 101 &&
        DroneAdapter->IsInjected_Implementation() &&
        UnitAdapter->IsNetworkVerified_Implementation();

    return bSchemasValid && bInterfacesReflected && bImplementationsValid;
}
