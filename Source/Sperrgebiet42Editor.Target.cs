// Niclas Schad, Loic Fernau, Tim Zachow

using UnrealBuildTool;
using System.Collections.Generic;

public class Sperrgebiet42EditorTarget : TargetRules
{
	public Sperrgebiet42EditorTarget(TargetInfo Target)
	{
		Type = TargetType.Editor;
	}

	//
	// TargetRules interface.
	//

	public override void SetupBinaries(
		TargetInfo Target,
		ref List<UEBuildBinaryConfiguration> OutBuildBinaryConfigurations,
		ref List<string> OutExtraModuleNames
		)
	{
		OutExtraModuleNames.AddRange( new string[] { "Sperrgebiet42" } );
	}
}
