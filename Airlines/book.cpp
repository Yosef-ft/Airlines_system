#include "book.h"
#include "ui_book.h"
#include <ctime>
#include <cstdlib>
#include <string>
#include <QTime>
#include <QDate>
#include <QDebug>
#include <QMessageBox>
#include <string>

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
    time_departure = time_value.toString("hh:mm:ss AP");
    source = ui->source_comboBox->currentText();
    destination = ui->destination_comboBox->currentText();
    QTime a_time = time_value.addSecs(2 * 3600);
    time_arrival = a_time.toString("hh:mm:ss AP");
    ui->arrival_label->setText(time_arrival);
    airlines = ui->airlinesD_comboBox->currentText();
    if (ui->classD_comboBox->currentText() == "Economy class"){
        seat = "EC-";
    }
    else if (ui->classD_comboBox->currentText() == "Business class"){
        seat = "BC-";
    }
    else{
        seat = "FC-";
    }
    int luggage = ui->luggageD_lineEdit->text().toInt();
    int price = 300 + 100 * luggage;
    QMessageBox::information(this, "Price", ("Your ticket price is " + std::to_string(price)).c_str() );
    qDebug () << id << " " << date << " " << time_departure << " " << source << " " << destination << time_arrival << " "
             << airlines << " " << seat;

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
    QTime a_time = time_value.addSecs(2 * 3600);
    time_arrival = a_time.toString("hh:mm:ss AP");
    ui->arrival_I_label->setText(time_arrival);
    airlines = ui->airlines_I_comboBox->currentText();
    if (ui->classD_comboBox->currentText() == "Economy class"){
        seat = "EC-";
    }
    else if (ui->classD_comboBox->currentText() == "Business class"){
        seat = "BC-";
    }
    else{
        seat = "FC-";
    }
    int luggage = ui->lug_I_lineEdit->text().toInt();
    int price = 300 + 100 * luggage;
    QMessageBox::information(this, "Price", ("Your ticket price is " + std::to_string(price)).c_str() );
    qDebug () << id << " " << date << " " << time_departure << " " << source << " " << destination << time_arrival << " "
             << airlines << " " << seat;
}

