#ifndef BUYING_PACKAGE_H
#define BUYING_PACKAGE_H

#include <QMainWindow>
#include "packagemodel.h"
namespace Ui {
class Buying_package;
}

class Buying_package : public QMainWindow
{
    Q_OBJECT

public:
    explicit Buying_package(QWidget *parent = nullptr);
    ~Buying_package();

private slots:
    void on_Autorisation_button_clicked();

private:
    Ui::Buying_package *ui;
    packagemodel *m_package;
};

#endif // BUYING_PACKAGE_H
