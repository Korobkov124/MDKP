#ifndef CHANGE_EMPLOYES_H
#define CHANGE_EMPLOYES_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include "usermodel.h"

namespace Ui {
class Change_employes;
}

class Change_employes : public QMainWindow
{
    Q_OBJECT

public:
    explicit Change_employes(QWidget *parent = nullptr);
    ~Change_employes();

private slots:
    void on_Autorisation_button_4_clicked();

    void on_Add_button_clicked();

    void on_Autorisation_button_2_clicked();


private:
    Ui::Change_employes *ui;
    usermodel *employee_model;
};

#endif // CHANGE_EMPLOYES_H
