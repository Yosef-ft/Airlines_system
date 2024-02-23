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

void Book::on_submit_pushButton_clicked()
{
    if (ui->local_radioButton->isChecked()){
        ui->stackedWidget->setCurrentIndex(1);
    }
    else if (ui->international_radioButton->isChecked()){
        ui->stackedWidget->setCurrentIndex(2);
    }
}


void Book::on_bookD_pushButton_clicked()
{

}


void Book::on_book_I_pushButton_clicked()
{

}

