using UnrealBuildTool;
using System.Collections.Generic;

public class FlowControlTarget : TargetRules
{
	public FlowControlTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "FlowControl" } );
	}
}
