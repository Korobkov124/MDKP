#ifndef CLEINTSMODEL_H
#define CLEINTSMODEL_H
#include <QAbstractTableModel>
#include "userclass.h"
#include <QVector>

class clientsmodel : public QAbstractTableModel
{
public:
    explicit clientsmodel(QObject *parent = nullptr);

public:
    int rowCount(const QModelIndex &parent) const override ;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

private:
    QVector<UsersClass> m_clients;
};

#endif // CLEINTSMODEL_H
