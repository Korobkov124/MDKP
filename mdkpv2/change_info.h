#ifndef CHANGE_INFO_H
#define CHANGE_INFO_H

#include <QMainWindow>

namespace Ui {
class Change_info;
}

class Change_info : public QMainWindow
{
    Q_OBJECT

public:
    explicit Change_info(QWidget *parent = nullptr);
    ~Change_info();

private:
    Ui::Change_info *ui;
};

#endif // CHANGE_INFO_H
