#include "change_employes.h"
#include "ui_change_employes.h"
#include "mainwindow.h"

Change_employes::Change_employes(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Change_employes)
{
    ui->setupUi(this);
    employee_model = new usermodel();
    ui->tableView->setModel(employee_model);
}

Change_employes::~Change_employes()
{
    delete ui;
}

void Change_employes::on_Autorisation_button_4_clicked()
{
    close();
}


void Change_employes::on_Autorisation_button_clicked()
{

}


void Change_employes::on_Autorisation_button_2_clicked()
{

}

