#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr, QString passanger_id = QString() );
    ~Login();

    QString pass_id;


private slots:
    void on_submit_pushButton_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
