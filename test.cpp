
#include <iostream>

#include "Fridge.h"
#include "Recipe.h"



int main(){

    //######################//
    //# Ingredient Testing #//
    //######################//

    // Stub...
    // No Tests found
    // I mean it works though

    //#########################//
    //# Fridge search testing #//
    //#########################//

    Fridge myfrg = Fridge("abeartus");
    cout << myfrg.getString();

    Ingredient banana = Ingredient("banana", 1);
    cout << "banana index: " << myfrg.searchItem(banana) <<" \n";

    Ingredient corn = Ingredient("corn", 1);
    cout << "corn index: " << myfrg.searchItem(corn) <<" \n";

    Ingredient egg = Ingredient("egg", 1);
    cout << "egg index: " << myfrg.searchItem(egg) <<" \n";

    Ingredient milk = Ingredient("milk", 1, "gallon");
    cout << "milk index: " << myfrg.searchItem(milk) <<" \n";    
    
    Ingredient agg = Ingredient("agg", 1);
    cout << "agg index: " << myfrg.searchItem(agg) <<" \n";
    
    Ingredient bgg = Ingredient("bgg", 1);
    cout << "bgg index: " << myfrg.searchItem(bgg) <<" \n";

    Ingredient czg = Ingredient("czg", 1);
    cout << "czg index: " << myfrg.searchItem(czg) <<" \n";

    Ingredient ezg = Ingredient("ezg", 1);
    cout << "ezg index: " << myfrg.searchItem(ezg) <<" \n";

    Ingredient date = Ingredient("zate", 1);
    cout << "zear idx: " << myfrg.searchItem(date) << "\n"; 

    // Testing adding values in list
    myfrg.addIngredient(milk);
    myfrg.addIngredient(corn);
    myfrg.addIngredient(banana);
    myfrg.addIngredient(egg);

    cout << myfrg.getString();

    // Testing values not in list
    myfrg.addIngredient(agg);
    myfrg.addIngredient(bgg);
    myfrg.addIngredient(czg);
    myfrg.addIngredient(ezg);
    myfrg.addIngredient(date);
    cout << myfrg.getString();


    //#################################//
    //# Example of saving a user file #//
    //#################################//

    string usrname = "abeartus";
    string psswrd = "SWEproj00";

    // Open an out file to overwrite/create a new file for the current user info and fridge
    ofstream outfile;
    outfile.open("usr/abeartus.txt");

    outfile << usrname << endl 
            << psswrd << endl 
            << "banana 3\ncorn 3\negg 2\nmilk 2 gallon" << endl;
    
    outfile.close();

    //##################//
    //# Recipe Testing #//
    //##################//
    
    Recipe Cookie_Bars = Recipe("Chocolate_Chip_Cookie_Bars","Snack");
    cout << Cookie_Bars.getDescription() ;

    // ... need more testing for Recipe





    return 0;
}


