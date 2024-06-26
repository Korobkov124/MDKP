#include "users_list.h"
#include "ui_users_list.h"

Users_list::Users_list(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Users_list)
{
    ui->setupUi(this);
    m_clients = new clientsmodel();
    ui->tableView->setModel(m_clients);
}

Users_list::~Users_list()
{
    delete ui;
}

void Users_list::on_Quit_button_clicked()
{
    close();
}

