class CfgPatches
{
	class Craftable_locker
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"dz_Data"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Container_Base;
	class WorldContainer_Base;
	class Craftable_Locker_Color_Base: Container_Base
	{
        displayName="Crafted_Locker";
		descriptionShort="simple_crafted_locker";
		model="\dz\structures\furniture\cases\locker\locker_closed_blue_v1.p3d";
		weight=10000;
		itemSize[]={5,15};
		itemBehaviour=0;
		stackedUnit="ml";
		randomQuantity=2;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=200000;
		absorbency=0;
		physLayer="item_large";
		allowOwnedCargoManipulation=1;

        class Cargo
		{
			itemsCargoSize[]={10,15};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
    };
	class Craftable_Locker_Blue: Craftable_Locker_Color_Base
	{
		scope=2;
		color="Blue"
		hiddenSelectionsTextures[]=
		{
			"\dz\structures\furniture\cases\locker\data\locker_blue_co.paa"
		};
	};

};