#include "user_main.h"
#include "ui_user_main.h"
#include "buyed_history.h"
#include "buying_package.h"
#include "change_info.h"

User_main::User_main(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::User_main)
{
    ui->setupUi(this);
}

User_main::~User_main()
{
    delete ui;
}

void User_main::on_Autorisation_button_4_clicked()
{
    close();
}


void User_main::on_Autorisation_button_2_clicked()
{
    buyed_hist = new Buyed_history(this);
    buyed_hist -> show();

}


void User_main::on_Autorisation_button_clicked()
{
    buying_pckg = new Buying_package(this);
    buying_pckg -> show();
}


void User_main::on_Autorisation_button_3_clicked()
{
    chg_info = new Change_info(this);
    chg_info -> show();
}

void User_main::closeEvent(QCloseEvent *event)
{
    qApp -> quit();
}
