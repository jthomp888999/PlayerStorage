modded class Hologram
{
    override string ProjectionBasedOnParent()
    {
        ItemBase item_in_hands = ItemBase.Cast(m_Player.GetHumanInventory().GetEntityInHands());

        if (item_in_hands.IsInherited(PlayerStorage_Kit))
            return "PlayerStorage_Holo";

        return super.ProjectionBasedOnParent();
    }
};