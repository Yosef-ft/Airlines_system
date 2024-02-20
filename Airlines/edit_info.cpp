#include "edit_info.h"
#include "ui_edit_info.h"
#include "mainwindow.h"
#include <QSqlQueryModel>
#include <QDebug>

Edit_info::Edit_info(QWidget *parent, QString pass_id)
    : QMainWindow(parent)
    , ui(new Ui::Edit_info)
{
    ui->setupUi(this);
    MainWindow * home = new MainWindow(this);
    bool check = home->connect_db();

    if (check){
        QSqlQueryModel *model = new QSqlQueryModel;
        qDebug () <<"passanger id" << pass_id;
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
