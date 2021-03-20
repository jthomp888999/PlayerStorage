class CfgPatches
{
	class CraftableLocker
	{
		units[]=
		{ 
			"Craftable_Locker" 
		};
		
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

class CfgSlots
{
    class Slot_Gun1
    {
        name = "shoulder1";
        displayName = "shoulder1";
        ghostIcon = "shoulderleft";
        selection = "shoulder1";
    };

    class Slot_Gun2
    {
        name = "shoulder2";
        displayName = "shoulder2";
        ghostIcon = "shoulderleft";
        selection = "shoulder2";
	};
};

// Defining base class for all custom lockers
class CfgVehicles
{
	class Container_Base;
	class Craftable_Locker: Container_Base
	{
        displayName="Crafted_Locker";
		scope=2;
		descriptionShort="Simple Crafted Storage Unit";
		model="\craftable_locker\Gun_Cabinet_1\Gun_Cabinet_1_model.p3d";
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
		hiddenSelectionsTextures[]=
		{
			"\craftable_locker\Gun_Cabinet_1\data\SpecGloss\test_low_lambert1_Diffuse.paa",
		};

		attachments[]=
		{
			"Shoulder"
			"Shoulder1",
			"Shoulder2",
			"Melee",
			"Head",
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
			"WalkieTalkie"
		};

		 class GUIInventoryAttachmentsProps
		{
			class Clothing
			{
				name="Clothing";
				attachmentSlots[]=
				{
					"Head",
					"Body",
					"Legs",
					"Vest",
					"Back",
					"Headgear",
					"Mask",
					"Armband"
				};
				icon="missing";
			};
			class Accessories
			{
				name="Accessories";
				attachmentSlots[]=
				{
					"Gloves",
					"Feet",
					"Hips",
					"Eyewear",
					"WalkieTalkie"
				};
				icon="missing";
			};
			class Weapons
			{
				name="Weapons";
				attachmentSlots[]=
				{
					"Shoulder",
					"Shoulder1",
					"Shoulder2"
					"Melee",
				};
				icon="shoulderleft";
			};
		};

		class Cargo
		{
			itemsCargoSize[]={10,3};
			openable=0;
			allowOwnedCargoManipulation=1;
		};

    };

};