#ifndef BUYED_HISTORY_H
#define BUYED_HISTORY_H

#include <QMainWindow>

namespace Ui {
class Buyed_history;
}

class Buyed_history : public QMainWindow
{
    Q_OBJECT

public:
    explicit Buyed_history(QWidget *parent = nullptr);
    ~Buyed_history();

private slots:
    void on_Autorisation_button_clicked();

private:
    Ui::Buyed_history *ui;
};

#endif // BUYED_HISTORY_H
