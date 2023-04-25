
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "login.h"
#include "signup.h"
#include <qdebug.h>
#include "Fridge.h"
#include <QFile>
#include <Qdir>


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
        ui->fridgeTable->setEditTriggers(QAbstractItemView::DoubleClicked);
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

