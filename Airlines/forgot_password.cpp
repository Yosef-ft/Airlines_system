#include "forgot_password.h"
#include "ui_forgot_password.h"
#include <QString>
#include "mainwindow.h"
#include <QSqlQuery>
#include <QMessageBox>
#include "passanger.h"

Forgot_password::Forgot_password(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Forgot_password)
{
    ui->setupUi(this);

}

Forgot_password::~Forgot_password()
{
    delete ui;
}

void Forgot_password::on_retrive_pushButton_clicked()
{
    MainWindow * home = new MainWindow(this);
    bool check = home->connect_db();

    if (check){
        QSqlQuery query;
        QString sql = "Select * from passanger where full_name = :name and forgot_email_data = :pet and age = :age and email = :email";
        query.prepare(sql);
        query.bindValue(":name", ui->name_lineEdit->text());
        query.bindValue(":pet", ui->security_lineEdit->text());
        query.bindValue(":age", ui->age_lineEdit->text());
        query.bindValue(":email", ui->email_lineEdit->text());

        if (query.exec()){
            if (query.next()){
                password = query.value("password").toString();
                Passanger * login = new Passanger(this);
                login->show();
                this->hide();
                QMessageBox::critical(this, "Password successfully retrieved", "Your password is " + password);
            }
        }
        else{
            QMessageBox::critical(this, "Error", "Invalid credientials! Please try again");
        }

    }
}


