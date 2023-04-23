#include "Ingredient.h"
#include <vector>
#include <string.h>
#include <sys/stat.h>
#include <fstream>
#include <iostream>


using namespace std;

class Recipe {

    private:
        string name;                    // name of the recipe
        string servingSize[2];          // {amount, unit } EX: 2 servings
        int cookTime;                   // units in minutes 
        string description;             // brief description
        vector<Ingredient> Ingredients; // Ingredients
        string directions;              // Directions (Large String)
        string typeDir;                 // Directory name of the meal type {Breakfast, Lunch, Dinner, Snack}

        int compareXCase( string s1, string s2 )
        {
            return strcasecmp( s1.c_str(), s2.c_str() );
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
                if (str[i] == a) 
                    str[i] = b;
                return str;
            } 
        }

        // this function is for adding to the -list.txt file to easily access the recipes in a dir.
        void updatelist() {
            // get the list from the given directory
            string list = "-list.txt";
            ifstream infile("Recipes/"+ typeDir + "/" + list);

            // check to see if the file is opened
            if (infile.is_open()){
                // read the file to see if name exists
                vector<string> recipes;
                string line;
                // transfer each recipe filename to the array
                while (getline(infile, line)) {
                    recipes.push_back(line);
                }
                // check if the file is already in the list
                for (int i =1; i < recipes.size(); i++) {
                    if (compareXCase(name, recipes[i]) == 0){
                        cout << "Recipe:"+ name+ ", Already in the list in Dir ~/Recipes/"+ typeDir;
                        return;
                    }
                }
                // pushback the recipe name in the vector
                recipes.push_back(name);

                // load the -list.txt file in the dir.
                ofstream outfile;
                outfile.open("Recipes/"+ typeDir +"/-list.txt");

                // cycle through the array adding each to a new line in the file
                for (int i =0; i < recipes.size(); i++)
                    outfile << recipes[i] + "\n";

                outfile.close();
            }
            infile.close();
        }

    public:        
        // directories /Recipes/{Breakfast}{Lunch}{Dinner}{Snacks}{Desert}


        /// @brief Loads in a Recipe from file, \n list of recipes can be found inside of the 'Food type directory' \n examples in definition in the -list.txt file
        /// @param FILENAME type:string | The name of the recipe to load into Recipe
        /// @param dir type:string | The food type Directory |  {Breakfast, Lunch, Dinner, Snack}
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

            // Get the directions
            while(getline(infile, line)){
                directions.append(line + "\n");
            }
        }

        
        /// @brief Creates a Recipe from collection of objects
        /// @param recipename type:string | The name of the recipe
        /// @param serving type|string[2] | The serving size [0] = {servings}, [1] {serving type} | Ex {4, Serving}
        /// @param time type:int | The cook time in minutes
        /// @param dscr type:string | The Recipe description
        /// @param Ings type:vector<Ingredient> | the vector of ingredients for the recipe
        /// @param dirctions type:string | The direction to cook the Recipe
        /// @param dirctry type:string | The Item Type Directory | {Breakfast,Lunch,Dinner,Snack}
        Recipe(string recipename, string serving[2], int time, string dscr, vector<Ingredient> Ings, string dirctions, string dirctry) {
            
        string flname = replace(recipename, ' ', '_');
            // set the obj params with the sent in function called objects
            name = flname;
            servingSize[0] = serving[0];
            servingSize[1] = serving[1];
            cookTime = time;
            description = dscr;
            directions = dirctions;
            typeDir = dirctry;
            
            ofstream outfile;

            outfile.open("Recipes/"+typeDir+"/"+name);
            outfile << getString();

            outfile.close();
            updatelist();
        }

        string getName(){
            return name;
        }

        string getServingSize(){
            return servingSize[0] +" "+ servingSize[1];
        }

        string getCookTime_min() {
            return to_string(cookTime) + " Minutes";
        }

        string getDescription(){
            return description;
        }

        string getIngredientsText(){
            string out;
            for (int i = 0; i < Ingredients.size();i++) {
                out.append(Ingredients[i].getText());
            }
        }

        vector<Ingredient> getIngredients(){
            return Ingredients;
        }


};
