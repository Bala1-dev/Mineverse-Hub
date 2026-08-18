// Copyright 2026 Emmanuel Bala
// SPDX-License-Identifier: Apache-2.0

using UnrealBuildTool;

public class MineverseOpenCore : ModuleRules
{
    public MineverseOpenCore(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new[]
            {
                "Core",
                "CoreUObject",
                "Engine"
            });
    }
}
