/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionlogin;
    QAction *actionAdd_Ingredient;
    QAction *actionEdit_Ingredient;
    QAction *actionRegister;
    QWidget *centralwidget;
    QListView *listView;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QTableWidget *fridgeTable;
    QMenuBar *menubar;
    QMenu *menuuser;
    QMenu *menuFridge;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionlogin = new QAction(MainWindow);
        actionlogin->setObjectName("actionlogin");
        actionAdd_Ingredient = new QAction(MainWindow);
        actionAdd_Ingredient->setObjectName("actionAdd_Ingredient");
        actionEdit_Ingredient = new QAction(MainWindow);
        actionEdit_Ingredient->setObjectName("actionEdit_Ingredient");
        actionRegister = new QAction(MainWindow);
        actionRegister->setObjectName("actionRegister");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        listView = new QListView(centralwidget);
        listView->setObjectName("listView");
        listView->setGeometry(QRect(360, 60, 421, 441));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 141, 41));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(360, 20, 131, 31));
        label_2->setFont(font);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(360, 510, 421, 24));
        fridgeTable = new QTableWidget(centralwidget);
        if (fridgeTable->columnCount() < 2)
            fridgeTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        fridgeTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        fridgeTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        fridgeTable->setObjectName("fridgeTable");
        fridgeTable->setGeometry(QRect(40, 61, 281, 441));
        fridgeTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        fridgeTable->verticalHeader()->setVisible(false);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuuser = new QMenu(menubar);
        menuuser->setObjectName("menuuser");
        menuFridge = new QMenu(menubar);
        menuFridge->setObjectName("menuFridge");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuuser->menuAction());
        menubar->addAction(menuFridge->menuAction());
        menuuser->addAction(actionlogin);
        menuuser->addAction(actionRegister);
        menuFridge->addAction(actionAdd_Ingredient);
        menuFridge->addAction(actionEdit_Ingredient);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionlogin->setText(QCoreApplication::translate("MainWindow", "login", nullptr));
        actionAdd_Ingredient->setText(QCoreApplication::translate("MainWindow", "Add Ingredient", nullptr));
        actionEdit_Ingredient->setText(QCoreApplication::translate("MainWindow", "Edit Ingredient", nullptr));
        actionRegister->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Fridge", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Recipe", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "cook", nullptr));
        QTableWidgetItem *___qtablewidgetitem = fridgeTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = fridgeTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Count", nullptr));
        menuuser->setTitle(QCoreApplication::translate("MainWindow", "user", nullptr));
        menuFridge->setTitle(QCoreApplication::translate("MainWindow", "Fridge", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
