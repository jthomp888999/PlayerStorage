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

// Rifles attach to custom weapon slots
// Not having "shoulder" or "melee", breaks those slots
class cfgWeapons
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
			"Melee"
		};
	};
};

// Pistol base class for all custom lockers
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
			"Shoulder1",
			"Shoulder2",
			"Shoulder3",
			"Shoulder4",
			"Pistol",
			"VestGrenadeA",
			"VestGrenadeB",
			"VestGrenadeC",
			"VestGrenadeD",
			"Magazine",
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

			class Rifles
			{
				name="Rifles";
				attachmentSlots[]=
				{
					"Shoulder1",
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

// For when proxies are done
// class CfgNonAIVehicles
// {
// 	class ProxyAttachment;
// 	class Proxyshoulder1: ProxyAttachment
// 	{
// 		scope=2;
// 		inventorySlot="Shoulder1";
// 		model="";
// 	};
// 	class Proxyshoulder2: ProxyAttachment
// 	{
// 		scope=2;
// 		inventorySlot="Shoulder2";
// 		model="";
// 	};
// 	class Proxyshoulder3: ProxyAttachment
// 	{
// 		scope=2;
// 		inventorySlot="Shoulder3";
// 		model="";
// 	};
// 	class Proxyshoulder4: ProxyAttachment
// 	{
// 		scope=2;
// 		inventorySlot="Shoulder4";
// 		model="";
// 	};

// };

// Custom weapon slots
class CfgSlots
{
    class Slot_Gun1
	{
		name="shoulder1";
		displayName="shoulder1";
		ghostIcon="shoulderleft";
		selection="shoulder1";
	};
	class Slot_Gun2
	{
		name="shoulder2";
		displayName="shoulder2";
		ghostIcon="shoulderleft";
		selection="shoulder2";
	};
	class Slot_Gun3
	{
		name="shoulder3";
		displayName="shoulder3";
		ghostIcon="shoulderleft";
		selection="shoulder3";
	};
	class Slot_Gun4
	{
		name="shoulder4";
		displayName="shoulder4";
		ghostIcon="shoulderleft";
		selection="shoulder4";
	};
};