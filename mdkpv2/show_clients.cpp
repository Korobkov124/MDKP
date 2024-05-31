#include "show_clients.h"
#include "ui_show_clients.h"
#include <QMessageBox>
#include <QString>
#include "usingdatabase.h"

Show_clients::Show_clients(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Show_clients)
{
    ui->setupUi(this);
}

Show_clients::~Show_clients()
{
    delete ui;
}

void Show_clients::on_Quit_button_clicked()
{
    close();
}


void Show_clients::on_Search_button_clicked()
{
    if (!UsingDataBase::getEmailFromDB(ui->Email_field->text()))
    {
        QMessageBox::warning(this, "Warning", "Your Email field is not correct!!");
    }
    else
    {
        QString Email = ui->Email_field->text();
        package_model = new BuyedPackagesModel(Email);
        ui->tableView->setModel(package_model);
    }
}

