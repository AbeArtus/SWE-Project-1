
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "login.h"
#include "signup.h"


MainWindow::MainWindow(QWidget *parent, const QString& username)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionlogin_triggered()
{
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

