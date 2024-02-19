#ifndef SIGNUP_H
#define SIGNUP_H

#include <QMainWindow>

namespace Ui {
class SignUp;
}

class SignUp : public QMainWindow
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();

private slots:
    void on_submit_pushButton_clicked();

private:
    Ui::SignUp *ui;
};

#endif // SIGNUP_H
