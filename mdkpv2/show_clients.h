#ifndef SHOW_CLIENTS_H
#define SHOW_CLIENTS_H

#include <QMainWindow>
#include "buyedpackagesmodel.h"

namespace Ui {
class Show_clients;
}

class Show_clients : public QMainWindow
{
    Q_OBJECT

public:
    explicit Show_clients(QWidget *parent = nullptr);
    ~Show_clients();

private slots:
    void on_Quit_button_clicked();

    void on_Search_button_clicked();

private:
    Ui::Show_clients *ui;
    BuyedPackagesModel *package_model;
};

#endif // SHOW_CLIENTS_H
