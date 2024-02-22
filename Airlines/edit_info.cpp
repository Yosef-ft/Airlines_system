#include "edit_info.h"
#include "ui_edit_info.h"
#include "mainwindow.h"
#include <QSqlQueryModel>
#include <QDebug>
#include "update_info.h"

Edit_info::Edit_info(QWidget *parent, QString pass_id)
    : QMainWindow(parent)
    , ui(new Ui::Edit_info)
{
    ui->setupUi(this);
    passangerId = pass_id;
    MainWindow * home = new MainWindow(this);
    bool check = home->connect_db();

    if (check){
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT full_name, age, email FROM passanger where passangerid = '"+ pass_id +"'");
        model->setHeaderData(0, Qt::Horizontal, tr("Name"));
        model->setHeaderData(1, Qt::Horizontal, tr("age"));
        model->setHeaderData(2, Qt::Horizontal, tr("Email"));
        ui->tableView->setModel(model);
        ui->tableView->show();
    }

}

Edit_info::~Edit_info()
{
    delete ui;
}

void Edit_info::on_edit_pushButton_clicked()
{
    update_info *update = new update_info(this, passangerId);
    this->hide();
    update->show();

}

