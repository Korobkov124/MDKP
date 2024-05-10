#include "change_packages.h"
#include "ui_change_packages.h"

Change_packages::Change_packages(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Change_packages)
{
    ui->setupUi(this);
}

Change_packages::~Change_packages()
{
    delete ui;
}

void Change_packages::on_Autorisation_button_4_clicked()
{
    close();
}

