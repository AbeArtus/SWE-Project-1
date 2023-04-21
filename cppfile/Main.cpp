
#include <iostream>
#include <iostream>
#include "Fridge.h"


int main(){
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
}


