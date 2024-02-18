#include "signup.h"
#include "ui_signup.h"
#include "mainwindow.h"
#include <QMessageBox>


SignUp::SignUp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SignUp)
{
    ui->setupUi(this);
    MainWindow * connector = new MainWindow(this);
    bool check = connector->connect_db();
    if (check){

    }
    else{
        ui->statusbar->showMessage("Unable to connect to database", 100);
    }
}

SignUp::~SignUp()
{
    delete ui;
}
