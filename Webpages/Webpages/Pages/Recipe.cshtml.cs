using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;

namespace SWEProject.Pages
{
    public class RecipeModel : PageModel
    {

        public Recipe recipe = Recipe.GetTestRecipe();
        public void OnGet()
        {
        }

    }
    public class Recipe
    {
        public string Name { get; set; }
        public string Description { get; set; }
        public List<string> Ingredients { get; set; }
        public string Directions { get; set; }
        public static Recipe GetTestRecipe()
        {
            return new Recipe()
            {
                Name = "Breakfast Burritos",
                Description = "Make this breakfast wrap on mornings when you're in a hurry and don't have time to sit and eat. Even better. Make it a night before and pop it in the microwave for about 30 sec.",
                Ingredients = new List<string> { " 1 Cooking_Spray", "2 item" },
                Directions = "Coat a medium-sized skill"
            };
        }
    }
}
