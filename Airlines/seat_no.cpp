#include "seat_no.h"
#include "ui_seat_no.h"
#include <QSettings>

Seat_no::Seat_no(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Seat_no)
{
    ui->setupUi(this);
    for (int i=0; i<18; i++){
        seat_color.append(Qt::white);
    }
    setLoadedColor("button1", 0, ui->one_pushButton);
    setLoadedColor("button2", 1, ui->two_pushButton);
    setLoadedColor("button3", 2, ui->three_pushButton);
    setLoadedColor("button4", 3, ui->four_pushButton);
    setLoadedColor("button5", 4, ui->five_pushButton);
    setLoadedColor("button6", 5, ui->six_pushButton);
    setLoadedColor("button7", 6, ui->seven_pushButton);
    setLoadedColor("button8", 7, ui->eight_pushButton);
    setLoadedColor("button9", 8, ui->nine_pushButton);
    setLoadedColor("button10", 9, ui->ten_pushButton);
    setLoadedColor("button11", 10, ui->eleven_pushButton);
    setLoadedColor("button12", 11, ui->tweleve_pushButton);
    setLoadedColor("button13", 12, ui->thirteen_pushButton);
    setLoadedColor("button14", 13, ui->fourteen_pushButton);
    setLoadedColor("button15", 14, ui->fiveT_pushButton);
    setLoadedColor("button16", 15, ui->sixT_pushButton);
    setLoadedColor("button17", 16, ui->sevenT_pushButton);
    setLoadedColor("button18", 17, ui->eightT_pushButton);
}

Seat_no::~Seat_no()
{
    delete ui;
}

void Seat_no::on_one_pushButton_clicked()
{
    QColor color = Qt::darkGray;
    seat_color[0] = color;

    //Set background color to the button
    QString css = QString("background-color : %1").arg(color.name());
    ui->one_pushButton->setStyleSheet(css);
    saveColor("button1", seat_color[0]);

    SeatNO = 001;
    accept();
}


void Seat_no::on_two_pushButton_clicked()
{
    QColor color = Qt::darkGray;
    seat_color[1] = color;

    QString css = QString("background-color : %1").arg(color.name());
    ui->two_pushButton->setStyleSheet(css);
    saveColor("button2", seat_color[1]);

    SeatNO = 002;
    accept();

}


void Seat_no::on_three_pushButton_clicked()
{
    QColor color = Qt::darkGray;
    seat_color[2] = color;

    QString css = QString ("background-color : %1").arg(color.name());
    ui->three_pushButton->setStyleSheet(css);
    saveColor("button3", seat_color[2]);

    SeatNO = 003;
    accept();
}


void Seat_no::on_four_pushButton_clicked()
{
    QColor color = Qt::darkGray;
    seat_color[3] = color;

    QString css = QString ("background-color : %1").arg(color.name());
    ui->four_pushButton->setStyleSheet(css);
    saveColor("button4", seat_color[3]);

    SeatNO = 004;
    accept();
}


void Seat_no::on_five_pushButton_clicked()
{
    QColor color = Qt::darkGray;
    seat_color[4] = color;

    QString css = QString ("background-color : %1").arg(color.name());
    ui->five_pushButton->setStyleSheet(css);
    saveColor("button5", seat_color[4]);

    SeatNO = 005;
    accept();
}


void Seat_no::on_six_pushButton_clicked()
{
    QColor color = Qt::darkGray;
    seat_color[5] = color;

    QString css = QString("background-color : %1").arg(color.name());
    ui->six_pushButton->setStyleSheet(css);
    saveColor("button6", seat_color[5]);

    SeatNO = 006;
    accept();
}


void Seat_no::on_seven_pushButton_clicked()
{
    QColor color = Qt::darkGray;
    seat_color[6] = color;

    QString css = QString("background-color : %1").arg(color.name());
    ui->seven_pushButton->setStyleSheet(css);
    saveColor("button7", seat_color[6]);

    SeatNO = 007;
    accept();
}


void Seat_no::on_eight_pushButton_clicked()
{
    QColor color = Qt::darkGray;
    seat_color[7] = color;

    QString css = QString("background-color : %1").arg(color.name());
    ui->eight_pushButton->setStyleSheet(css);
    saveColor("button8", seat_color[7]);

    SeatNO = 8;
    accept();
}


