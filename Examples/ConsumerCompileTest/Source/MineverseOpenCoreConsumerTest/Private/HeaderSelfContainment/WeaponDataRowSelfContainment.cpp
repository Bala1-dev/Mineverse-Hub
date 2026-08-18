// Copyright 2026 Emmanuel Bala
// SPDX-License-Identifier: Apache-2.0

#include "WeaponDataRow.h"

namespace MineverseOpenCoreConsumerHeaderChecks
{
    FMineverseOpenWeaponDataRow MakeWeaponDataRow()
    {
        FMineverseOpenWeaponDataRow Row;
        Row.WeaponName = TEXT("PublicTestTool");
        return Row;
    }
}
