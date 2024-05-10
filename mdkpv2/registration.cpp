#include "registration.h"
#include "ui_registration.h"
#include "mainwindow.h"

registration::registration(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::registration)
{
    ui->setupUi(this);
}

registration::~registration()
{
    delete ui;
}

void registration::on_Registration_button_clicked()
{
    close();
}

