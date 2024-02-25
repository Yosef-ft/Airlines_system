#ifndef BOOK_H
#define BOOK_H

#include <QMainWindow>
#include <string>
#include <QString>

namespace Ui {
class Book;
}

class Book : public QMainWindow
{
    Q_OBJECT
protected:
    std::string ticketid();
    std::string id;
    QString date;
    QString source;
    QString destination;
    QString time_arrival;
    QString time_departure;
    QString airlines;
    QString seat;
    int price;

public:
    explicit Book(QWidget *parent = nullptr, QString pass_id = QString());
    ~Book();

private slots:
    void on_submit_pushButton_clicked();

    void on_bookD_pushButton_clicked();

    void on_book_I_pushButton_clicked();

private:
    Ui::Book *ui;
};

#endif // BOOK_H
