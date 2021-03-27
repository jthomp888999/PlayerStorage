// Most basic setup from what I can tell,
// can add more logic and features anytime
class PlayerStorage: Container_Base
{
	protected ref OpenableBehaviour m_OPOpenable;

    override bool CanPutInCargo( EntityAI parent )
    {
        return false;
    }
    
    override bool CanPutIntoHands(EntityAI parent)
    {
        return false;
    }

	void PlayerStorage()
    {   
        m_OPOpenable = new OpenableBehaviour(false);
        RegisterNetSyncVariableBool("m_OPOpenable.m_IsOpened");
        RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
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

    override void SetActions()
    {
        super.SetActions();
        
		AddAction(ActionCloseStorage);
        AddAction(ActionOpenStorage);
    }
};

class PlayerStorage_Holo extends PlayerStorage {};

class PlayerStorage_Kit extends ItemBase
{
    protected Object StorageKit;

    void PlayerStorage_Kit()
    {
        RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
    }

    override void EEInit()
	{
		super.EEInit();
	}

    override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
    {
        super.OnPlacementComplete( player, position, orientation );

        PlayerBase pb = PlayerBase.Cast( player );
        if ( GetGame().IsServer() )
        {
            PlayerBase player_base = PlayerBase.Cast( player );
			StorageKit = GetGame().CreateObject("PlayerStorage", pb.GetLocalProjectionPosition(), false );
			StorageKit.SetPosition( position );
			StorageKit.SetOrientation( orientation );
            this.Delete();
        }

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