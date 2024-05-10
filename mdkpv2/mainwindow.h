#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "registration.h"
#include "admin_main.h"
#include "user_main.h"
#include "employee_main.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Registration_button_clicked();

    void on_Autorisation_button_clicked();

private:
    Ui::MainWindow *ui;
    registration *window;
    Admin_main *win_admin;
    User_main *win_usr;
    Employee_main *win_emp;
};
#endif // MAINWINDOW_H
