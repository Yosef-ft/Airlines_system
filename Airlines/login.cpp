#include "login.h"
#include "ui_login.h"
#include <QString>
#include "edit_info.h"
#include <QDebug>
#include "book.h"

Login::Login(QWidget *parent, QString passanger_id)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    pass_id = passanger_id;
}

Login::~Login()
{
    delete ui;
}

void Login::on_submit_pushButton_clicked()
{
    if (ui->edit_radioButton->isChecked()){
        Edit_info * edit = new Edit_info(this, pass_id);

        edit->show();

    }
    else if (ui->book_radioButton->isChecked()){
        Book * book = new Book(this, pass_id);
        book->show();
    }
    else if (ui->ticket_radioButton->isChecked()){

    }
}

