#include "admin_main.h"
#include "ui_admin_main.h"
#include "change_packages.h"
#include "show_clients.h"
#include "users_list.h"
#include "change_employes.h"

Admin_main::Admin_main(const UsersClass &user, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Admin_main)
{
    ui->setupUi(this);
    ui->Name_label->setText("Admin " + user.Name);
}

Admin_main::~Admin_main()
{
    delete ui;
}

void Admin_main::on_Quit_button_clicked()
{
    close();
}


void Admin_main::on_Change_button_clicked()
{
    chg_pckgs = new Change_packages(this);
    chg_pckgs -> show();
}


void Admin_main::on_History_button_clicked()
{
    shw_usr = new Show_clients(this);
    shw_usr -> show();
}


void Admin_main::on_Show_button_clicked()
{
    usr_list = new Users_list(this);
    usr_list -> show();
}


void Admin_main::on_Changemp_button_clicked()
{
    chg_emp = new Change_employes(this);
    chg_emp -> show();
}

void Admin_main::closeEvent(QCloseEvent *event)
{
    qApp -> quit();
}

