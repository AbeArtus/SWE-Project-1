using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using System.Xml.Linq;

namespace SWEProject.Pages
{
    public class RecipeModel : PageModel
    {
        //public Recipe recipe = Recipe.GetTestRecipe();
        public Recipe recipe;

        //public List<File> Files { get; set; }
        private IWebHostEnvironment Environment;
        public string[] filecontent, filePaths = new string[] {""};
        public RecipeModel(IWebHostEnvironment _environment)
        {
            this.Environment = _environment;
        }
        public void OnGet()
        {
            GetAllRecipePaths();
            DisplayRecipe(filePaths[1]);
        }

        public void OnGetViewRecipe(string recipeName)
        {
            GetAllRecipePaths();
            DisplayRecipe(recipeName);
        }

        public void GetAllRecipePaths()
        {
            //get all recipes
            filePaths = Directory.GetFiles(Path.Combine(
                Environment.ContentRootPath, "App_Data/DemoUser/Breakfast/"));
        }

        public void DisplayRecipe(string recipePath)
        {
            filecontent = System.IO.File.ReadAllLines(recipePath);
            recipe = new Recipe(filecontent);
        }
    }
    public class Recipe
    {
        public string Name { get; set; }
        public string Description { get; set; }
        public List<string> Ingredients { get; set; }
        public List<string> Directions { get; set; }
        public static Recipe GetTestRecipe()
        {
            return new Recipe(new string[]{ " 1 Cooking_Spray", "2 item" })
            {
                Name = "Breakfast Burritos",
                Description = "Make this breakfast wrap on mornings when you're in a hurry and don't have time to sit and eat. Even better. Make it a night before and pop it in the microwave for about 30 sec.",
                Ingredients = new List<string> { " 1 Cooking_Spray", "2 item" },
                Directions = new List<string> { "Coat a medium-sized skill" }
            };
        }

        /// <summary>
        /// Creates a recipe from a .txt file.
        /// </summary>
        /// <param name="fileContent"></param>
        public Recipe(string[] fileContent)
        {
            Name = fileContent[0];
            Description = fileContent[6];
            Ingredients = new List<string>();
            int i = 8;
            for (int k = i; k < fileContent.Length; k++)
            {
                if (fileContent[k].StartsWith("#"))
                {
                    i = k + 1;
                    break;
                }
                Ingredients.Add(fileContent[k].Replace('_', ' '));
            }
            Directions = new List<string>();
            for(int j = i; j < fileContent.Length; j++)
            {
                Directions.Add(fileContent[j]);
            }
        }
    }
}
