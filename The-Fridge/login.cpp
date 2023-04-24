#include "login.h"
#include "ui_login.h"
#include <string>
#include <QMessageBox>
#include <QFile>
#include <QDir>

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    ui->LoginLabel->text();
}

login::~login()
{
    delete ui;
}

//TODO: This can be deleted? Corresponding code in other files to be deleted as well?
void login::on_login_Button_released()
{
    // save the string in the line edit to usr
    std:std::string usr = ui->usr_lnEdt->text().toStdString();
    // save the password to psw
    std::string psw = ui->Pss_lnEdt->text().toStdString();

}



void login::on_loginButton_clicked()
{
    //Save login information
    QString username = ui->usr_lnEdt->text();
    QString password = ui->Pss_lnEdt->text();
    QString fileName = username + ".txt";

    // Get the parent directory of the current directory
    QDir parentDir(QCoreApplication::applicationDirPath());
    parentDir.cdUp();

    // Append the "usr" directory and the file name to the parent directory path
    QString filePath = parentDir.filePath("The-Fridge/usr/" + fileName);
    QFile file(filePath);

    //Start Authentication process
    if(file.exists()){
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            //Stream in text
            QTextStream in(&file);
            //Read first line
            in.readLine();
            //Reads second line
            QString keyword = in.readLine();
            file.close();
            //If successfu
            if(password == keyword){
                QMessageBox::warning(this, "Login", "Login Successful");
                hide();
                mainWindow = new MainWindow(this, username);
                mainWindow->show();
            }
        }
    }
    else {
        QMessageBox::warning(this, "Login", "username or password is incorrect");
    }
}

