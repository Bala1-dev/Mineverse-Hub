// Copyright 2026 Emmanuel Bala
// SPDX-License-Identifier: Apache-2.0

#include "MineverseOpenCoreConsumerCompileTest.h"

#if WITH_DEV_AUTOMATION_TESTS
#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FMineverseOpenCoreConsumerContractsTest,
    "Mineverse.OpenCore.Consumer.Contracts",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FMineverseOpenCoreConsumerContractsTest::RunTest(const FString& Parameters)
{
    TestTrue(TEXT("consumer compile smoke test succeeds"), UMineverseOpenCoreConsumerCompileTest::RunCompileSmokeTest());
    TestNotNull(TEXT("sensor interface is reflected"), UBitRobotSensorDriverInterface::StaticClass());
    TestNotNull(TEXT("drone interface is reflected"), UDroneInterface::StaticClass());
    TestNotNull(TEXT("UNIT interface is reflected"), UUNITInterface::StaticClass());
    TestTrue(TEXT("sensor adapter implements the public sensor contract"), UMineverseOpenCoreConsumerSensorAdapter::StaticClass()->ImplementsInterface(UBitRobotSensorDriverInterface::StaticClass()));
    TestTrue(TEXT("drone adapter implements the public drone contract"), UMineverseOpenCoreConsumerDroneAdapter::StaticClass()->ImplementsInterface(UDroneInterface::StaticClass()));
    TestTrue(TEXT("UNIT adapter implements the public UNIT contract"), UMineverseOpenCoreConsumerUnitAdapter::StaticClass()->ImplementsInterface(UUNITInterface::StaticClass()));
    return true;
}
#endif