void Seat_no::on_nine_pushButton_clicked()
{
    QColor color = Qt::darkGray;
    seat_color[8] = color;

    QString css = QString("background-color : %1").arg(color.name());
    ui->nine_pushButton->setStyleSheet(css);
    saveColor("button9", seat_color[8]);

    SeatNO = 9;
    accept();
}


void Seat_no::on_ten_pushButton_clicked()
{
    QColor color = Qt::darkGray;
    seat_color[9] = color;

    QString css = QString("background-color : %1").arg(color.name());
    ui->ten_pushButton->setStyleSheet(css);
    saveColor("button10", seat_color[9]);

    SeatNO = 010;
    accept();
}


void Seat_no::on_eleven_pushButton_clicked()
{
    QColor color = Qt::darkGray;
    seat_color[10] = color;

    QString css = QString("background-color : %1").arg(color.name());
    ui->eleven_pushButton->setStyleSheet(css);
    saveColor("button11", seat_color[10]);

    SeatNO = 011;
    accept();
}


void Seat_no::on_tweleve_pushButton_clicked()
{
    QColor color = Qt::darkGray;
    seat_color[11] = color;

    QString css = QString("background-color : %1").arg(color.name());
    ui->tweleve_pushButton->setStyleSheet(css);
    saveColor("button12", seat_color[11]);

    SeatNO = 012;
    accept();
}


void Seat_no::on_thirteen_pushButton_clicked()
{
    QColor color = Qt::darkGray;
    seat_color[12] = color;

    QString css = QString("background-color : %1").arg(color.name());
    ui->thirteen_pushButton->setStyleSheet(css);
    saveColor("button13", seat_color[12]);

    SeatNO = 013;
    accept();
}


void Seat_no::on_fourteen_pushButton_clicked()
{
    QColor color = Qt::darkGray;
    seat_color[13] = color;

    QString css = QString("background-color : %1").arg(color.name());
    ui->fourteen_pushButton->setStyleSheet(css);
    saveColor("button14", seat_color[13]);

    SeatNO = 014;
    accept();
}


void Seat_no::on_fiveT_pushButton_clicked()
{
    QColor color = Qt::darkGray;
    seat_color[14] = color;

    QString css = QString("background-color : %1").arg(color.name());
    ui->fiveT_pushButton->setStyleSheet(css);
    saveColor("button15", seat_color[14]);

    SeatNO = 015;
    accept();
}


void Seat_no::on_sixT_pushButton_clicked()
{
    QColor color = Qt::darkGray;
    seat_color[15] = color;

    QString css = QString("background-color : %1").arg(color.name());
    ui->sixT_pushButton->setStyleSheet(css);
    saveColor("button16", seat_color[15]);

    SeatNO = 015;
    accept();
}


void Seat_no::on_sevenT_pushButton_clicked()
{
    QColor color = Qt::darkGray;
    seat_color[16] = color;

    QString css = QString("background-color : %1").arg(color.name());
    ui->sevenT_pushButton->setStyleSheet(css);
    saveColor("button17", seat_color[16]);

    SeatNO = 017;
    accept();
}


void Seat_no::on_eightT_pushButton_clicked()
{
    QColor color = Qt::darkGray;
    seat_color[17] = color;

    QString css = QString("background-color : %1").arg(color.name());
    ui->eightT_pushButton->setStyleSheet(css);
    saveColor("button18", seat_color[17]);

    SeatNO = 18;
    accept();
}

void Seat_no::saveColor(QString key, QColor color)
{
    int red = color.red();
    int green = color.green();
    int blue = color.blue();

    QSettings settings ("Airlines", "seat_color");
    settings.beginGroup("set_color");
    settings.setValue(key + "r", red);
    settings.setValue(key + "g", green);
    settings.setValue(key + "b", blue);
    settings.endGroup();

}

QColor Seat_no::loadColor(QString key)
{
    int red, green, blue;

    QSettings settings("Airlines", "seat_color");
    settings.beginGroup("set_color");
    red = settings.value(key + "r", QVariant(0)).toInt();
    green = settings.value(key + "g", QVariant(0)).toInt();
    blue = settings.value(key + "b", QVariant(0)).toInt();
    settings.endGroup();
    return QColor(red,green, blue);
}

void Seat_no::setLoadedColor(QString key, int index, QPushButton *button)
{
    QColor color = loadColor(key);
    seat_color[index] = color;
    QString css = QString("background-color : %1").arg(color.name());
    button->setStyleSheet(css);
}

int Seat_no::getSeatNO() const
{
    return SeatNO;
}

