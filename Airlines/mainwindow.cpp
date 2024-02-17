#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QSqlDatabase>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    bool ok = connect_db();
    if(ok) {
        qDebug () << "Database connected" << Qt::endl;
    }
    else
        qDebug() << "Unable to connect database" << Qt::endl;

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
