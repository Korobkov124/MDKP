#ifndef BUYING_PACKAGE_H
#define BUYING_PACKAGE_H

#include <QMainWindow>

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
};

#endif // BUYING_PACKAGE_H
