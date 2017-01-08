#include <iostream>
#include <QTimer>
#include <QProgressBar>
#include <QMessageBox>

#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::run()
{
    QTimer *timer = new QTimer();
    timer->setInterval(50);
    ui->progressBar->setMaximum(time * 1000);

    connect(timer, SIGNAL(timeout()), SLOT(timerTimeout()));
    timer->start();
}

void Dialog::timerTimeout()
{
    ui->progressBar->setValue(ui->progressBar->value() + 50);

    if(ui->progressBar->value() == ui->progressBar->maximum())
        accept();
}

void Dialog::setTime(long t)
{
    if(t < 1)
        throw std::string("time argument must be a number at least equal to 1.");

    this->time = t;
}

bool Dialog::really()
{
    return QMessageBox::question(this, tr("Really?"), tr("Do you really want to stop not doing anything?"), QMessageBox::Yes, QMessageBox::No) == QMessageBox::Yes;
}

void Dialog::closeEvent(QCloseEvent *event)
{
    if(really())
        event->accept();
    else
        event->ignore();
}

void Dialog::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Escape)
    {
        if(really())
            accept();
    }
}

void Dialog::on_buttonBox_rejected()
{
    if(really())
        accept();
}
