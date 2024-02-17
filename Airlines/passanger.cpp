#include "passanger.h"
#include "ui_passanger.h"

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
