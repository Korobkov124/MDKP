#include "show_clients.h"
#include "ui_show_clients.h"

Show_clients::Show_clients(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Show_clients)
{
    ui->setupUi(this);
}

Show_clients::~Show_clients()
{
    delete ui;
}

void Show_clients::on_Autorisation_button_2_clicked()
{
    close();
}

