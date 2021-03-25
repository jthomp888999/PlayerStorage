// Most basic setup from what I can tell,
// can add more logic and features anytime
class PlayerStorage: DeployableContainer_Base
{
	protected ref OpenableBehaviour m_OPOpenable;

	void PlayerStorage()
    {   
        m_OPOpenable = new OpenableBehaviour(false);
        RegisterNetSyncVariableBool("m_OPOpenable.m_IsOpened");
        RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
        RegisterNetSyncVariableBool("m_IsPlaceSound");
    }

	override void EEInit()
    {
        super.EEInit();
        GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);
    }

	override void Open()
    {
        m_OPOpenable.Open();
        GetInventory().UnlockInventory(HIDE_INV_FROM_SCRIPT);
        SoundSynchRemote();
    }

	override void Close()
    {
        m_OPOpenable.Close();
        GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);
        SoundSynchRemote();
    }

	override bool IsOpen()
    {
        return m_OPOpenable.IsOpened();
    }

	override bool CanPutInCargo( EntityAI parent )
	{
        return IsOpen();
	}

	override void OnVariablesSynchronized()
    {
        super.OnVariablesSynchronized();
                
        if ( IsPlaceSound() )
        {
            PlayPlaceSound();
        }
        else
        {
            if ( IsOpen() && IsSoundSynchRemote() && !IsBeingPlaced() )
            {
                SoundBarrelOpenPlay();
            }
            
            if ( !IsOpen() && IsSoundSynchRemote() && !IsBeingPlaced() )
            {
                SoundBarrelClosePlay();
            }
        }   
    }

	void SoundBarrelOpenPlay()
	{
		EffectSound sound =	SEffectManager.PlaySound( "barrel_open_SoundSet", GetPosition() );
		sound.SetSoundAutodestroy( true );
	}

	void SoundBarrelClosePlay()
	{
		EffectSound sound =	SEffectManager.PlaySound( "barrel_close_SoundSet", GetPosition() );
		sound.SetSoundAutodestroy( true );
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
		AddAction(ActionCloseStorage);
        AddAction(ActionOpenStorage);
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