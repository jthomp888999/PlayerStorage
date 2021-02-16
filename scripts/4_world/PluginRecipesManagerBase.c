modded class PluginRecipesManagerBase extends PluginBase	// modded keyword for modding existing class
{
	override void RegisterRecipes())	// overriding existing function
	{
		super.RegisterRecipes();			// call the original jump function so we don't break stuff
		RegisterRecipe(new CraftLocker);	// our modded recipe
	}
}