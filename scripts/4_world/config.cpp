class CfgPatches		// required
{
	class TestMod
	{
		requiredAddons[]=
		{
			"DZ_Data",	// addon depedency
		};
	};
};

class CfgMods			// required in pbo's which add/modify scripts or inputs
{
	class LockerMod
	{
		type = "mod";										// required

		class defs
		{
			/*
			script module config classes are optional, define only what you want to mod
			class gameLibScriptModule
			{
				value="";
				files[]={"mods/testmod/scripts/2_GameLib"};
			};*/

			class worldScriptModule
			{
				value="lockerRecipe";
				files[]={"craftable_locker/scripts/4_World"};
			};
		};
	};
};