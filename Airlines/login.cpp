#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent, QString passanger_id)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}
