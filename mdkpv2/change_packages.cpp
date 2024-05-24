#include "change_packages.h"
#include "ui_change_packages.h"
#include <QString>
#include <QMessageBox>
#include "usingdatabase.h"

Change_packages::Change_packages(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Change_packages)
{
    ui->setupUi(this);
    m_package = new packagemodel();
    ui->tableView->setModel(m_package);
}

Change_packages::~Change_packages()
{
    delete ui;
}

void Change_packages::on_Quit_button_clicked()
{
    close();
}


void Change_packages::on_Add_button_clicked()
{
    QString line = ui->lineEdit->text();
    if (line == "")
    {
        QMessageBox::warning(this, "Warning", "Your field is empty!");
    }
    else
    {
        packageclass package = package.getPackageFromString(line);
        if(UsingDataBase::takePackageToDB(package))
        {
            int row = m_package->rowCount(QModelIndex());
            m_package->insertRow(row, QModelIndex());
            m_package->setData(m_package->index(row, 0), package.Country_name);
            m_package->setData(m_package->index(row, 1), package.Hotel_name);
            m_package->setData(m_package->index(row, 2), package.Cost_for_week);
            m_package->setData(m_package->index(row, 3), package.Week_cast);
            m_package->setData(m_package->index(row, 4), package.Package_cast);
            m_package->setData(m_package->index(row, 5), package.ID);
            m_package->submit();
            ui->tableView->viewport()->update();
            ui->tableView->reset();
        }
    }
}


void Change_packages::on_Delete_button_clicked()
{
    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedRows();
    if (!selectedRows.isEmpty())
    {
        int row = selectedRows.at(0).row();
        if (m_package->removeRow(row, QModelIndex()))
        {
            ui->tableView->update();
        }
    }
    else
    {
        QMessageBox::warning(this, "Warning", "Select the entire row!");
    }
}

