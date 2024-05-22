#ifndef CHANGE_PACKAGES_H
#define CHANGE_PACKAGES_H

#include <QMainWindow>
#include "packagemodel.h"

namespace Ui {
class Change_packages;
}

class Change_packages : public QMainWindow
{
    Q_OBJECT

public:
    explicit Change_packages(QWidget *parent = nullptr);
    ~Change_packages();

private slots:
    void on_Autorisation_button_4_clicked();

private:
    Ui::Change_packages *ui;
    packagemodel *m_package;
};

#endif // CHANGE_PACKAGES_H
