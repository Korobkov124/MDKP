#ifndef ADMIN_MAIN_H
#define ADMIN_MAIN_H

#include <QMainWindow>
#include "change_packages.h"
#include "show_clients.h"
#include "users_list.h"
#include "change_employes.h"
#include "userclass.h"

namespace Ui {
class Admin_main;
}

class Admin_main : public QMainWindow
{
    Q_OBJECT

public:
    explicit Admin_main(const UsersClass &user, QWidget *parent = nullptr);
    ~Admin_main();

private slots:
    void on_Quit_button_clicked();

    void on_Change_button_clicked();

    void on_History_button_clicked();

    void on_Show_button_clicked();

    void on_Changemp_button_clicked();

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::Admin_main *ui;
    Change_packages *chg_pckgs;
    Show_clients *shw_usr;
    Users_list *usr_list;
    Change_employes *chg_emp;
    UsersClass admin;
};

#endif // ADMIN_MAIN_H
