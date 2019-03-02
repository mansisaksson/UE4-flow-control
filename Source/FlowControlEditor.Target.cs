using UnrealBuildTool;
using System.Collections.Generic;

public class FlowControlEditorTarget : TargetRules
{
	public FlowControlEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "FlowControl", "FlowControlEditor" } );
	}
}
