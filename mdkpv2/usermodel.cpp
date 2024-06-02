#include "usermodel.h"
#include "usingdatabase.h"

usermodel::usermodel(QObject *parent) : QAbstractTableModel{parent}
{
    UsingDataBase Base;
    m_users = Base.GetAllEmployees();
}

int usermodel::rowCount(const QModelIndex &parent) const
{
    return m_users.size();
}

int usermodel::columnCount(const QModelIndex &parent) const
{
    return 5;
}

QVariant usermodel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        if (index.column() == 0 && m_users[index.row()].Display_mode == 1) {
            return m_users[index.row()].Name;
        }
        if (index.column() == 1 && m_users[index.row()].Display_mode == 1) {
            return m_users[index.row()].Email;
        }
        if (index.column() == 2 && m_users[index.row()].Display_mode == 1) {
            return m_users[index.row()].Phone;
        }
        if (index.column() == 3 && m_users[index.row()].Display_mode == 1) {
            return m_users[index.row()].Password;
        }
        if (index.column() == 4 && m_users[index.row()].Display_mode == 1) {
            return m_users[index.row()].Role;
        }
    }
    return {};
}

QVariant usermodel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Vertical) {
        return section;
    }

    if (role == Qt::DisplayRole) {
        if (section == 0) {
            return "Name";
        }
        if (section == 1) {
            return "Email";
        }
        if (section == 2) {
            return "Phone";
        }
        if (section == 3) {
            return "Password";
        }
        if (section == 4) {
            return "Role";
        }
    }
    return {};
}

bool usermodel::removeRow(int row, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row);
    UsingDataBase Base;
    Base.DeleteEmployee(m_users[row].Email);
    m_users.removeAt(row);
    endRemoveRows();
    return true;
}

bool usermodel::addUser(const UsersClass& newUser)
{
    beginInsertRows(QModelIndex(), m_users.size(), m_users.size());
    m_users.append(newUser);
    UsingDataBase Base;
    m_users = Base.GetAllEmployees();
    endInsertRows();
    return true;
}

bool usermodel::updateData()
{
    beginResetModel();
    UsingDataBase Base;
    m_users = Base.GetAllEmployees();
    endResetModel();
    return true;
}

