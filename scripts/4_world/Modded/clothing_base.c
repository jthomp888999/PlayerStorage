// Thanks to Helkhiana for his ClothingInventoryFix mod

modded class Clothing extends Clothing_Base
{
	override bool CanPutInCargoClothingConditions(EntityAI parent)
	{
		bool is_hidden_stash_exception = false;
		
		if ( parent.IsInherited( UndergroundStash ) )
			is_hidden_stash_exception = true;
		
		if ( GetNumberOfItems() == 0 || is_hidden_stash_exception )
		{
			EntityAI cargoParent = parent.GetHierarchyParent();
			ClothingBase parentClothing = ClothingBase.Cast(parent);
			if (cargoParent && parentClothing)
				return !(parent.IsClothing() && cargoParent.IsClothing()));			
			return true;
		}
		
		return false;
	}

	override bool CanReceiveItemIntoCargoClothingConditions(EntityAI item)
	{
		if (GetInventory().IsInCargo())
			return false;
		return true;
	}

	override bool CanLoadItemIntoCargoClothingConditions(EntityAI item)
	{		
		if (GetInventory().IsInCargo())
			return false;
		return true;
	}
};