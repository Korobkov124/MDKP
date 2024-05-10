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
    UsingDataBase object;
    QString employee_role;
    if(login == "" && password == "")
    {
        QMessageBox::warning(this, "Warning", "Your login & password fields is empty");
        return;
    }
    if (object.FindClient(login, password) == true)
    {
        hide();
        win_usr = new User_main(this);
        win_usr -> show();
        return;
    }
    else
    {
        employee_role = object.FindUserRole(login, password);
        if (employee_role == "admin")
        {
            hide();
            win_admin = new Admin_main(this);
            win_admin -> show();
            return;
        }
        if (employee_role == "moder")
        {
            hide();
            win_emp = new Employee_main(this);
            win_emp -> show();
            return;
        }
    }
    QMessageBox::warning(this, "Warning", "Your login & password fields is uncorrect");
}

