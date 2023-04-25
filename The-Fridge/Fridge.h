#ifndef FRIDGE_H
#define FRIDGE_H

#include <vector>
#include <string>
#include <string.h>
#include <fstream>
#include "Ingredient.h"
#include <iostream>
#include <QCoreApplication>


class Fridge {
    private:

        vector<Ingredient> myFridge;
        string name;

        int compareXCase( string s1, string s2 )
        {
            return strcasecmp( s1.c_str(), s2.c_str() );
        }




    public:

        Fridge() {
            myFridge = {};
        }


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
        infile = std::move(infile2);
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


    void saveFile(string user)
    {

        // get the original file
        // save the username and password
        // overwrite: username, passwor, fridge content

        QString fileName = QString::fromStdString(user + ".txt");

        // Get the parent directory of the current directory
        QDir parentDir(QCoreApplication::applicationDirPath());
        parentDir.cdUp();

        // Append the "usr" directory and the file name to the parent directory path
        QString filePath = parentDir.filePath("The-Fridge/usr/" + fileName);
        QFile file(filePath);
        qDebug() << filePath;
        string usrnm;
        string pswd;


        // check to see if the file is open



        // if the file does NOT exist
        if( !(file.exists()) ) {
        qDebug() << "Error Opening File: " << filePath;
            return;
        }

        // get first two lines
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            //Stream in text
            QTextStream in(&file);
            //Read first line
            usrnm = in.readLine().toStdString();
            pswd = in.readLine().toStdString();
            file.close();
        }


        // close the current file


        //--- write to the file----//
        // create a new fstream object


        if (file.open(QIODevice::WriteOnly | QIODevice::Text)){

            // add the user name and passwrod
            file.write((usrnm + "\n").c_str());
            file.write((pswd + "\n").c_str());

            // add the fridge contents

            file.write( getString().c_str() );


        } else {
        qDebug() << "Error Witing to File: " << filePath;
        }
        // close the file



    }

        int size() {
            return myFridge.size();
        }

        vector<Ingredient> getIngredients() {
            return myFridge;
        }

        void addIngredient(Ingredient item) {
            if (myFridge.size() == 0) {
                myFridge.push_back(item);
                return;
            }

            else if (searchItem(item) < 0) {
                myFridge.push_back(item);
            } else {
                myFridge.at(searchItem(item)).addAmount(item.getAmnt());
                return;
            }
        }

        Ingredient getIngredient(int index) {
            return myFridge[index];
        }

        void removeIngredient(int idx) {
            myFridge.erase(myFridge.begin() + idx);

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



            for (int i =0; i < myFridge.size(); i++) {

                if ( (compareXCase(myFridge.at(i).getName(), item.getName())) == 0
                    &&
                    compareXCase(myFridge.at(i).getUnit(), item.getUnit()) == 0 )
                return i;
            }
            return -1;
        }
};

#endif // FRIDGE_H
