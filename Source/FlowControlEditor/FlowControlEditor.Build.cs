using UnrealBuildTool;

public class FlowControlEditor : ModuleRules
{
	public FlowControlEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "ApplicationCore",
            "Engine",
            "Slate",
            "UnrealEd",
            "EditorScriptingUtilities",
            "FlowControl",
            "BlueprintGraph",
            "Kismet",
            "KismetCompiler"
        });

		PrivateDependencyModuleNames.AddRange(new string[] {
            "InputCore",
            "SlateCore",
            "PropertyEditor",
            "LevelEditor",
            "RenderCore"
        });

        DynamicallyLoadedModuleNames.AddRange(
             new string[] {
             }
        );
    }
}
