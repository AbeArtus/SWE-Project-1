
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Fridge.h"
#include "Ingredient.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, const QString& username = "");
    ~MainWindow();
    void addIngredient(Ingredient ingrd);

private slots:
    void on_actionlogin_triggered();

    void on_actionRegister_triggered();

    void on_breakfastBox_stateChanged(int arg1);

    void on_lunchBox_stateChanged(int arg1);

    void on_dinnerBox_stateChanged(int arg1);

    void on_snackBox_stateChanged(int arg1);

    void on_recipeExplorer_clicked(const QModelIndex &index);

    void on_AddIngPushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Fridge myFridge;
    Ui::MainWindow *ui;
    void populateRecipeList(const QString& folderPath, int arg);
    void displayRecipe(const QString& dirPath);
    void subIngredient(Ingredient ingrd);


};

#endif // MAINWINDOW_H
