/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_signup
{
public:
    QLineEdit *signupUsername;
    QLineEdit *signupPassword;
    QLineEdit *signupConfirmpwd;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *signupButton;

    void setupUi(QDialog *signup)
    {
        if (signup->objectName().isEmpty())
            signup->setObjectName("signup");
        signup->resize(400, 300);
        signupUsername = new QLineEdit(signup);
        signupUsername->setObjectName("signupUsername");
        signupUsername->setGeometry(QRect(50, 100, 291, 24));
        signupPassword = new QLineEdit(signup);
        signupPassword->setObjectName("signupPassword");
        signupPassword->setGeometry(QRect(50, 160, 291, 24));
        signupConfirmpwd = new QLineEdit(signup);
        signupConfirmpwd->setObjectName("signupConfirmpwd");
        signupConfirmpwd->setGeometry(QRect(50, 220, 291, 24));
        label = new QLabel(signup);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 30, 211, 31));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(signup);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(58, 200, 271, 20));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(signup);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 140, 291, 20));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(signup);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(50, 80, 291, 20));
        label_4->setAlignment(Qt::AlignCenter);
        signupButton = new QPushButton(signup);
        signupButton->setObjectName("signupButton");
        signupButton->setGeometry(QRect(150, 260, 101, 24));

        retranslateUi(signup);

        QMetaObject::connectSlotsByName(signup);
    } // setupUi

    void retranslateUi(QDialog *signup)
    {
        signup->setWindowTitle(QCoreApplication::translate("signup", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("signup", "Sign Up", nullptr));
        label_2->setText(QCoreApplication::translate("signup", "Re-enter Password", nullptr));
        label_3->setText(QCoreApplication::translate("signup", "Password", nullptr));
        label_4->setText(QCoreApplication::translate("signup", "username", nullptr));
        signupButton->setText(QCoreApplication::translate("signup", "Signup", nullptr));
    } // retranslateUi

};

namespace Ui {
    class signup: public Ui_signup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
