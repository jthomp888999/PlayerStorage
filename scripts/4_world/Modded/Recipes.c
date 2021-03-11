modded class PluginRecipesManager 	// modded keyword for modding existing class
{
	override void RegisterRecipies()	// overriding existing function
	{
		super.RegisterRecipies();			// call the original jump function so we don't break stuff
		
		RegisterRecipe(new CraftLocker);	// our modded recipe
	}
}