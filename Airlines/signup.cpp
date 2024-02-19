#include "signup.h"
#include "ui_signup.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>

SignUp::SignUp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SignUp)
{
    ui->setupUi(this);

}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_submit_pushButton_clicked()
{

    MainWindow * home = new MainWindow(this);
    bool check = home->connect_db();

    if (check){
        ui->statusbar->showMessage("connected to database");

        QSqlQuery query;
        query.prepare("Insert into Passanger (full_name, age, gender, email, password, forgot_email_data) "
                      "Values (:name, :age, :gender, :email, :password, :data)");
        query.bindValue(":name", ui->name_lineEdit->text());
        query.bindValue(":age", ui->age_lineEdit->text());
        query.bindValue(":gender",ui->gender_comboBox->currentText());
        query.bindValue(":email", ui->email_lineEdit->text());
        query.bindValue(":password", ui->password_lineEdit->text());
        query.bindValue(":data", ui->security_lineEdit->text());

        if(query.exec()){
            QMessageBox::information(this, "Saved", "Data has been successfully saved to database");
            home->show();
            this->hide();
        }
        else{
            //error message
            QMessageBox::information(this,"Error", query.lastError().text());

        }

    }
    else{
        ui->statusbar->showMessage("Unable to connect to database", 100);
    }



}

