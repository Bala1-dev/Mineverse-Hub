// Copyright 2026 Emmanuel Bala
// SPDX-License-Identifier: Apache-2.0

#include "BitRobotSensorTypes.h"

namespace MineverseOpenCoreConsumerHeaderChecks
{
    FBitRobotRawSensorReading MakeSensorReading()
    {
        FBitRobotRawSensorReading Reading;
        Reading.SensorType = TEXT("PublicConsumerSensor");
        return Reading;
    }
}
