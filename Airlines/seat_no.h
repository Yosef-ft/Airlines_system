#ifndef SEAT_NO_H
#define SEAT_NO_H

#include <QDialog>
#include <QColor>

namespace Ui {
class Seat_no;
}

class Seat_no : public QDialog
{
    Q_OBJECT

public:
    explicit Seat_no(QWidget *parent = nullptr);
    ~Seat_no();

    int getSeatNO() const;

private slots:
    void on_one_pushButton_clicked();

    void on_two_pushButton_clicked();

    void on_three_pushButton_clicked();

    void on_four_pushButton_clicked();

    void on_five_pushButton_clicked();

    void on_six_pushButton_clicked();

    void on_seven_pushButton_clicked();

    void on_eight_pushButton_clicked();

    void on_nine_pushButton_clicked();

    void on_ten_pushButton_clicked();

    void on_eleven_pushButton_clicked();

    void on_tweleve_pushButton_clicked();

    void on_thirteen_pushButton_clicked();

    void on_fourteen_pushButton_clicked();

    void on_fiveT_pushButton_clicked();

    void on_sixT_pushButton_clicked();

    void on_sevenT_pushButton_clicked();

    void on_eightT_pushButton_clicked();

private:
    Ui::Seat_no *ui;

    QList <QColor> seat_color;
    void saveColor(QString key, QColor color);
    QColor loadColor(QString key);
    void setLoadedColor(QString key, int index, QPushButton * button);

    int SeatNO;
};

#endif // SEAT_NO_H
