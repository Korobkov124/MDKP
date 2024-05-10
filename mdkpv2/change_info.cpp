#include "change_info.h"
#include "ui_change_info.h"

Change_info::Change_info(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Change_info)
{
    ui->setupUi(this);
}

Change_info::~Change_info()
{
    delete ui;
}
