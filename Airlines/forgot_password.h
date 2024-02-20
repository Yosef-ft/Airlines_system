#ifndef FORGOT_PASSWORD_H
#define FORGOT_PASSWORD_H

#include <QMainWindow>

namespace Ui {
class Forgot_password;
}

class Forgot_password : public QMainWindow
{
    Q_OBJECT

public:
    explicit Forgot_password(QWidget *parent = nullptr);
    ~Forgot_password();

    QString password;

private slots:
    void on_retrive_pushButton_clicked();

private:
    Ui::Forgot_password *ui;
};

#endif // FORGOT_PASSWORD_H
