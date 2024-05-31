#ifndef BUYEDPACKAGESMODEL_H
#define BUYEDPACKAGESMODEL_H

#include <QAbstractTableModel>
#include "buyedpackageclass.h"
#include <QString>

class BuyedPackagesModel : public QAbstractTableModel
{
public:
    explicit BuyedPackagesModel(const QString &clientEmail, QObject *parent = nullptr);

public:
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

private:
    QVector<BuyedPackageClass> m_BuyedPackages;
    QString clientEmail;
};

#endif // BUYEDPACKAGESMODEL_H
