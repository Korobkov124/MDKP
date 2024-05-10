#ifndef ADMIN_MAIN_H
#define ADMIN_MAIN_H

#include <QMainWindow>
#include "change_packages.h"
#include "show_clients.h"
#include "users_list.h"
#include "change_employes.h"

namespace Ui {
class Admin_main;
}

class Admin_main : public QMainWindow
{
    Q_OBJECT

public:
    explicit Admin_main(QWidget *parent = nullptr);
    ~Admin_main();

private slots:
    void on_Autorisation_button_4_clicked();

    void on_Autorisation_button_clicked();

    void on_Autorisation_button_2_clicked();

    void on_Autorisation_button_3_clicked();

    void on_Autorisation_button_5_clicked();

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::Admin_main *ui;
    Change_packages *chg_pckgs;
    Show_clients *shw_usr;
    Users_list *usr_list;
    Change_employes *chg_emp;
};

#endif // ADMIN_MAIN_H
