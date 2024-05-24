#ifndef USINGDATABASE_H
#define USINGDATABASE_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include "userclass.h"
#include <QObject>
#include <QVector>
#include "packageclass.h"

class UsingDataBase : public QObject
{
        Q_OBJECT
public:
    explicit UsingDataBase(QObject *parent = nullptr);
    static QString FindUserRole(QString login, QString password);
    static bool FindClient(QString login, QString password);
    static UsersClass GetUserFromDB(QString login, QString password);
    static QVector<UsersClass> GetAllEmployees();
    static QVector<UsersClass> GetAllClients();
    static void DataBaseConnection();
    static QVector<packageclass> getAllPackages();
    static void DeleteEmployee(QString login);
    static void DeletePackage(int ID);
    static bool takeUserToDB(UsersClass object);
    static bool takePackageToDB(packageclass object);
};

#endif // USINGDATABASE_H
