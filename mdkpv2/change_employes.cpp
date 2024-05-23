#include "change_employes.h"
#include "ui_change_employes.h"
#include "mainwindow.h"
#include "userclass.h"
#include "usingdatabase.h"
#include <QMessageBox>
#include <QString>

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
    QString line = ui->lineEdit_3->text();
    UsersClass user = user.getUserFromString(line);
    UsingDataBase::takeUserToDB(user);
    ui->tableView->update();
}


void Change_employes::on_Autorisation_button_2_clicked()
{
    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedRows();
    if (!selectedRows.isEmpty())
    {
        int row = selectedRows.at(0).row();
        if (employee_model->removeRow(row, QModelIndex()))
        {
            ui->tableView->update();
        }
    }
    else
    {
        QMessageBox::warning(this, "Warning", "Select the entire row!");
    }
}

