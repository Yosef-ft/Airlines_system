#include "book.h"
#include "ui_book.h"
#include <ctime>
#include <cstdlib>
#include <string>
#include <QTime>
#include <QDate>
#include <QDebug>

std::string Book::ticketid()
{
    std::string id;
    srand(time(NULL));
    for (int i = 0; i< 4; i++){
        char start = (rand() % 10) + 65;
        id += start;
    }
    for (int i = 0; i<4; i++){
        int end = (rand() % 10);
        id += std::to_string(end);
    }
    return id;
}

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
    id = ticketid();
    QTime time_value = ui->timeEdit->time();
    QDate date_value = ui->dateEdit->date();

    date = date_value.toString("yyyy-MM-dd");
    time_departure = time_value.toString("hh-mm:ss AP");
    source = ui->source_comboBox->currentText();
    destination = ui->destination_comboBox->currentText();
    qDebug () << id << " " << date << " " << time_departure << " " << source << " " << destination;

}


void Book::on_book_I_pushButton_clicked()
{
    id = ticketid();
    QTime time_value = ui->international_timeEdit->time();
    QDate date_value = ui->international_dateEdit->date();

    date = date_value.toString("yyyy-mm-dd");
    time_departure = time_value.toString("hh:mm:ss AP");
    source = ui->source_I_comboBox->currentText();
    destination = ui->destination_I_comboBox->currentText();
    qDebug () << id << " " << date << " " << time_departure << " " << source << " " << destination;
}

