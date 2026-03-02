// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CPP_UE_04_Romain : ModuleRules
{
	public CPP_UE_04_Romain(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"CPP_UE_04_Romain",
			"CPP_UE_04_Romain/Variant_Horror",
			"CPP_UE_04_Romain/Variant_Horror/UI",
			"CPP_UE_04_Romain/Variant_Shooter",
			"CPP_UE_04_Romain/Variant_Shooter/AI",
			"CPP_UE_04_Romain/Variant_Shooter/UI",
			"CPP_UE_04_Romain/Variant_Shooter/Weapons"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
