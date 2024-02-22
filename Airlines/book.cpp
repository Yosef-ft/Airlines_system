#include "book.h"
#include "ui_book.h"

Book::Book(QWidget *parent, QString pass_id)
    : QMainWindow(parent)
    , ui(new Ui::Book)
{
    ui->setupUi(this);
}

Book::~Book()
{
    delete ui;
}
