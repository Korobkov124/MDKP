#ifndef BUYING_PACKAGE_H
#define BUYING_PACKAGE_H

#include <QMainWindow>
#include "packagemodel.h"
#include "userclass.h"
#include "confirm_package.h"

namespace Ui {
class Buying_package;
}

class Buying_package : public QMainWindow
{
    Q_OBJECT
public slots:
    void handleSelectionChanged(const QModelIndex &current, const QModelIndex &previous);

public:
    explicit Buying_package(const UsersClass &user, QWidget *parent = nullptr);
    ~Buying_package();

private slots:
    void on_Quit_button_clicked();

private:
    Ui::Buying_package *ui;
    packagemodel *m_package;
    Confirm_package *conf_pack;
    UsersClass User;
};

#endif // BUYING_PACKAGE_H
