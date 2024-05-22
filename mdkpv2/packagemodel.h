#ifndef PACKAGEMODEL_H
#define PACKAGEMODEL_H
#include <QAbstractTableModel>
#include "packageclass.h"
#include <QVector>

class packagemodel : public QAbstractTableModel
{
public:
    explicit packagemodel(QObject *parent = nullptr);

public:
    int rowCount(const QModelIndex &parent) const override ;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

private:
    QVector<packageclass> m_packages;
};

#endif // PACKAGEMODEL_H
