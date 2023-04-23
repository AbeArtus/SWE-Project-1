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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QLineEdit *Pss_lnEdt;
    QLineEdit *usr_lnEdt;
    QLabel *passwordLabel;
    QLabel *UsrLabel;
    QLabel *LoginLabel;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName("login");
        login->resize(400, 300);
        Pss_lnEdt = new QLineEdit(login);
        Pss_lnEdt->setObjectName("Pss_lnEdt");
        Pss_lnEdt->setGeometry(QRect(50, 170, 301, 24));
        usr_lnEdt = new QLineEdit(login);
        usr_lnEdt->setObjectName("usr_lnEdt");
        usr_lnEdt->setGeometry(QRect(50, 100, 301, 24));
        passwordLabel = new QLabel(login);
        passwordLabel->setObjectName("passwordLabel");
        passwordLabel->setGeometry(QRect(50, 140, 301, 20));
        passwordLabel->setAlignment(Qt::AlignCenter);
        UsrLabel = new QLabel(login);
        UsrLabel->setObjectName("UsrLabel");
        UsrLabel->setGeometry(QRect(50, 70, 301, 20));
        UsrLabel->setAlignment(Qt::AlignCenter);
        LoginLabel = new QLabel(login);
        LoginLabel->setObjectName("LoginLabel");
        LoginLabel->setGeometry(QRect(20, 20, 361, 31));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setUnderline(true);
        LoginLabel->setFont(font);
        LoginLabel->setAlignment(Qt::AlignCenter);
        label = new QLabel(login);
        label->setObjectName("label");
        label->setGeometry(QRect(48, 200, 301, 20));
        pushButton = new QPushButton(login);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(140, 230, 131, 24));

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QDialog *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "Dialog", nullptr));
        passwordLabel->setText(QCoreApplication::translate("login", "Password", nullptr));
        UsrLabel->setText(QCoreApplication::translate("login", "Username", nullptr));
        LoginLabel->setText(QCoreApplication::translate("login", "LOGIN", nullptr));
        label->setText(QString());
        pushButton->setText(QCoreApplication::translate("login", "login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
