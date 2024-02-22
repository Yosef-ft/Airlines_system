#include "update_info.h"
#include "ui_update_info.h"
#include "mainwindow.h"
#include <QString>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include "edit_info.h"

update_info::update_info(QWidget *parent, QString pass_id)
    : QMainWindow(parent)
    , ui(new Ui::update_info)
{
    ui->setupUi(this);
    passwordId = pass_id;
}

update_info::~update_info()
{
    delete ui;
}

void update_info::on_edit_pushButton_clicked()
{
    MainWindow * home = new MainWindow(this);
    bool check = home->connect_db();

    if (check){
        QString name = ui->name_lineEdit->text();
        QString age = ui->age_lineEdit->text();
        QString email = ui->email_lineEdit->text();

        QSqlQuery query;
        query.prepare("Update Passanger set full_name = '"+name+"', age = '"+age+"', email = '"+email+"' where passangerId = '"+passwordId+"'");

        if (query.exec()){
            QMessageBox::information(this, "Saved", "Sucessfully edited your data");
            this->hide();
            Edit_info * edit = new Edit_info(this,passwordId);
            edit->show();
        }
        else{
            QMessageBox::critical(this, "Error", query.lastError().text());
        }
    }
    else{
        ui->statusbar->showMessage("Unstable connection please try again");
    }
}

