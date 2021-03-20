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
			"DZ_Data",
			"DZ_Scripts"
		};
	};
};

class CfgMods
{
	class CraftableLocker
	{
		type="mod";
		class defs
		{
			class worldScriptModule
			{
				value="";
				files[]=
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
	class PistolCore;
    class Rifle_Base: RifleCore
    {
        inventorySlot[]=
        {
			"Shoulder",
            "Shoulder1",
            "Shoulder2",
            "Shoulder3",
            "Shoulder4"
        };
    };

    class Pistol_Base: PistolCore
    {
        inventorySlot[]=
        {
			"Pistol",
            "Pistol1",
            "Pistol2",
            "Pistol3",
            "Pistol4"
        };
    };
};

class CfgSlots
{
    class Slot_Shoulder1
    {
        name="Shoulder1";
        displayName="Shoulder1";
        ghostIcon="shoulderleft";
		show="true";
    };

    class Slot_Shoulder2
    {
        name="Shoulder2";
        displayName="Shoulder2";
        ghostIcon="shoulderleft";
		show="true";
    };

    class Slot_Shoulder3
    {
        name="Shoulder3";
        displayName="Shoulder3";
        ghostIcon="shoulderleft";
		show="true";
    };

    class Slot_Shoulder4
    {
        name="Shoulder4";
        displayName="Shoulder4";
        ghostIcon="shoulderleft";
		show="true";
    };

    class Slot_Pistol1
    {
        name="Pistol1";
        displayName="Pistol1";
        ghostIcon="pistol";
		show="true";
    };

    class Slot_Pistol2
    {
        name="Pistol2";
        displayName="Pistol2";
        ghostIcon="pistol";
		show="true";
    };

    class Slot_Pistol3
    {
        name="Pistol3";
        displayName="Pistol3";
        ghostIcon="pistol";
		show="true";
    };

    class Slot_Pistol4
    {
        name="Pistol4";
        displayName="Pistol4";
        ghostIcon="pistol";
		show="true";
    };
};

//Pistol base class for all custom lockers
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
		canBeDigged=0;
        heavyItem=1;
        physLayer="item_large";
        bounding="BSphere";
        carveNavmesh=1;
        slopeTolerance=0.2;
        yawPitchRollLimit[]={12,12,12};
        placement="ForceSlopeOnTerrain";
		allowOwnedCargoManipulation=1;
		attachments[]=
		{
			"Shoulder",
			"Shoulder1",
			"Shoulder2",
			"Shoulder3",
			"Shoulder4",
			"Pistol",
            "Pistol1",
			"VestGrenadeA",
			"VestGrenadeB",
			"VestGrenadeC",
			"VestGrenadeD",
			"Magazine",
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

			class Rifles
			{
				name="Rifles";
				attachmentSlots[]=
				{
					"Shoulder",
					"Shoulder2",
					"Shoulder3",
					"Shoulder4"
				};
				icon="shoulderleft";
			};

			class Pistols
			{
				name="Pistols";
				attachmentSlots[]=
				{
					"Pistol",
					"Magazine"
				};
				icon="pistol";
			};

			class Explosives
			{
				name="Explosives";
				attachmentSlots[]=
				{
					"VestGrenadeA",
					"VestGrenadeB",
					"VestGrenadeC",
					"VestGrenadeD"
				};
				icon="grenade";
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