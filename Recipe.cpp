#include "Ingredient.h"
#include <vector>
#include <string>
#include <sys/stat.h>
#include <fstream>
#include <iostream>


using namespace std;

class Recipe {
    private:
        
    public:

        string name;
        string description;
        vector<Ingredient> Ingredients;
        string directions;
        string servingSize;
        int cookTime; // units in minutes

        
        
    string getIngredientString() {
        string item;
        for (int i = 0; i < Ingredients.size();i++)
            item.append(Ingredients.at(i).getString());
        return item;
    }
    string getString() {
        string str;
        str.append(name + "\n");
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

    void updatelist(string name, string dir) {

        // get the list from the given directory
        string direc =  "Recipes/"+dir+"/~list.txt";

        ofstream directoryFile;
        directoryFile.open(direc);
        // check to see if the file is opened
        if (directoryFile.is_open()){
            // read the file to see if name exists
            string recipe;
            while (getline(directoryFile, recipe)){
                int sameName = strcmp(name, recipe);
                if (sameName ==0){
                    // the recipe is already in the file
                    cout<< " Recipe already exists"<< endl;
                    break;
                }
            }
            // Add the recipe name  if ! exists
            directoryFile << name;

        }
        directoryFile.close();

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

    writeTextFile() {

        // create a text file

        fstream recipeFile;
        recipe_file.open(name, ios::out);
        if !(recipeFile)
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
            for (int idx = 0; i < numIngr; i++) {
                Ingredient current = Ingredients[idx];
                recipeFile << current;

                if !(idx == numIngr - 1)
                {
                    // Add a new line if it is not the last ingredient in the vector
                    recipeFile << endl;
                }

                recipeFile << "#";
                recipeFile << directions;
            }

            // Close the file
            recioeFile.come();


        }
    }

    // directories /Recipes/{Breakfast}{Lunch}{Dinner}{Snacks}{Desert}
    Recipe(string FILENAME, string dir){
        ifstream infile("Recipes/"+ dir + "/" + FILENAME + ".txt" );
        if (!infile.is_open()){
                cout 
                    << "Error opening file: " 
                    << "Recipes/"+ dir + "/" + FILENAME + ".txt"
                    << " in ~/usr" << endl;
                return;
        }
        string line;

        getline(infile, name);
        getline(infile, line);
        while(line != "#"){
            description.append(line);
            getline(infile, line);
        }
        
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
        }
        while(getline(infile, line)){
            directions.append(line + "\n");
        }
    }


}


    int main() {
        Recipe recipe = Recipe("Breakfast_Burritos", "Breakfast");
        cout << recipe.getString();

        recipe.updatelist(recipe.name, "Breakfast")
        return 0;
    }