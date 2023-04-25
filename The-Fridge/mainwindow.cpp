
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "login.h"
#include "signup.h"
#include <qdebug.h>
#include "Fridge.h"
#include <QFile>
#include <Qdir>
#include "Ingredient.h"
#include <QDir>
#include <QFileInfo>
#include <QStringList>
#include <QListView>
#include <QStringListModel>
#include <QMessageBox>
#include "Recipe.h"

QString usr = "";
Recipe *recipe = nullptr;

MainWindow::MainWindow(QWidget *parent, const QString& username)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->unitcomboBox->addItem("");
    ui->unitcomboBox->addItem("g");
    ui->unitcomboBox->addItem("slice");



    //User has logged in
    if(username != ""){
        usr = username;
        QString fileName = usr + ".txt";

        // Get the parent directory of the current directory
        QDir parentDir(QCoreApplication::applicationDirPath());
        parentDir.cdUp();


        // Append the "usr" directory and the file name to the parent directory path
        QString filePath = parentDir.filePath("The-Fridge/usr/" + fileName);
        QFile file(filePath);
        myFridge = Fridge(filePath.toStdString());


        //Fridge Widget Config
        ui->fridgeTable->setEditTriggers(QAbstractItemView::DoubleClicked);
        QTableWidget *myFridgeTable = ui->fridgeTable;

        myFridgeTable->setRowCount(myFridge.size());
        myFridgeTable->setColumnCount(3);
        ui->fridgeTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


        //Fill fridge widget
        for(int i = 0; i < myFridge.size(); i++){
            Ingredient ingredient = myFridge.getIngredient(i);
            QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString(ingredient.getName()));
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            QTableWidgetItem *count = new QTableWidgetItem(QString::number(ingredient.getAmnt()));
            count->setFlags(count->flags() & ~Qt::ItemIsEditable);
            QTableWidgetItem *unit = new QTableWidgetItem(QString::fromStdString(ingredient.getUnit()));
            unit->setFlags(unit->flags() & ~Qt::ItemIsEditable);



            myFridgeTable->setItem(i, 0, item);
            myFridgeTable->setItem(i, 1, count);
            myFridgeTable->setItem(i,2, unit);
        }

        //Update Table
        qApp->processEvents();
        qDebug() << "update";
        myFridgeTable->update();
        myFridgeTable->show();

    }
}

MainWindow::~MainWindow()
{
    delete recipe;
    delete ui;
}


void MainWindow::on_actionlogin_triggered()
{
        this->hide();       //hides the first main window, this instance does not have userlogin information
        login mlogin;
        mlogin.setModal(true);
        mlogin.exec();
}


void MainWindow::on_actionRegister_triggered()
{
        signup msignup;
        msignup.setModal(true);
        msignup.exec();
}


void MainWindow::on_breakfastBox_stateChanged(int arg1)
{
    populateRecipeList("The-Fridge/Recipes/Breakfast", arg1);
}

void MainWindow::on_lunchBox_stateChanged(int arg1)
{
    populateRecipeList("The-Fridge/Recipes/Lunch", arg1);
}


void MainWindow::on_dinnerBox_stateChanged(int arg1)
{
    populateRecipeList("The-Fridge/Recipes/Dinner", arg1);
}


void MainWindow::on_snackBox_stateChanged(int arg1)
{
    populateRecipeList("The-Fridge/Recipes/Snack", arg1);
}

void MainWindow::populateRecipeList(const QString& folderPath, int arg)
{
    //RecipeList Widget Config
    QListView *recipeExplorer = ui->recipeExplorer;

    // Get the parent directory of the current directory
    QDir parentDir(QCoreApplication::applicationDirPath());
    parentDir.cdUp();
    //Go to Breakfast Folder
    QString dir = parentDir.filePath(folderPath);
    QDir folder(dir);

    // Filter files by name and sort them
    QStringList filters;
    filters << "*.txt";
    folder.setNameFilters(filters);
    folder.setSorting(QDir::Name | QDir::IgnoreCase);

    // Get the list of file names
    QStringList fileNames = folder.entryList();

    // Remove file extension from file names
    for (int i = 0; i < fileNames.size(); ++i) {
        QFileInfo fileInfo(fileNames.at(i));
        fileNames.replace(i, fileInfo.baseName());
    }

    if(arg == 2){
        // Get the existing string list model
        QStringListModel *model = qobject_cast<QStringListModel*>(recipeExplorer->model());

        if(!model) {
            // If the model does not exist yet, create a new one
            model = new QStringListModel(this);
            recipeExplorer->setModel(model);
        }

        // Append the new file names to the existing list
        QStringList currentFileNames = model->stringList();
        currentFileNames.append(fileNames);
        model->setStringList(currentFileNames);
    }

    else if (arg == 0) {
        // Get the current model of the QListView
        QStringListModel *model = qobject_cast<QStringListModel*>(recipeExplorer->model());

        if (model) {
            // Remove any items that are in the fileNames list
            QStringList currentList = model->stringList();
            for (int i = 0; i < currentList.size(); ++i) {
                if (fileNames.contains(currentList[i])) {
                    currentList.removeAt(i);
                    i--;
                }
            }
            model->setStringList(currentList);
        }
    }
}


