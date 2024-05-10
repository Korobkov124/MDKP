#include "employee_main.h"
#include "ui_employee_main.h"
#include "change_packages.h"
#include "show_clients.h"
#include "users_list.h"

Employee_main::Employee_main(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Employee_main)
{
    ui->setupUi(this);
}

Employee_main::~Employee_main()
{
    delete ui;
}

void Employee_main::on_Autorisation_button_4_clicked()
{
    close();
}


void Employee_main::on_Autorisation_button_clicked()
{
    chg_pckgs = new Change_packages(this);
    chg_pckgs -> show();
}


void Employee_main::on_Autorisation_button_2_clicked()
{
    shw_usr = new Show_clients(this);
    shw_usr -> show();
}


void Employee_main::on_Autorisation_button_3_clicked()
{
    usr_list = new Users_list(this);
    usr_list -> show();
}

void Employee_main::closeEvent(QCloseEvent *event)
{
    qApp -> quit();
}

