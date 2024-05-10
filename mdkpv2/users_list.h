#ifndef USERS_LIST_H
#define USERS_LIST_H

#include <QMainWindow>

namespace Ui {
class Users_list;
}

class Users_list : public QMainWindow
{
    Q_OBJECT

public:
    explicit Users_list(QWidget *parent = nullptr);
    ~Users_list();

private slots:
    void on_Registration_button_clicked();

private:
    Ui::Users_list *ui;
};

#endif // USERS_LIST_H
