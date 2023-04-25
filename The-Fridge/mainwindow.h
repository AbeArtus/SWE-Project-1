
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

private slots:
    void on_actionlogin_triggered();

    void on_actionRegister_triggered();

    void on_breakfastBox_stateChanged(int arg1);

    void on_lunchBox_stateChanged(int arg1);

    void on_dinnerBox_stateChanged(int arg1);

    void on_snackBox_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
    void populateRecipeList(const QString& folderPath, int arg);

};

#endif // MAINWINDOW_H
