// Copyright 2026 Emmanuel Bala
// SPDX-License-Identifier: Apache-2.0

#include "MineverseOpenCore.h"

#include "Modules/ModuleManager.h"

class FMineverseOpenCoreModule final : public IModuleInterface
{
public:
    void StartupModule() override
    {
    }

    void ShutdownModule() override
    {
    }
};

IMPLEMENT_MODULE(FMineverseOpenCoreModule, MineverseOpenCore)
