
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "login.h"
#include "signup.h"
#include <qdebug.h>
#include "Fridge.h"
#include <QFile>
#include <QDir>
#include <QFileInfo>
#include <QStringList>
#include <QListView>
#include <QStringListModel>

MainWindow::MainWindow(QWidget *parent, const QString& username)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //User has logged in
    if(username != ""){
        QString fileName = username + ".txt";

        // Get the parent directory of the current directory
        QDir parentDir(QCoreApplication::applicationDirPath());
        parentDir.cdUp();

        // Append the "usr" directory and the file name to the parent directory path
        QString filePath = parentDir.filePath("The-Fridge/usr/" + fileName);
        QFile file(filePath);
        Fridge myFridge = Fridge(filePath.toStdString());

        //Fridge Widget Config
        QTableWidget *myFridgeTable = ui->fridgeTable;

        myFridgeTable->setRowCount(myFridge.size());
        myFridgeTable->setColumnCount(2);
        ui->fridgeTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        //Fill fridge widget
        for(int i = 0; i < myFridge.size(); i++){
            Ingredient ingredient = myFridge.getIngredient(i);
            QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString(ingredient.getName()));
            QTableWidgetItem *count = new QTableWidgetItem(QString::number(ingredient.getAmnt()));

            myFridgeTable->setItem(i, 0, item);
            myFridgeTable->setItem(i, 1, count);
        }
    }
}

MainWindow::~MainWindow()
{
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
    populateRecipeList("The-Fridge/Recipes/SnackBox", arg1);
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

