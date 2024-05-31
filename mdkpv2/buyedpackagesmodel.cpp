#include "buyedpackagesmodel.h"
#include "usingdatabase.h"

BuyedPackagesModel::BuyedPackagesModel(const QString &clientEmail, QObject *parent) : QAbstractTableModel{parent}, clientEmail(clientEmail)
{
    UsingDataBase Base;
    m_BuyedPackages = Base.getBuyedPackages(clientEmail);
}

int BuyedPackagesModel::rowCount(const QModelIndex &parent) const
{
    return m_BuyedPackages.size();
}

int BuyedPackagesModel::columnCount(const QModelIndex &parent) const
{
    return 7;
}

QVariant BuyedPackagesModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        if (index.column() == 0) {
            return m_BuyedPackages[index.row()].ID;
        }
        if (index.column() == 1) {
            return m_BuyedPackages[index.row()].ID_package;
        }
        if (index.column() == 2) {
            return m_BuyedPackages[index.row()].Email_user;
        }
        if (index.column() == 3) {
            return m_BuyedPackages[index.row()].Quantity_of_packages;
        }
        if (index.column() == 4) {
            return m_BuyedPackages[index.row()].Country_name;
        }
        if (index.column() == 5) {
            return m_BuyedPackages[index.row()].Hotel_name;
        }
        if (index.column() == 6) {
            return m_BuyedPackages[index.row()].TotalCost;
        }
    }
    return {};
}

QVariant BuyedPackagesModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Vertical) {
        return section;
    }

    if (role == Qt::DisplayRole) {
        if (section == 0) {
            return "ID";
        }
        if (section == 1) {
            return "ID_package";
        }
        if (section == 2) {
            return "Email_user";
        }
        if (section == 3) {
            return "Quantity_of_packages";
        }
        if (section == 4) {
            return "Country_name";
        }
        if (section == 5) {
            return "Hotel_name";
        }
        if (section == 6) {
            return "Total_cost";
        }
    }
    return {};
}

