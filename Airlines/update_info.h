#ifndef UPDATE_INFO_H
#define UPDATE_INFO_H

#include <QMainWindow>

namespace Ui {
class update_info;
}

class update_info : public QMainWindow
{
    Q_OBJECT

public:
    explicit update_info(QWidget *parent = nullptr, QString pass_id = QString());
    ~update_info();

    QString passwordId;

private slots:
    void on_edit_pushButton_clicked();

private:
    Ui::update_info *ui;
};

#endif // UPDATE_INFO_H
