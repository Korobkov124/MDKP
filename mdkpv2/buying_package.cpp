#include "buying_package.h"
#include "ui_buying_package.h"

Buying_package::Buying_package(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Buying_package)
{
    ui->setupUi(this);
    m_package = new packagemodel();
    ui->tableView->setModel(m_package);
}

Buying_package::~Buying_package()
{
    delete ui;
}

void Buying_package::on_Autorisation_button_clicked()
{
    close();
}

