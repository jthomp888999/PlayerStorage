// Most basic setup from what I can tell,
// can add more logic and features anytime
class PlayerStorage: DeployableContainer_Base
{
   override bool IsContainer()
    {
        return true; 
    }

	override bool CanPutInCargo( EntityAI parent )
	{
		return true;
	}

    override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
    {
        super.OnPlacementComplete( player, position, orientation );
            
        SetIsPlaceSound( true );
    }

    override bool IsDeployable()
    {
        return true;
    }

    override void SetActions()
    {
        super.SetActions();
        
        AddAction(ActionTogglePlaceObject);
        AddAction(ActionPlaceObject);
    }

    override bool CanReceiveAttachment( EntityAI attachment, int slotId )
	{
		if ( GetHealthLevel() == GameConstants.STATE_RUINED )
			return false;
		
		return super.CanReceiveAttachment(attachment, slotId);
	}
	
	override bool CanLoadAttachment( EntityAI attachment )
	{
		if ( GetHealthLevel() == GameConstants.STATE_RUINED )
			return false;
		
		return super.CanLoadAttachment(attachment);
	}

	override bool CanReceiveItemIntoCargo( EntityAI item )
	{
		if ( GetHealthLevel() == GameConstants.STATE_RUINED )
			return false;

		return super.CanReceiveItemIntoCargo( item );
	}
	
	override bool CanLoadItemIntoCargo( EntityAI item )
	{
		if ( GetHealthLevel() == GameConstants.STATE_RUINED )
			return false;

		return super.CanLoadItemIntoCargo( item );
	}
};