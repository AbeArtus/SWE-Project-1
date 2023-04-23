#include <iostream>
#include <strings.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <sys/stat.h>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
/*
class Ingredient {
    private:
        string itemName;
        double amount;
        string unit = "";
    public:
        Ingredient(string imNm, double amnt){
            itemName = imNm;
            amount = amnt;
        }
        Ingredient(string imNm, double amnt, string unt){
            itemName = imNm;
            amount = amnt;
            unit = unt;
        }
        string getName(){
            return itemName;
        }
        double getAmnt(){
            return amount;
        }
        string getUnit(){
            return unit;
        }
        string getString() {
            stringstream ss;
            string itemStr;
             if (amount - int(amount) != 0) 
                    ss << fixed << setprecision(1) << amount;
                else
                    ss << fixed << setprecision(0) << amount;

                if (unit.compare("") != 0) 
                    itemStr = (itemName  + " " + ss.str() + " " +  unit + "\n");
                else 
                    itemStr = (itemName + " " + ss.str() + "\n");
                return itemStr;
        }      
};
*/
/*
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
           
           
            if (compval == 0) {
                return index;
            } else if (compval < 0) {
                return searchItemHelper(item, low, index - 1);
            } else if (compval > 0) {
                return searchItemHelper(item, index + 1, high);
            }
            return -99999;
        }
    public:
        Fridge(string FILENAME) {
            ifstream infile("usr/"+FILENAME+".txt");
            if (!infile.is_open()){
                cout 
                    << "Error opening file: " 
                    << FILENAME << ".txt" 
                    << " in ~/usr" << endl;
                return;
            }
            string line;
            getline(infile, line);
            getline(infile, line);
            while(getline(infile, line)){
                if(infile.eof()){
                    break;
                }

                istringstream lineStream(line);
                string itemname;
                double amount;
                string unit;

                lineStream >> itemname >> amount;
                
                if(lineStream.fail()) {
                    cout << "Invalid input" << line << endl;
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
            else {
                int inx = (searchItem(item)+1)*-1;
                myFridge.insert(myFridge.begin() +inx,item);
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
*/




 ////////////////////////
 // Directory Creating //
 ////////////////////////

 /*
   string dir = "test";
    struct stat info;
    if(stat(dir.c_str(), &info) != 0) {
        mkdir(dir.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    }
    ofstream outfile;
    outfile.open("test/abeartus.txt");
    outfile << "abeartus" << endl << "SWEproj00";
    outfile.close();
*/


//#########################//
//# Fridge search testing #//
//#########################//

/*
    Fridge myfrg = Fridge("abeartus");
    cout << myfrg.getString();

    Ingredient egg = Ingredient("agg", 1);
    cout << "agg index: " << myfrg.searchItem(egg) <<" \n";
    
    Ingredient bgg = Ingredient("bgg", 1);
    cout << "bgg index: " << myfrg.searchItem(bgg) <<" \n";

    Ingredient czg = Ingredient("czg", 1);
    cout << "czg index: " << myfrg.searchItem(czg) <<" \n";

    Ingredient ezg = Ingredient("ezg", 1);
    cout << "ezg index: " << myfrg.searchItem(ezg) <<" \n";

    Ingredient date = Ingredient("zate", 1);
    cout << "zear idx: " << myfrg.searchItem(date) << "\n"; 


    return 0;
};
*/

