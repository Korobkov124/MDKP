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
    explicit Employee_main(const UsersClass &moder, QWidget *parent = nullptr);
    ~Employee_main();

private slots:
    void on_Quit_button_clicked();

    void on_Change_packs_button_clicked();

    void on_Check_button_clicked();

    void on_Show_button_clicked();

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::Employee_main *ui;
    Change_packages *chg_pckgs;
    Show_clients *shw_usr;
    Users_list *usr_list;
    UsersClass moder;
};

#endif // EMPLOYEE_MAIN_H
