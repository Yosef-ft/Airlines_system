#include "passanger.h"
#include "ui_passanger.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QSqlQuery>

Passanger::Passanger(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Passanger)
{
    ui->setupUi(this);

}

Passanger::~Passanger()
{
    delete ui;
}

void Passanger::on_login_pushButton_clicked()
{
    MainWindow * home = new MainWindow(this);
    bool check = home->connect_db();

    if (check){
        QString email = ui->email_lineEdit->text();
        QString password = ui->password_lineEdit->text();
        QSqlQuery query;
        QString sql = "Select * from passanger where email = :email and password = :password";
        query.prepare(sql);
        query.bindValue(":email", email);
        query.bindValue(":password", password);

        if (query.exec()){
            if (query.next()){
                QString passangerid = query.value("passangerid").toString();
                qDebug () << "the passanger id is" << passangerid << Qt::endl;
            }
        }
    }
    else{
        QMessageBox::critical(this, "Error", "Unable to connect to database");
    }

}


void Passanger::on_forgot_pushButton_clicked()
{
    MainWindow * home = new MainWindow(this);
    bool check = home->connect_db();

    if (check){

    }
    else{
        QMessageBox::critical(this, "Error", "Unable to connect to database");
    }
}

