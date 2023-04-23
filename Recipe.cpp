#include "Ingredient.h"
#include <vector>
#include <string.h>
#include <sys/stat.h>
#include <fstream>
#include <iostream>


using namespace std;

class Recipe {
    private:
        string typeDir;
    public:

        string name;                    // name of the recipe
        string servingSize[2];          // {amount, unit } EX: 2 servings
        int cookTime;                   // units in minutes 
        string description;             // brief description
        vector<Ingredient> Ingredients; // Ingredients
        string directions;              // Directions (Large String)
        
    // directories /Recipes/{Breakfast}{Lunch}{Dinner}{Snacks}{Desert}
    Recipe(string FILENAME, string dir){
        typeDir = dir;
        // open the recipe file inside given Dir
        ifstream infile("Recipes/"+ dir + "/" + FILENAME + ".txt" );
        if (!infile.is_open()){
                cout 
                    << "Error opening file: " 
                    << "~/Recipes/"+ dir + "/" + FILENAME + ".txt"
                    << endl;
                return;
        }
        string line;

        // get name of the recipe
        getline(infile, name);
        getline(infile, line); // load #

        
        // Get the serving size
        getline(infile, line);
        istringstream lineStream(line);
        lineStream >> servingSize[0]>>servingSize[1];
        lineStream.clear();
        getline(infile, line); // load #
        
        // Get Cook Time
        getline(infile, line);
        lineStream.str(line);   // load into stream
        lineStream >> cookTime; // extract the integer
        lineStream.clear();     // clear remaining "min" (its assumed)
        getline(infile, line);  // remove load #
        getline(infile, line);  // remove remove # from stream

        // get the description
        while(line != "#"){
            description.append(line);
            getline(infile, line);
        }
        
        // Get ingredients
        getline(infile, line);
        while(line != "#"){
            istringstream lineStream(line);
            string itemname;
            double amount;
            string unit;

            lineStream >> itemname;
            if( !(lineStream >> amount) ) 
                Ingredients.push_back(Ingredient(itemname));
            else if (!(lineStream >> unit))
                Ingredients.push_back(Ingredient(itemname,amount));
            else 
                Ingredients.push_back(Ingredient(itemname,amount,unit));
            getline(infile, line);

            lineStream.clear();
        }
        while(getline(infile, line)){
            directions.append(line + "\n");
        }
    }
        
    string getIngredientString() {
        string item;
        for (int i = 0; i < Ingredients.size();i++)
            item.append(Ingredients.at(i).getString());
        return item;
    }

    string getString() {
        string str;
        str.append(name + "\n#\n");
        str.append(servingSize[0] + " " + servingSize[1] + "\n#\n" );
        str.append(to_string(cookTime) + " min\n#\n");
        str.append(description+ "\n#\n");
        str.append(getIngredientString()+"#\n");
        str.append(directions);
        return str;
    }
    
    string replace(string str, char a, char b) {
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] == a) {
                str[i] = b;
            }
        }
            return str;


        
    }


    void updatelist(string name, string RecipeDir) {

        // get the list from the given directory
        string direc =  "Recipes/"+RecipeDir+"/~list.txt";

        ifstream infile(direc);

        // check to see if the file is opened
        if (infile.is_open()){
            // read the file to see if name exists
            vector<string> recipes;
            string line;

            while (getline(infile, line)) {
                recipes.push_back(line);
            }
            

        }
        infile.close();

    }
        


    // Constructor

    Recipe(string name, string serving, int time, string dscr, vector<Ingredient> Ings, string dirctions, string dirctry) {
        ofstream outfile;
        string flname = replace(name, ' ', '_');
        outfile.open("Recipes/"+dirctry+"/"+flname);
        outfile << "abeartus" << endl << "SWEproj00";

        outfile.close();
    }

    // Create a textfile from the parameters in the constructor
    void writeTextFile() {

        // create a text file

        fstream recipeFile;
        recipeFile.open(name, ios::out);
        if (!(recipeFile))
        {
            cout << "File not created";
        }
        else{
            // Write to the file

            // Write to the text file
            recipeFile << name;
            recipeFile << "#";
            recipeFile << servingSize;
            recipeFile << "#";
            recipeFile << cookTime;
            recipeFile << "#";
            recipeFile << description;
            recipeFile << "#";

            // loop for instruction vector
            int numIngr = Ingredients.size();
            for (int i = 0; i < numIngr; i++) {
                Ingredient current = Ingredients[i];
                recipeFile << current.getString();

                if (!(i == numIngr - 1))
                {
                    // Add a new line if it is not the last ingredient in the vector
                    recipeFile << endl;
                }

                recipeFile << "#";
                recipeFile << directions;
            }

            // Close the file
            recipeFile.close();


        }
    }


};



/*
    int main() {
        Recipe recipe = Recipe("Breakfast_Burritos", "Breakfast");
        cout << recipe.getString();

        recipe.updatelist(recipe.name, "Breakfast");
        return 0;
    }
*/