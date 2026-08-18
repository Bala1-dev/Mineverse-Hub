// Copyright 2026 Emmanuel Bala
// SPDX-License-Identifier: Apache-2.0

using UnrealBuildTool;

public class MineverseOpenCoreConsumerTest : ModuleRules
{
    public MineverseOpenCoreConsumerTest(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                "MineverseOpenCore"
            });
    }
}
