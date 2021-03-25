class ActionOpenStorage: ActionInteractBase
{
    void ActionOpenStorage()
    {
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
        m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
        m_HUDCursorIcon = CursorIcons.OpenHood;
    }

    override string GetText()
    {
        return "Show Inventory";
    }

    override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
    {
        Object target_object = target.GetObject();
        if ( target_object.IsItemBase() )
        {
            PlayerStorage playerStorage = PlayerStorage.Cast( target_object );
            if( playerStorage )
            {
                if( !playerStorage.IsOpen() )
                {
                    return true;
                }
            }
        }
        return false;
    }

    override void OnExecuteServer( ActionData action_data )
    {
        PlayerStorage playerStorage = PlayerStorage.Cast( action_data.m_Target.GetObject() );
        if ( playerStorage )
        {
            playerStorage.Open();
        }
    }

  	override void OnStartClient( ActionData action_data )
	{
        PlayerStorage playerStorage = PlayerStorage.Cast( action_data.m_Target.GetObject() );
	}
   
    override void OnEndServer( ActionData action_data )
    {
        Object target_object = action_data.m_Target.GetObject();
        PlayerStorage ntarget = PlayerStorage.Cast( target_object );
        if( ntarget )
        {
            ntarget.SoundSynchRemoteReset();
        }
    }
}

class ActionCloseStorage: ActionInteractBase
{
	void ActionCloseStorage()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_HUDCursorIcon = CursorIcons.CloseHood;
	}

	override string GetText()
	{
		return "Hide Inventory";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object target_object = target.GetObject();
		if ( target_object.IsItemBase() )
		{
			PlayerStorage ntarget = PlayerStorage.Cast( target_object );
			if( ntarget )
			{
				if ( ntarget.IsOpen() )
				{
					return true;
				}
			}
		}
		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		Object target_object = action_data.m_Target.GetObject();
		PlayerStorage ntarget = PlayerStorage.Cast( target_object );
		
		if( ntarget )
		{
			ntarget.Close();
		}
	}
	
	override void OnEndServer( ActionData action_data )
	{
		Object target_object = action_data.m_Target.GetObject();
		PlayerStorage ntarget = PlayerStorage.Cast( target_object );
		if( ntarget )
		{
			ntarget.SoundSynchRemoteReset();
		}
	}
}