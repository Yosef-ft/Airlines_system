#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QSqlDatabase>
#include <QDebug>
#include "signup.h"
#include "passanger.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    bool ok = connect_db();
    if(ok) {
        qDebug () << "Database connected" << Qt::endl;
        close_db();
    }
    else
        qDebug() << "Unable to connect database" << Qt::endl;

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_submit_pushButton_clicked()
{
    if (ui->login_radioButton->isChecked()){
        this->hide();
        Passanger * login = new Passanger(this);
        login->show();
    }
    else if (ui->signUp_radioButton->isChecked()){
        //this->hide();
        SignUp * signup = new SignUp(this);
        signup->show();
    }
}

