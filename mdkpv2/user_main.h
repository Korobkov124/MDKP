#ifndef USER_MAIN_H
#define USER_MAIN_H

#include <QMainWindow>
#include "buyed_history.h"
#include "buying_package.h"
#include "change_info.h"
#include "userclass.h"

namespace Ui {
class User_main;
}

class User_main : public QMainWindow
{
    Q_OBJECT

public:
    explicit User_main(const UsersClass &client, QWidget *parent = nullptr);
    ~User_main();

private slots:
    void on_Quit_button_clicked();

    void on_Show_button_clicked();

    void on_Change_button_clicked();

    void on_History_button_clicked();

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::User_main *ui;
    Buyed_history *buyed_hist;
    Buying_package *buying_pckg;
    Change_info *chg_info;
    UsersClass Client;
};

#endif // USER_MAIN_H
