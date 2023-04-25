/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QLabel *LoginLabel;
    QGroupBox *groupBox;
    QLineEdit *usr_lnEdt;
    QLabel *UsrLabel;
    QLabel *passwordLabel;
    QLineEdit *Pss_lnEdt;
    QPushButton *loginButton;
    QLabel *loginHelp;

    void setupUi(QDialog *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName("login");
        login->resize(400, 300);
        LoginLabel = new QLabel(login);
        LoginLabel->setObjectName("LoginLabel");
        LoginLabel->setGeometry(QRect(10, 10, 361, 31));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setUnderline(true);
        LoginLabel->setFont(font);
        LoginLabel->setAlignment(Qt::AlignCenter);
        groupBox = new QGroupBox(login);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(20, 40, 351, 241));
        usr_lnEdt = new QLineEdit(groupBox);
        usr_lnEdt->setObjectName("usr_lnEdt");
        usr_lnEdt->setGeometry(QRect(30, 50, 301, 24));
        UsrLabel = new QLabel(groupBox);
        UsrLabel->setObjectName("UsrLabel");
        UsrLabel->setGeometry(QRect(30, 30, 301, 20));
        UsrLabel->setAlignment(Qt::AlignCenter);
        passwordLabel = new QLabel(groupBox);
        passwordLabel->setObjectName("passwordLabel");
        passwordLabel->setGeometry(QRect(30, 90, 301, 20));
        passwordLabel->setAlignment(Qt::AlignCenter);
        Pss_lnEdt = new QLineEdit(groupBox);
        Pss_lnEdt->setObjectName("Pss_lnEdt");
        Pss_lnEdt->setGeometry(QRect(30, 120, 301, 24));
        loginButton = new QPushButton(groupBox);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(110, 160, 131, 24));
        loginHelp = new QLabel(groupBox);
        loginHelp->setObjectName("loginHelp");
        loginHelp->setGeometry(QRect(70, 210, 211, 16));

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QDialog *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "Dialog", nullptr));
        LoginLabel->setText(QCoreApplication::translate("login", "LOGIN", nullptr));
        groupBox->setTitle(QCoreApplication::translate("login", "signIn", nullptr));
        UsrLabel->setText(QCoreApplication::translate("login", "Username", nullptr));
        passwordLabel->setText(QCoreApplication::translate("login", "Password", nullptr));
        loginButton->setText(QCoreApplication::translate("login", "login", nullptr));
        loginHelp->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
