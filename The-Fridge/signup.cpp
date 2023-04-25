#include "signup.h"
#include "ui_signup.h"
#include <QDir>
#include <QFile>
#include <QMessageBox>

signup::signup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
}

signup::~signup()
{
    delete ui;
}

void signup::on_signupButton_clicked()
{
    QString username = ui->signupUsername->text();
    QString password = ui->signupPassword->text();
    QString confirmPwd = ui->signupConfirmpwd->text();

    QString fileName = username + ".txt";

    QDir parentDir(QCoreApplication::applicationDirPath());
    parentDir.cdUp();

    // Append the "usr" directory and the file name to the parent directory path
    QString filePath = parentDir.filePath("The-Fridge/usr/" + fileName);
    QFile file(filePath);

    //Start Authentication process
    if(file.exists()){
        QMessageBox::warning(this, "Regiser", "username taken");
    }

    else{
        if(password == confirmPwd){
            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream out(&file);
                out << username;
                out << "\n";
                out << password;
                file.close();
                QMessageBox::warning(this, "Regiser", "Signup successful, please login");
                hide();
            }

        }
        else{
            QMessageBox::warning(this, "Regiser", "Passwords do not match");
        }
    }

}