void MainWindow::on_recipeExplorer_clicked(const QModelIndex &index)
{
    //Get the itemName the user is clicking on, and add .txt to get ready to search for this file
    QString itemName = index.data(Qt::DisplayRole).toString() + ".txt";

    // Get the parent directory of the current directory
    QDir parentDir(QCoreApplication::applicationDirPath());
    parentDir.cdUp();

    // Create a list of directories to search
    QStringList dirList;
    dirList << parentDir.filePath("The-Fridge/Recipes/Breakfast");
    dirList << parentDir.filePath("The-Fridge/Recipes/Lunch");
    dirList << parentDir.filePath("The-Fridge/Recipes/Dinner");
    dirList << parentDir.filePath("The-Fridge/Recipes/Snack");

    // Check if the file exists in any of the directories
    bool found = false;
    //iterate through dirList to find where the file is
    for (const QString& dirPath : dirList) {
        QDir dir(dirPath);

        Recipe* rcp = new Recipe(itemName.toStdString(), dirPath.toStdString());
        delete recipe;
        recipe = rcp;


        if (dir.exists(itemName)) {
            found = true;

            displayRecipe(dirPath + "/" +  itemName);
            break;
        }
    }

    if (!found) {
        QMessageBox::warning(this, "Error in Search", "Recipe text file not found");
    }
}

void MainWindow::displayRecipe(const QString& dirPath){
    QFile file(dirPath);
    qDebug() << dirPath;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "error";
        return;
    }

    QString content = QString::fromUtf8(file.readAll());
    ui->recipeView->setPlainText(content);
}


void MainWindow::on_AddIngPushButton_clicked()
{
    QString name    = ui->NameQLineEdit->text();
    std::string str = name.toStdString();

    str.erase(0, str.find_first_not_of(" "));
    str.erase(str.find_last_not_of(" ") + 1);
    replace(str.begin(), str.end(), ' ', '_');

    name = QString::fromStdString(str);

    QString unit    = ui->unitcomboBox->currentText();
    double val       = ui->amtQDoubleSpinBox->value();
    if (val <= 0 || name == "")
        return;

    if (unit == "")
        addIngredient(Ingredient(name.toStdString(),val));
    else
        addIngredient(Ingredient(name.toStdString(), val, unit.toStdString()));


}

// Addd Ingredient
void MainWindow::addIngredient(Ingredient ingrd) {
    int idx = myFridge.searchItem(ingrd);
    QTableWidget *myFridgeTable = ui->fridgeTable;

    if (idx >= 0) {
        // increment the model and view by ingrd amoun at idx

        QTableWidgetItem* item = myFridgeTable->item(idx,1);

        QString text = item->text();
        std::string str = text.toStdString();
        str.erase(0, str.find_first_of(" "));
        str.erase(str.find_last_not_of(" ") + 1);
        replace(str.begin(), str.end(), ' ', '_');
        text = QString::fromStdString(str);

        double val = myFridge.getIngredient(idx).getAmnt();
        double iremval = val + (ingrd.getAmnt());
        QTableWidgetItem *count = new QTableWidgetItem(QString::number(iremval));
        myFridgeTable->setItem(idx,1, count);

        myFridge.addIngredient(ingrd);
        return;
    } else {
        // add another elemnt to the model and view (Both at the end of the list)
        idx = myFridge.size();


        QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString(ingrd.getName()));
        item->setFlags(item->flags() & ~Qt::ItemIsEditable);
        QTableWidgetItem *count = new QTableWidgetItem(QString::number(ingrd.getAmnt()));
        count->setFlags(count->flags() & ~Qt::ItemIsEditable);
        QTableWidgetItem *unit = new QTableWidgetItem(QString::fromStdString(ingrd.getUnit()));
        unit->setFlags(unit->flags() & ~Qt::ItemIsEditable);


        myFridgeTable->setRowCount(myFridge.size()+1);
        myFridgeTable->setItem(idx, 0, item);
        myFridgeTable->setItem(idx, 1, count);
        myFridgeTable->setItem(idx,2, unit);

        myFridge.addIngredient(ingrd);
    }
}

// subtract
void MainWindow::on_pushButton_2_clicked()
{

    QString name    = ui->NameQLineEdit->text();
    std::string str = name.toStdString();
    str.erase(0, str.find_first_not_of(" "));
    str.erase(str.find_last_not_of(" ") + 1);
    replace(str.begin(), str.end(), ' ', '_');
    name = QString::fromStdString(str);

    QString unit    = ui->unitcomboBox->currentText();

    double val       = ui->amtQDoubleSpinBox->value();

    Ingredient tadd = Ingredient(name.toStdString(), -1*(val), unit.toStdString());
    int idx = myFridge.searchItem(tadd);

    if  (idx <  0) {
        return;
    }
    if ( myFridge.getIngredient(idx).getAmnt() + tadd.getAmnt() <= 0 ) {
        myFridge.removeIngredient(idx);
        ui->fridgeTable->removeRow(idx);
        return;

    }

    addIngredient(tadd);
}

void MainWindow::Subtract(Ingredient ingrd) {
    int idx = myFridge.searchItem(ingrd);

    if  (idx <  0) {
        return;
    }
    if ( myFridge.getIngredient(idx).getAmnt() - ingrd.getAmnt() <= 0 ) {

        return;

    }

    addIngredient(ingrd);


}



// save button
void MainWindow::on_saveButton_clicked()
{
    myFridge.saveFile(usr.toStdString());
}

// cook button
void MainWindow::on_pushButton_clicked()
{
    if (recipe == nullptr) {
        return;
    }
    bool canCook = true;
    vector<Ingredient> recip = recipe->getIngredients();
    for (int i =0; i < recip.size(); i++) {
        if (myFridge.searchItem(recip[i]) < 0) {
            if (canCook){
                canCook = false;
                qDebug() << "Ingredient not in Fridge: " << recip[i].getName();
            }
        } else if ( myFridge.getIngredient(myFridge.searchItem(recip[i])).getAmnt() - recip[i].getAmnt() < 0 ) {
            if (canCook){
                canCook = false;
                qDebug() << "not Enough Ingredient(s) not in Fridge:" << recip[i].getName();
            }
        }
    }


    if (!(canCook))
        return;

    for (int i =0; i < recip.size(); i++) {


    }
}

