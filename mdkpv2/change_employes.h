#ifndef CHANGE_EMPLOYES_H
#define CHANGE_EMPLOYES_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include "usermodel.h"
#include <QRegularExpressionValidator>

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
    void on_Quit_button_clicked();

    void on_Add_button_clicked();

    void on_Delete_button_clicked();


    void on_Search_button_clicked();

    void on_Change_button_clicked();

private:
    Ui::Change_employes *ui;
    usermodel *employee_model;
    QRegularExpressionValidator name_validator;
    QRegularExpressionValidator email_validator;
    QRegularExpressionValidator phone_validator;
    QRegularExpressionValidator password_validator;
    QRegularExpressionValidator role_validator;
};

#endif // CHANGE_EMPLOYES_H
