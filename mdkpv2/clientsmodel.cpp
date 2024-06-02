#include "clientsmodel.h"
#include "usingdatabase.h"

clientsmodel::clientsmodel(QObject *parent) : QAbstractTableModel{parent}
{
    UsingDataBase Base;
    m_clients = Base.GetAllClients();
}

int clientsmodel::rowCount(const QModelIndex &parent) const
{
    return m_clients.size();
}

int clientsmodel::columnCount(const QModelIndex &parent) const
{
    return 5;
}

QVariant clientsmodel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        if (index.column() == 0 && m_clients[index.row()].Display_mode == 1) {
            return m_clients[index.row()].Name;
        }
        if (index.column() == 1 && m_clients[index.row()].Display_mode == 1) {
            return m_clients[index.row()].Email;
        }
        if (index.column() == 2 && m_clients[index.row()].Display_mode == 1) {
            return m_clients[index.row()].Phone;
        }
        if (index.column() == 3 && m_clients[index.row()].Display_mode == 1) {
            return m_clients[index.row()].Password;
        }
        if (index.column() == 4 && m_clients[index.row()].Display_mode == 1) {
            return m_clients[index.row()].Role;
        }
    }
    return {};
}

QVariant clientsmodel::headerData(int section, Qt::Orientation orientation, int role) const
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
