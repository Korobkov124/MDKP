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
    bool removeRow(int row, const QModelIndex &parent);
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    bool addPackage(const packageclass& newPackage);
    bool updateData();
    int getPackageID(int row, const QModelIndex &parent) const;
private:
    QVector<packageclass> m_packages;
};

#endif // PACKAGEMODEL_H
