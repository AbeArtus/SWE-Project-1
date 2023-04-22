#ifndef INGREDIENT_H
#define INGREDIENT_H

// Create's an abstract Food "item"



#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Ingredient {
    private:
        string itemName;
        double amount = -1;
        string unit = "";
    public:
        Ingredient(string itNm) {
            itemName = itNm;
        }

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

        void addAmount(double val){
            amount += val;
        }

        void setUnit(string itemunit){
            unit = itemunit;
        }

        string getString() {
            stringstream ss;
            string itemStr;
             if (amount - int(amount) != 0) 
                    ss << fixed << setprecision(2) << amount;
                else
                    ss << fixed << setprecision(0) << amount;

                if (unit.compare("") != 0) 
                    itemStr = (itemName  + " " + ss.str() + " " +  unit + "\n");
                else if (amount != -1)
                    itemStr = (itemName + " " + ss.str() + "\n");
                else
                    itemStr = itemName + "\n";
                return itemStr;
        }      

};
#endif // INGREDIENT_H