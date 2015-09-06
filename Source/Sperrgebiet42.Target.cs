// Niclas Schad, Loic Fernau, Tim Zachow

using UnrealBuildTool;
using System.Collections.Generic;

public class Sperrgebiet42Target : TargetRules
{
	public Sperrgebiet42Target(TargetInfo Target)
	{
		Type = TargetType.Game;
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
