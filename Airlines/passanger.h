#ifndef PASSANGER_H
#define PASSANGER_H

#include <QMainWindow>
#include <string>

namespace Ui {
class Passanger;
}

class Passanger : public QMainWindow
{
    Q_OBJECT

public:
    explicit Passanger(QWidget *parent = nullptr);
    ~Passanger();

private:
    Ui::Passanger *ui;
    std::string ticketid;
    std::string name;
    int age;
    std::string gender;
    std::string email;
    std::string password;
    std::string forgot_pass_data;
};

#endif // PASSANGER_H
