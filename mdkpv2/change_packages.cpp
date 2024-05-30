#include "change_packages.h"
#include "ui_change_packages.h"
#include <QString>
#include <QMessageBox>
#include "usingdatabase.h"


Change_packages::Change_packages(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Change_packages),
    country_validator(QRegularExpression("^[A-Z]{1}[a-z]{15}$")),
    hotel_validator(QRegularExpression("^.{40}$")),
    cost_validator(QRegularExpression("^(10000|[1-9]\\d{4}|1000000)$")),
    weekcast_validator(QRegularExpression("^[1-4]$")),
    packcast_validator(QRegularExpression("^(1|[1-9]\\d{2}|100)$")),
    id_validator(QRegularExpression("^[0-9]{1,}$"))
{
    ui->setupUi(this);
    m_package = new packagemodel();
    ui->tableView->setModel(m_package);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
    ui->Country_field->setValidator(&country_validator);
    ui->Country_for_change_field->setValidator(&country_validator);
    ui->Hotel_field->setValidator(&hotel_validator);
    ui->Hotel_for_chang_field->setValidator(&hotel_validator);
    ui->Cost_field->setValidator(&cost_validator);
    ui->Cost_for_change_field->setValidator(&cost_validator);
    ui->Week_cast_field->setValidator(&weekcast_validator);
    ui->Weekcast_for_change_field->setValidator(&weekcast_validator);
    ui->Package_cast_field->setValidator(&packcast_validator);
    ui->Packcast_for_change_field_->setValidator(&packcast_validator);
    ui->ID_for_change_field->setValidator(&id_validator);
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

