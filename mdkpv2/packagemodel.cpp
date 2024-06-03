#include "packagemodel.h"
#include "usingdatabase.h"

packagemodel::packagemodel(QObject *parent) : QAbstractTableModel{parent}
{
    UsingDataBase Base;
    m_packages = Base.getAllPackages();
}

int packagemodel::rowCount(const QModelIndex &parent) const
{
    return m_packages.size();
}

int packagemodel::columnCount(const QModelIndex &parent) const
{
    return 6;
}

bool packagemodel::removeRow(int row, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row);
    UsingDataBase Base;
    Base.DeletePackage(m_packages[row].ID);
    m_packages.removeAt(row);
    endRemoveRows();
    return true;
}



QVariant packagemodel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        if (index.column() == 0 && m_packages[index.row()].Display_mode == 1) {
            return m_packages[index.row()].Country_name;
        }
        if (index.column() == 1 && m_packages[index.row()].Display_mode == 1) {
            return m_packages[index.row()].Hotel_name;
        }
        if (index.column() == 2 && m_packages[index.row()].Display_mode == 1) {
            return m_packages[index.row()].Cost_for_week;
        }
        if (index.column() == 3 && m_packages[index.row()].Display_mode == 1) {
            return m_packages[index.row()].Week_cast;
        }
        if (index.column() == 4 && m_packages[index.row()].Display_mode == 1) {
            return m_packages[index.row()].Package_cast;
        }
        if (index.column() == 5 && m_packages[index.row()].Display_mode == 1) {
            return m_packages[index.row()].ID;
        }
    }
    return {};
}

QVariant packagemodel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Vertical) {
        return section;
    }

    if (role == Qt::DisplayRole) {
        if (section == 0) {
            return "Country_name";
        }
        if (section == 1) {
            return "Hotel_name";
        }
        if (section == 2) {
            return "Cost_for_week";
        }
        if (section == 3) {
            return "Week_cast";
        }
        if (section == 4) {
            return "Package_cast";
        }
        if (section == 5) {
            return "ID";
        }
    }
    return {};
}


bool packagemodel::addPackage(const packageclass &newPackage)
{
    beginInsertRows(QModelIndex(), m_packages.size(), m_packages.size());
    m_packages.append(newPackage);
    UsingDataBase Base;
    m_packages = Base.getAllPackages();
    endInsertRows();
    return true;
}

bool packagemodel::updateData()
{
    beginResetModel();
    UsingDataBase Base;
    m_packages = Base.getAllPackages();
    endResetModel();
    return true;
}

int packagemodel::getPackageID(int row, const QModelIndex &parent) const
{
    return m_packages[row].ID;
}
