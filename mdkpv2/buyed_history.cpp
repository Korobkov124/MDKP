#include "buyed_history.h"
#include "ui_buyed_history.h"

Buyed_history::Buyed_history(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Buyed_history)
{
    ui->setupUi(this);
}

Buyed_history::~Buyed_history()
{
    delete ui;
}

void Buyed_history::on_Autorisation_button_clicked()
{
    close();
}

