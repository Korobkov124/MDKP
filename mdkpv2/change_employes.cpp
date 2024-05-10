#include "change_employes.h"
#include "ui_change_employes.h"
#include "mainwindow.h"

Change_employes::Change_employes(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Change_employes)
{
    ui->setupUi(this);
    QSqlDatabase new_db = QSqlDatabase::addDatabase("QSQLITE");
    new_db.setDatabaseName("./users_bd.db");
    if (new_db.open())
    {
        qDebug() << "OPEN";
    }
    else
    {
        qDebug() << "NOT OPEN";
    }
    model = new QSqlTableModel(this, new_db);
    model -> setTable("employees");
    model -> select();
    ui->tableView->setModel(model);
}

Change_employes::~Change_employes()
{
    delete ui;
}

void Change_employes::on_Autorisation_button_4_clicked()
{
    close();
}


void Change_employes::on_Autorisation_button_clicked()
{
    model->insertRow(model->rowCount());
}


void Change_employes::on_Autorisation_button_2_clicked()
{
    model->removeRow(row);
}


void Change_employes::on_tableView_clicked(const QModelIndex &index)
{
    row = index.row();
}

