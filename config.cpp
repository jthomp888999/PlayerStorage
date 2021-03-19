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
        ghostIcon = "hips";
        selection = "shoulder1";

    };

    class Slot_Gun2
    {

        name = "shoulder2";
        displayName = "shoulder2";
        ghostIcon = "hips";
        selection = "shoulder2";

    };

	class Slot_Gun3
    {

        name = "shoulder3";
        displayName = "shoulder3";
        ghostIcon = "hips";
        selection = "shoulder3";

    };

	class Slot_Gun4
    {

        name = "shoulder4";
        displayName = "shoulder4";
        ghostIcon = "hips";
        selection = "shoulder4";
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
			
		};
		
		hiddenSelectionsTextures[]=
		{
			"\craftable_locker\Gun_Cabinet_1\data\SpecGloss\test_low_lambert1_Diffuse.paa",
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
					"Mask",
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
				};
				icon="shoulderright";
				
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