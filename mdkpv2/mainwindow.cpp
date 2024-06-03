#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "admin_main.h"
#include "user_main.h"
#include "employee_main.h"
#include "usingdatabase.h"
#include <QMessageBox>
#include <qDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    UsingDataBase::DataBaseConnection();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Registration_button_clicked()
{
    window = new registration(this);
    window -> show();
}


void MainWindow::on_Autorisation_button_clicked()
{
    QString login = ui->Email_field->text();
    QString password = ui->Password_field->text();

    if(login.isEmpty() || password.isEmpty())
    {
        QMessageBox::warning(this, "Warning", "Your login & password fields are empty");
        return;
    }
    if ((!UsingDataBase::getEmailFromDB(login)) && (!UsingDataBase::getPasswordFromDB(password)))
    {
        QMessageBox::warning(this, "Warning", "Incorrect login or password");
        return;
    }
    else
    {
        QString userRole = UsingDataBase::FindUserRole(login, password);
        if(userRole == "empty")
        {
            QMessageBox::warning(this, "Warning", "Incorrect login or password");
            return;
        }
        if (userRole == "admin")
        {
            hide();
            UsersClass admin = UsingDataBase::GetUserFromDB(login, password);
            win_admin = new Admin_main(admin);
            win_admin->show();
        }
        else if (userRole == "moder")
        {
            hide();
            UsersClass moder = UsingDataBase::GetUserFromDB(login, password);
            win_emp = new Employee_main(moder);
            win_emp->show();
        }
        else if (userRole == "client")
        {
            hide();
            UsersClass client = UsingDataBase::GetUserFromDB(login, password);
            win_usr = new User_main(client);
            win_usr->show();
        }
    }
}

