#ifndef EMPLOYEE_MAIN_H
#define EMPLOYEE_MAIN_H

#include <QMainWindow>
#include "change_packages.h"
#include "show_clients.h"
#include "users_list.h"

namespace Ui {
class Employee_main;
}

class Employee_main : public QMainWindow
{
    Q_OBJECT

public:
    explicit Employee_main(QWidget *parent = nullptr);
    ~Employee_main();

private slots:
    void on_Autorisation_button_4_clicked();

    void on_Autorisation_button_clicked();

    void on_Autorisation_button_2_clicked();

    void on_Autorisation_button_3_clicked();

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::Employee_main *ui;
    Change_packages *chg_pckgs;
    Show_clients *shw_usr;
    Users_list *usr_list;
};

#endif // EMPLOYEE_MAIN_H
