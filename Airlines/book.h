#ifndef BOOK_H
#define BOOK_H

#include <QMainWindow>
#include <string>

namespace Ui {
class Book;
}

class Book : public QMainWindow
{
    Q_OBJECT
protected:
    std::string ticketid;
    int date;
    std::string source;
    std::string destination;
    std::string time_arrival;
    std::string time_depardture;
    std::string airlines;
    std::string seat;
    int pirce;

public:
    explicit Book(QWidget *parent = nullptr, QString pass_id = QString());
    ~Book();

private:
    Ui::Book *ui;
};

#endif // BOOK_H
