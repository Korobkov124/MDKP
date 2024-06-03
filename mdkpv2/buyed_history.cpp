#include "buyed_history.h"
#include "ui_buyed_history.h"
#include <QString>

Buyed_history::Buyed_history(const UsersClass &user, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Buyed_history)
{
    ui->setupUi(this);
    package_model = new BuyedPackagesModel(user.Email);
    ui->tableView->setModel(package_model);
    int Discaunt = package_model->totalPurchasesForClient(user.Email);
    ui->label_3->setText("Your total discaunt is " + QString::number(Discaunt) + "%!");
}

Buyed_history::~Buyed_history()
{
    delete ui;
}

void Buyed_history::on_Quit_button_clicked()
{
    close();
}

