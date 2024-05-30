#ifndef USERMODEL_H
#define USERMODEL_H
#include <QAbstractTableModel>
#include "userclass.h"
#include <QVector>

class usermodel : public QAbstractTableModel
{
public:
    explicit usermodel(QObject *parent = nullptr);

public:
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    bool removeRow(int row, const QModelIndex &parent);
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    bool addUser(const UsersClass& newUser);
    bool updateData();
private:
    QVector<UsersClass> m_users;
};

#endif // USERMODEL_H
