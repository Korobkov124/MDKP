#ifndef USINGDATABASE_H
#define USINGDATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include "userclass.h"
#include <QObject>
#include <QVector>
#include "packageclass.h"
#include "buyedpackageclass.h"

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
    static bool getEmailFromDB(QString Email);
    static UsersClass getUserWithEmail(QString Email);
    static bool updateDataIntoUser(QString Email, QString NewName, QString NewEmail, QString NewPhone, QString NewPassword, QString NewRole);
    static int findBiggestIdOfPackage();
    static packageclass findPackageWithID(int ID);
    static void updateDataIntoPackage(int ID, QString Country, QString Hotel, int Cost, int Weekcast, int Packcast);
    static QVector<BuyedPackageClass> getBuyedPackages(QString Email);
    static QVector<QString> getCountryHotelTotalCost(int ID);
};

#endif // USINGDATABASE_H
