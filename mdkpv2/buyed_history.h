#ifndef BUYED_HISTORY_H
#define BUYED_HISTORY_H

#include <QMainWindow>
#include "userclass.h"
#include "buyedpackagesmodel.h"

namespace Ui {
class Buyed_history;
}

class Buyed_history : public QMainWindow
{
    Q_OBJECT

public:
    explicit Buyed_history(const UsersClass &client, QWidget *parent = nullptr);
    ~Buyed_history();

private slots:
    void on_Quit_button_clicked();

private:
    Ui::Buyed_history *ui;
    BuyedPackagesModel *package_model;
};

#endif // BUYED_HISTORY_H
