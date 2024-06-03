#include "confirm_package.h"
#include "ui_confirm_package.h"
#include "usingdatabase.h"
#include <QMEssageBox>

Confirm_package::Confirm_package(const UsersClass &user, const packageclass &package, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Confirm_package)
{
    ui->setupUi(this);
    ui->label_2->setText(package.Country_name + " " + package.Hotel_name + ", " + QString::number(package.Week_cast) + " " + "weeks");
    ui->spinBox->setMaximum(package.Package_cast);
    ui->spinBox->setMinimum(1);
    Package = package;
    User = user;
}

Confirm_package::~Confirm_package()
{
    delete ui;
}


void Confirm_package::on_Quit_button_clicked()
{
    this->close();
    this->deleteLater();
}


void Confirm_package::on_Enter_button_clicked()
{
    int TotalCost = (Package.Cost_for_week * Package.Week_cast) * ui->spinBox->value();
    ui->label_5->setText("Total cost is " + QString::number(TotalCost) + "$");
}


void Confirm_package::on_Comfirm_button_clicked()
{
    if(UsingDataBase::getPackageBuyed(Package.ID, User.Email, ui->spinBox->value()))
    {
        QMessageBox::information(this, "Information", "Package buyed! Great!");
    }
    else
    {
        QMessageBox::warning(this, "Warning", "Something goes wrong!");
    }
}

