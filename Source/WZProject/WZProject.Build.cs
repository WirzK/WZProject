// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class WZProject : ModuleRules
{
	public WZProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
