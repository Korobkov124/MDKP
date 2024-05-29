#ifndef REGISTRATION_H
#define REGISTRATION_H
#include <QRegularExpressionValidator>
#include <QMainWindow>

namespace Ui {
class registration;
}

class registration : public QMainWindow
{
    Q_OBJECT

public:
    explicit registration(QWidget *parent = nullptr);
    ~registration();

private slots:
    void on_Quit_button_clicked();

    void on_Registrate_button_clicked();

private:
    Ui::registration *ui;
    QRegularExpressionValidator name_validator;
    QRegularExpressionValidator email_validator;
    QRegularExpressionValidator phone_validator;
    QRegularExpressionValidator password_validator;
};

#endif // REGISTRATION_H
