#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include "login.h"

namespace Ui {
class signup;
}

class signup : public QDialog
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = nullptr);
    ~signup();

private slots:
    void on_signupButton_clicked();

private:
    Ui::signup *ui;
    login *Login;
};

#endif // SIGNUP_H
