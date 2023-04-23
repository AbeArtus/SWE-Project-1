/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_register
{
public:
    QLineEdit *usernamelineEdit;
    QLineEdit *passwordlineEdit;
    QLineEdit *passwrod2lineEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton;

    void setupUi(QDialog *register)
    {
        if (register->objectName().isEmpty())
            register->setObjectName("register");
        register->resize(400, 300);
        usernamelineEdit = new QLineEdit(register);
        usernamelineEdit->setObjectName("usernamelineEdit");
        usernamelineEdit->setGeometry(QRect(30, 90, 341, 24));
        passwordlineEdit = new QLineEdit(register);
        passwordlineEdit->setObjectName("passwordlineEdit");
        passwordlineEdit->setGeometry(QRect(30, 150, 341, 24));
        passwrod2lineEdit = new QLineEdit(register);
        passwrod2lineEdit->setObjectName("passwrod2lineEdit");
        passwrod2lineEdit->setGeometry(QRect(30, 210, 341, 24));
        label = new QLabel(register);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 70, 341, 20));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(register);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 130, 341, 16));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(register);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 190, 341, 16));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(register);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 10, 341, 41));
        QFont font;
        font.setPointSize(20);
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(register);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(130, 260, 151, 24));

        retranslateUi(register);

        QMetaObject::connectSlotsByName(register);
    } // setupUi

    void retranslateUi(QDialog *register)
    {
        register->setWindowTitle(QCoreApplication::translate("register", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("register", "username", nullptr));
        label_2->setText(QCoreApplication::translate("register", "password", nullptr));
        label_3->setText(QCoreApplication::translate("register", "re-enter password", nullptr));
        label_4->setText(QCoreApplication::translate("register", "Register", nullptr));
        pushButton->setText(QCoreApplication::translate("register", "Register", nullptr));
    } // retranslateUi

};

namespace Ui {
    class register: public Ui_register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
