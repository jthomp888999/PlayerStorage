// Most basic setup from what I can tell,
// can add more logic and features anytime
class Craftable_Locker: DeployableContainer_Base
{
   override bool IsContainer()
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
};