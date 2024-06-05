#include "change_employes.h"
#include "ui_change_employes.h"
#include "mainwindow.h"
#include "userclass.h"
#include "usingdatabase.h"
#include <QMessageBox>
#include <QString>

Change_employes::Change_employes(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Change_employes),
    name_validator(QRegularExpression("^[A-Z]{1}[a-z]{15}$")),
    email_validator(QRegularExpression("^.{30}+@(mail\\.ru|outlook\\.com)$")),
    phone_validator(QRegularExpression("^\\+\\d{1,1}\\(\\d{3,5}\\)\\d{2,7}$")),
    password_validator(QRegularExpression("^.{30}$")),
    role_validator(QRegularExpression("^(admin|moder)$"))
{
    ui->setupUi(this);
    employee_model = new usermodel();
    ui->tableView->setModel(employee_model);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
    ui->Name_field->setValidator(&name_validator);
    ui->Name_for_change_field->setValidator(&name_validator);
    ui->Email_field->setValidator(&email_validator);
    ui->Email_for_change_field->setValidator(&email_validator);
    ui->Email_for_change_field_2->setValidator(&email_validator);
    ui->Phone_field->setValidator(&phone_validator);
    ui->Phone_for_change_field->setValidator(&phone_validator);
    ui->Password_field->setValidator(&password_validator);
    ui->Passsword_for_change_field->setValidator(&password_validator);
    ui->Role_field->setValidator(&role_validator);
    ui->Role_for_change_field->setValidator(&role_validator);
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
    UsersClass user;
    user.Name = ui->Name_field->text();
    user.Email = ui->Email_field->text();
    user.Phone = ui->Phone_field->text();
    user.Password = ui->Password_field->text();
    user.Role = ui->Role_field->text();
    if (!UsingDataBase::getEmailFromDB(ui->Email_field->text()) && user.Email != "" && user.Name != "" && user.Phone != "" && user.Password != "" && user.Role != "" && user.Password.length() == 14)
    {
        UsingDataBase::takeUserToDB(user);
        if (employee_model->addUser(user))
        {
            ui->tableView->update();
        }
    }
    else
    {
        QMessageBox::warning(this, "Warning", "Your fields is not correct!!");
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
        QMessageBox::warning(this, "Warning", "Select the row!");
    }
}


void Change_employes::on_Search_button_clicked()
{
    if ((ui->Email_for_change_field->text() != "") && (UsingDataBase::getEmailFromDB(ui->Email_for_change_field->text())))
    {
        UsersClass user = UsingDataBase::getUserWithEmail(ui->Email_for_change_field->text());
        if (user.Display_mode == 1)
        {
            ui->Name_for_change_field->setText(user.Name);
            ui->Email_for_change_field_2->setText(user.Email);
            ui->Phone_for_change_field->setText(user.Phone);
            ui->Passsword_for_change_field->setText(user.Password);
            ui->Role_for_change_field->setText(user.Role);
        }
        else
        {
            QMessageBox::warning(this, "Warning", "Email is not correct!!");
        }
    }
    else
    {
        QMessageBox::warning(this, "Warning", "Email is not correct!!");
    }
}


void Change_employes::on_Change_button_clicked()
{
    if ((UsingDataBase::getEmailFromDB(ui->Email_for_change_field->text())) && (ui->Email_for_change_field_2->text() != "") && (ui->Name_for_change_field->text() != "") && (ui->Phone_for_change_field->text() != "") && (ui->Passsword_for_change_field->text() != "") && (ui->Role_for_change_field->text() != ""))
    {
        UsingDataBase::updateDataIntoUser(ui->Email_for_change_field->text(), ui->Name_for_change_field->text(), ui->Email_for_change_field_2->text(), ui->Phone_for_change_field->text(), ui->Passsword_for_change_field->text(), ui->Role_for_change_field->text());
        if(employee_model->updateData())
        {
            ui->tableView->update();
        }
    }
    else
    {
        QMessageBox::warning(this, "Warning", "Your fields is not correct!!");
    }
}

