using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using System.Xml.Linq;

namespace SWEProject.Pages
{
    public class RecipeModel : PageModel
    {
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
                Environment.WebRootPath, "App_Data/DemoUser/"));
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
