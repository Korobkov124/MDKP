#ifndef SHOW_CLIENTS_H
#define SHOW_CLIENTS_H

#include <QMainWindow>

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
    void on_Autorisation_button_2_clicked();

private:
    Ui::Show_clients *ui;
};

#endif // SHOW_CLIENTS_H
