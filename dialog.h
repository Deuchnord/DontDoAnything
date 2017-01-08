#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QCloseEvent>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    void setTime(long t);
    void closeEvent(QCloseEvent *event);
    bool really();
    void run();
    ~Dialog();

private slots:
    void keyPressEvent(QKeyEvent *e);
    void on_buttonBox_rejected();
    void timerTimeout();

private:
    Ui::Dialog *ui;
    long time = 60;
};

#endif // DIALOG_H
