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

class CfgWeapons
{
    class RifleCore;
    class Rifle_Base: RifleCore
    {
        inventorySlot[]=
        {
            "Shoulder",
            "Shoulder1",
            "Shoulder2",
            "Shoulder3",
            "Shoulder4",

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
		hiddenSelections[]=
        {
            "camoGround"
        };
		
		hiddenSelectionsTextures[]=
		{
			"\craftable_locker\Gun_Cabinet_1\data\SpecGloss\test_low_lambert1_Diffuse.paa",
			"\craftable_locker\Gun_Cabinet_1\data\SpecGloss\test_low_lambert1_Glossiness.paa",
			"\craftable_locker\Gun_Cabinet_1\data\SpecGloss\test_low_lambert1_Height.paa",
			"\craftable_locker\Gun_Cabinet_1\data\SpecGloss\test_low_lambert1_Normal.paa",
			"\craftable_locker\Gun_Cabinet_1\data\SpecGloss\test_low_lambert1_Specular.paa"
		};

		attachments[]=
		{
			"Shoulder1",
			"Shoulder2",
			"Shoulder3",
			"Shoulder4",
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
					"Shoulder1",
					"Shoulder2",
					"Shoulder3",
					"Shoulder4",
					"Melee"
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