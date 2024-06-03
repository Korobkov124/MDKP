#ifndef CHANGE_INFO_H
#define CHANGE_INFO_H

#include <QMainWindow>
#include <QString>
#include <QRegularExpressionValidator>
#include "userclass.h"

namespace Ui {
class Change_info;
}

class Change_info : public QMainWindow
{
    Q_OBJECT

public:
    explicit Change_info(const UsersClass &client, QWidget *parent = nullptr);
    ~Change_info();

private slots:
    void on_Change_button_clicked();

    void on_Quit_button_clicked();

private:
    Ui::Change_info *ui;
    QRegularExpressionValidator name_validator;
    QRegularExpressionValidator email_validator;
    QRegularExpressionValidator phone_validator;
    QRegularExpressionValidator password_validator;
    UsersClass Client;
};

#endif // CHANGE_INFO_H
