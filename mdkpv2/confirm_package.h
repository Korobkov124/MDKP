#ifndef CONFIRM_PACKAGE_H
#define CONFIRM_PACKAGE_H

#include <QMainWindow>
#include <QString>
#include "userclass.h"
#include "packageclass.h"

namespace Ui {
class Confirm_package;
}

class Confirm_package : public QMainWindow
{
    Q_OBJECT

public:
    explicit Confirm_package(const UsersClass &user, const packageclass &package, QWidget *parent = nullptr);
    ~Confirm_package();

private slots:
    void on_Quit_button_clicked();

    void on_Enter_button_clicked();

    void on_Comfirm_button_clicked();

private:
    Ui::Confirm_package *ui;
    UsersClass User;
    packageclass Package;
};

#endif // CONFIRM_PACKAGE_H
