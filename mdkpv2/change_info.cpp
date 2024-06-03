#include "change_info.h"
#include "ui_change_info.h"
#include <QMessageBox>
#include <QString>
#include "usingdatabase.h"

Change_info::Change_info(const UsersClass &client, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Change_info),
    name_validator(QRegularExpression("^[A-Z]{1}[a-z]{15}$")),
    email_validator(QRegularExpression("^.{30}+@(mail\\.ru|outlook\\.com)$")),
    phone_validator(QRegularExpression("^\\+\\d{1,1}\\(\\d{3,5}\\)\\d{2,7}$")),
    password_validator(QRegularExpression("^.{30}$"))
{
    ui->setupUi(this);
    ui->Name_field->setText(client.Name);
    ui->Email_field->setText(client.Email);
    ui->Phone_field->setText(client.Phone);
    ui->Password_field->setText(client.Password);
    Client = client;
    ui->Name_field->setValidator(&name_validator);
    ui->Email_field->setValidator(&email_validator);
    ui->Phone_field->setValidator(&phone_validator);
    ui->Password_field->setValidator(&password_validator);
    ui->Confirm_field->setValidator(&password_validator);
}

Change_info::~Change_info()
{
    delete ui;
}

void Change_info::on_Change_button_clicked()
{
    if (ui->Name_field->text().isEmpty() || ui->Email_field->text().isEmpty() || ui->Phone_field->text().isEmpty() || ui->Password_field->text().isEmpty() || ui->Confirm_field->text().isEmpty())
    {
        QMessageBox::warning(this, "Warning", "Your fields is not correct!!");
    }
    else
    {
        if (ui->Password_field->text() == ui->Confirm_field->text())
        {
            UsersClass user;
            user.Name = ui->Name_field->text();
            user.Email = ui->Email_field->text();
            user.Phone = ui->Phone_field->text();
            user.Password = ui->Password_field->text();
            user.Role = "client";
            user.Display_mode = 1;
            if(UsingDataBase::updateDataIntoUser(Client.Email, user.Name, user.Email, user.Phone, user.Password, user.Role))
            {
                QMessageBox::information(this, "Information", "Your information is updated!");
            }
            else
            {
                QMessageBox::warning(this, "Warning", "Your fields is not correct!!");
            }
        }
    }
}


void Change_info::on_Quit_button_clicked()
{
    close();
}

