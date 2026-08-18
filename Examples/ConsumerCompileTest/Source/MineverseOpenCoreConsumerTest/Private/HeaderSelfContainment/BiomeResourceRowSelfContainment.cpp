// Copyright 2026 Emmanuel Bala
// SPDX-License-Identifier: Apache-2.0

#include "BiomeResourceRow.h"

namespace MineverseOpenCoreConsumerHeaderChecks
{
    FBiomeResourceRow MakeBiomeResourceRow()
    {
        FBiomeResourceRow Row;
        Row.BiomeTag = TEXT("PublicBiome");
        return Row;
    }
}
