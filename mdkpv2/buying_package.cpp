#include "buying_package.h"
#include "ui_buying_package.h"
#include "usingdatabase.h"

Buying_package::Buying_package(const UsersClass &user, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Buying_package)
{
    ui->setupUi(this);
    m_package = new packagemodel();
    ui->tableView->setModel(m_package);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
    User = user;
    connect(ui->tableView->selectionModel(), &QItemSelectionModel::currentRowChanged, this, &Buying_package::handleSelectionChanged);
}

Buying_package::~Buying_package()
{
    delete ui;
}

void Buying_package::on_Quit_button_clicked()
{
    close();
}

void Buying_package::handleSelectionChanged(const QModelIndex &current, const QModelIndex &previous)
{
    if (current.isValid()) {
        int row = current.row();
        int package_id = m_package->getPackageID(row, QModelIndex());
        packageclass package = UsingDataBase::findPackageWithID(package_id);
        conf_pack = new Confirm_package(User, package);
        conf_pack->show();
    }
}
