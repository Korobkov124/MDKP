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

void Change_employes::on_Quit_button_clicked()
{
    close();
}


void Change_employes::on_Add_button_clicked()
{
    QString line = ui->lineEdit_3->text();
    if (line == "")
    {
        QMessageBox::warning(this, "Warning", "Your field is empty!");
    }
    else
    {
        UsersClass user = user.getUserFromString(line);
        if(UsingDataBase::takeUserToDB(user))
        {
            int row = employee_model->rowCount(QModelIndex());
            employee_model->insertRow(row, QModelIndex());
            employee_model->setData(employee_model->index(row, 0), user.Name);
            employee_model->setData(employee_model->index(row, 1), user.Email);
            employee_model->setData(employee_model->index(row, 2), user.Phone);
            employee_model->setData(employee_model->index(row, 3), user.Password);
            employee_model->setData(employee_model->index(row, 4), user.Role);
            employee_model->submit();
            ui->tableView->viewport()->update();
            ui->tableView->reset();
        }
    }
}


void Change_employes::on_Delete_button_clicked()
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

