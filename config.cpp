class CfgPatches
{
	class CraftableLocker
	{
		requiredAddons[] =
		{
			"DZ_Data"
		};
	};
};

class CfgMods
{
	class CraftableLocker
	{
		type = "mod";
		class defs
		{
			class worldScriptModule
			{
				value="";
				files[] = 
				{
					"craftable_locker/scripts/Common",
					"craftable_locker/scripts/4_World"
				};
			};
		};
	};
};


// Defining base class for all custom lockers
class CfgVehicles
{
	class Barrel_ColorBase;
	class Inventory_Base;
	class Container_Base;
	class Craftable_Locker: Container_Base
	{
        displayName="Crafted_Locker";
		scope=2;
		descriptionShort="Simple Crafted Locker";
		color="Blue";
		model="\dz\structures\furniture\cases\locker\locker_closed_blue_v1.p3d";
		weight=10000;
		itemSize[]={5,15};
		itemBehaviour=2;
		canBeDigged = 0;
        heavyItem = 1;
        physLayer = "item_large";
        bounding = "BSphere";
        carveNavmesh = 1;
        slopeTolerance = 0.2;
        yawPitchRollLimit[] = {12,12,12};
        placement = "ForceSlopeOnTerrain";
		allowOwnedCargoManipulation=1;
		hiddenSelections[]=
        {
            "camoGround"
        };
		
		hiddenSelectionsTextures[]=
		{
			"\dz\structures\furniture\cases\locker\data\locker_blue_co.paa"
		};

		attachments[]=
		{
			"Head",
			"Shoulder",
			"Melee",
			"Headgear",
			"Mask",
			"Eyewear",
			"Gloves",
			"Armband",
			"Vest",
			"Body",
			"Back",
			"Hips",
			"Legs",
			"Feet",
			"WalkieTalkie",
			"tripWireAttachment"
		};

        class Cargo
		{
			itemsCargoSize[]={10,3};
			openable=0;
			allowOwnedCargoManipulation=1;
		};

    };

};