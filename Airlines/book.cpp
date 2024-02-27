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
#include "seat_no.h"
#include <QSqlQuery>
#include "mainwindow.h"
#include <QSqlError>

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
    passanger_ID = pass_id;
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
    QString seatPre;

    int luggage = ui->luggageD_lineEdit->text().toInt();
    price = 300 + 100 * luggage;

    int ret = QMessageBox::information(this, "Price", ("Your ticket price is " + std::to_string(price)).c_str(), QMessageBox::Ok | QMessageBox::Cancel );

    switch(ret){
    case QMessageBox::Ok:
        //add payment
        if (ui->classD_comboBox->currentText() == "Economy class"){
            seatPre = "EC-";
            Seat_no * seat = new Seat_no(this);
            auto ret = seat->exec();
            if (ret == QDialog::Accepted){
                QString seat_num = QString::number(seat->getSeatNO());
                seatPre += seat_num;
            }
        }
        else if (ui->classD_comboBox->currentText() == "Business class"){
            seatPre = "BC-";
            Seat_no * seat = new Seat_no(this);
            auto ret = seat->exec();
            if (ret == QDialog::Accepted){
                QString seat_num = QString::number(seat->getSeatNO());
                seatPre += seat_num;
            }
        }
        else{
            seatPre = "FC-";
            Seat_no * seat = new Seat_no(this);
            auto ret = seat->exec();
            if (ret == QDialog::Accepted){
                QString seat_num = QString::number(seat->getSeatNO());
                seatPre += seat_num;
            }
        }
        seat = seatPre;
        QMessageBox::information(this, "Successfully booked", QString("Your ticket number is %1 and your seat is %2").arg(QString::fromStdString(id)).arg(seat));
        this->hide();
        break;
    case QMessageBox::Cancel:
        QMessageBox::critical(this, "Cancelled", "Did not make payment there for couldn't book!");
        this->hide();
        break;
    }
    MainWindow * home = new MainWindow(this);
    bool check = home->connect_db();

    if (check){
        QSqlQuery query;
        query.prepare("Insert into Book values (:pass_id, :tid,:date, :source,:dest, :ta, :td, :seat, :price, :tf, :airL)");
        query.bindValue(":pass_id", passanger_ID);
        query.bindValue(":tid", QString::fromStdString(id));
        query.bindValue(":date", date);
        query.bindValue(":source", source);
        query.bindValue(":dest", destination);
        query.bindValue(":ta", time_arrival);
        query.bindValue(":td", time_departure);
        query.bindValue(":seat", seat);
        query.bindValue(":price", price);
        query.bindValue(":tf", "International");
        query.bindValue(":airL", airlines);
        if (query.exec()){
            qDebug() << "success";
        }else{
            //QMessageBox::critical(this, "error",query.lastError().text());
             qDebug () << query.lastError().text();
        }
    }else{
        qDebug () << "Unable to open the database";
    }
    qDebug () << id << " " << date << " " << time_departure << " " << source << " " << destination << time_arrival << " "
             << airlines << " " << seat;

}


void Book::on_book_I_pushButton_clicked()
{
    id = ticketid();
    QTime time_value = ui->international_timeEdit->time();
    QDate date_value = ui->international_dateEdit->date();

    date = date_value.toString("yyyy-MM-dd");
    time_departure = time_value.toString("hh:mm:ss AP");
    source = ui->source_I_comboBox->currentText();
    destination = ui->destination_I_comboBox->currentText();
    QTime a_time = time_value.addSecs(2 * 3600);
    time_arrival = a_time.toString("hh:mm:ss AP");
    ui->arrival_I_label->setText(time_arrival);
    airlines = ui->airlines_I_comboBox->currentText();
    QString seatPre;

    int luggage = ui->lug_I_lineEdit->text().toInt();
    price = 300 + 100 * luggage;


    int ret = QMessageBox::information(this, "Price", ("Your ticket price is " + std::to_string(price)).c_str(), QMessageBox::Ok | QMessageBox::Cancel );

    switch(ret){
    case QMessageBox::Ok:
        //add payment

        if (ui->classD_comboBox->currentText() == "Economy class"){
            seatPre = "EC-";
            Seat_no * seat = new Seat_no(this);
            auto ret = seat->exec();
            if (ret == QDialog::Accepted){
                QString seat_num = QString::number(seat->getSeatNO());
                seatPre += seat_num;
            }
        }
        else if (ui->classD_comboBox->currentText() == "Business class"){
            seatPre = "BC-";
            Seat_no * seat = new Seat_no(this);
            auto ret = seat->exec();
            if (ret == QDialog::Accepted){
                QString seat_num = QString::number(seat->getSeatNO());
                seatPre += seat_num;
            }
        }
        else{
            seatPre = "FC-";
            Seat_no * seat = new Seat_no(this);
            auto ret = seat->exec();
            if (ret == QDialog::Accepted){
                QString seat_num = QString::number(seat->getSeatNO());
                seatPre += seat_num;
            }
        }

        seat = seatPre;
        QMessageBox::information(this, "Successfully booked", QString("Your ticket number is %1 and your seat is %2").arg(QString::fromStdString(id)).arg(seat));
        this->hide();
        break;
    case QMessageBox::Cancel:
        QMessageBox::critical(this, "Cancelled", "Did not make payment there for couldn't book!");
        break;
    }

    MainWindow * home = new MainWindow(this);
    bool check = home->connect_db();

    if (check){
        QSqlQuery query;
        query.prepare("Insert into Book values (:pass_id, :tid,:date, :source,:dest, :ta, :td, :seat, :price, :tf, :airL)");
        query.bindValue(":pass_id", passanger_ID);
        query.bindValue(":tid", QString::fromStdString(id));
        query.bindValue(":date", date);
        query.bindValue(":source", source);
        query.bindValue(":dest", destination);
        query.bindValue(":ta", time_arrival);
        query.bindValue(":td", time_departure);
        query.bindValue(":seat", seat);
        query.bindValue(":price", price);
        query.bindValue(":tf", "Domestic");
        query.bindValue(":airL", airlines);
        if (query.exec()){
            qDebug() << "success";
        }else{
            //QMessageBox::critical(this, "error",query.lastError().text());
            qDebug () << query.lastError().text();
        }
    }else{
        qDebug () << "Unable to open the database";
    }

    qDebug () << id << " " << date << " " << time_departure << " " << source << " " << destination << time_arrival << " "
             << airlines << " " << seat;
}

