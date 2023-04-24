#ifndef FRIDGE_H
#define FRIDGE_H

#include <vector>
#include <string>
#include <string.h>
#include <fstream>
#include "Ingredient.h"
#include <iostream>


class Fridge {
    private:
        
        vector<Ingredient> myFridge;
        string name;

        int compareXCase( string s1, string s2 )
        {
            return strcasecmp( s1.c_str(), s2.c_str() );
        }  

        int searchItemHelper(Ingredient item, int low, int high) {
            int index = low + (high - low) /2;
            
            if (high < low)
                return -1*(index)-1;
            
            int compval = compareXCase(item.getName(), myFridge[index].getName());
           
            if (compval == 0) 
                return index;
            else if (compval < 0) 
                return searchItemHelper(item, low, index - 1);
            else if (compval > 0) 
                return searchItemHelper(item, index + 1, high);
            
            return -99999;
        }


    public:
    
        Fridge(string fileDirectory) {
    ifstream infile(fileDirectory);
    if (!infile.is_open()){
        // try opening file using the second file path
        ifstream infile2("usr/"+fileDirectory+".txt");
        if (!infile2.is_open()) {
            cout 
                << "Error opening file: " 
                << fileDirectory << endl;
            return;
        }
        // use the second file stream
        infile = move(infile2);
    }

    string line;

    // remove first two lines
    getline(infile, line);
    getline(infile, line);
    
    while(getline(infile, line)){
        if(infile.eof())
            break;

        istringstream lineStream(line);
        string itemname;
        double amount;
        string unit;

        
        lineStream >> itemname;
        if( !(lineStream >> amount) ) {
           addIngredient(Ingredient(itemname));
        }
        else if (lineStream >> unit) {
            addIngredient(Ingredient(itemname,amount,unit));
        }
        else {
            addIngredient(Ingredient(itemname,amount));
        }
    }
    infile.close();
}

        int size() {
            return myFridge.size();
        }

        vector<Ingredient> getIngredients() {
            return myFridge;
        }

        void addIngredient(Ingredient item) {
            if (myFridge.size() == 0) 
                myFridge.push_back(item);
            else if (searchItem(item) < 0) {
                int inx = (searchItem(item)+1)*-1;
                myFridge.insert(myFridge.begin() +inx,item);
            } else {
                myFridge.at(searchItem(item)).addAmount(item.getAmnt());
            }
        }

        Ingredient getIngredient(int index) {
            return myFridge[index];
        }

        string getString() {    
            string fridgeStr = "";
            for (int i = 0; i < myFridge.size(); i++){
                Ingredient ing = myFridge[i];
                fridgeStr.append(ing.getString());
            }
            return fridgeStr;
         
        }
        
        int searchItem(Ingredient item) {
            return searchItemHelper(item, 0 , myFridge.size() -1);
        }
};

#endif // FRIDGE_H
