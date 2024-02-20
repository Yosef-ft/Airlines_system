#ifndef EDIT_INFO_H
#define EDIT_INFO_H

#include <QMainWindow>

namespace Ui {
class Edit_info;
}

class Edit_info : public QMainWindow
{
    Q_OBJECT

public:
    explicit Edit_info(QWidget *parent = nullptr, QString pass_id = QString());
    ~Edit_info();

private:
    Ui::Edit_info *ui;
};

#endif // EDIT_INFO_H
