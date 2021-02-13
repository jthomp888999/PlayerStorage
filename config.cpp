class CfgPatches
{
	class DZ_Gear_Containers
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Container_Base;
	class WorldContainer_Base;
	class Craftable_Locker: Container_Base
	{
        displayName="Crafted_Locker";
		descriptionShort="simple_crafted_locker";
		model="\dz\structures\furniture\cases\locker\locker_closed_blue_v1.p3d";
		overrideDrawArea="8.0";
		forceFarBubble="true";
		slopeTolerance=0.30000001;
		destroyOnEmpty=0;
		varQuantityDestroyOnMin=0;
		quantityBar=1;
		carveNavmesh=1;
		canBeDigged=0;
		heavyItem=1;
		weight=10000;
		itemSize[]={10,15};
		itemBehaviour=0;
		stackedUnit="ml";
		randomQuantity=2;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=200000;
		absorbency=0.1;
		physLayer="item_large";
		allowOwnedCargoManipulation=1;

        class Cargo
		{
			itemsCargoSize[]={10,15};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
    }

};