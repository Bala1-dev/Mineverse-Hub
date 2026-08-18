// Copyright 2026 Emmanuel Bala
// SPDX-License-Identifier: Apache-2.0

#include "MineverseOpenValidationTypes.h"

namespace MineverseOpenCoreConsumerHeaderChecks
{
    FMineverseOpenValidationResult MakeValidationResult()
    {
        FMineverseOpenValidationResult Result;
        Result.Status = EMineverseOpenValidationStatus::Accepted;
        return Result;
    }
}
