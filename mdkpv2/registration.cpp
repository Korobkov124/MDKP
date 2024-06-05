#include "registration.h"
#include "ui_registration.h"
#include "mainwindow.h"
#include "usingdatabase.h"
#include "userclass.h"
#include <QString>
#include <QValidator>
#include <QMessageBox>

registration::registration(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::registration),
    name_validator(QRegularExpression("^[A-Z]{1}[a-z]{15}$")),
    email_validator(QRegularExpression("^.{30}+@(mail\\.ru|outlook\\.com)$")),
    phone_validator(QRegularExpression("^\\+\\d{1,1}\\(\\d{3,5}\\)\\d{2,7}$")),
    password_validator(QRegularExpression("^.{30}$"))
{
    ui->setupUi(this);
    ui->Name_field->setValidator(&name_validator);
    ui->Phone_field->setValidator(&phone_validator);
    ui->Email_field->setValidator(&email_validator);
    ui->Password_field->setValidator(&password_validator);
}

registration::~registration()
{
    delete ui;
}



void registration::on_Quit_button_clicked()
{
    close();
}


void registration::on_Registrate_button_clicked()
{
    QString Name = ui->Name_field->text();
    QString Email = ui->Email_field->text();
    QString Phone = ui->Phone_field->text();
    QString Password = ui->Password_field->text();
    QString Confirm = ui->Confirm_field->text();
    if ((Password == Confirm) && !(UsingDataBase::getEmailFromDB(Email)) && (Password.length() == 14))
    {
        UsersClass user;
        user.Name = Name;
        user.Email = Email;
        user.Phone = Phone;
        user.Password = Password;
        user.Role = "client";
        UsingDataBase::takeUserToDB(user);
        QMessageBox::warning(this, "Information", "You are registrated! Grats!!!");
    }
    else
    {
        QMessageBox::warning(this, "Warning", "Your password fields or Email is not correct!!");
    }
}

