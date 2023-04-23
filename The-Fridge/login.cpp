#include "login.h"
#include "ui_login.h"
#include <string>

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
void login::on_login_Button_released()
{
    // save the string in the line edit to usr
    std:std::string usr = ui->usr_lnEdt->text().toStdString();
    // save the password to psw
    std::string psw = ui->Pss_lnEdt->text().toStdString();

}


