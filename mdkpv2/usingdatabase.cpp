#include "usingdatabase.h"
#include <QMessageBox>
#include <QDebug>

UsingDataBase::UsingDataBase(QObject *parent) : QObject{parent} {}

void UsingDataBase::DataBaseConnection()
{
    QSqlDatabase db;
    const QString database = "./users_bd.db";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(database);
    if(!db.open())
    {
        qDebug() << "DataBase is not open!";
    }
    else
    {
        qDebug() << "DataBase is open!";
    }
}

QVector<packageclass> UsingDataBase::getAllPackages()
{
    QVector<packageclass> packages;
    class packageclass package;
    QSqlQuery query;
    query.exec("SELECT * FROM Packages");
    while (query.next())
    {
        package.Country_name = query.value(0).toString();
        package.Hotel_name = query.value(1).toString();
        package.Cost_for_week = query.value(2).toInt();
        package.Week_cast = query.value(3).toInt();
        package.Package_cast = query.value(4).toInt();
        package.ID = query.value(5).toInt();
        packages.append(package);
    }
    return packages;
}

void UsingDataBase::DeleteEmployee(QString login)
{
    QSqlQuery query;
    query.prepare("DELETE FROM Users WHERE Email = :login");
    query.bindValue(":login", login);
    query.exec();
}

void UsingDataBase::DeletePackage(int ID)
{
    QSqlQuery query;
    query.prepare("DELETE FROM Packages WHERE ID = :ID");
    query.bindValue(":ID", ID);
    query.exec();
}

bool UsingDataBase::takeUserToDB(UsersClass object)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Users VALUES(:Name, :Email, :Phone, :Password, :Role)");
    query.bindValue(":Name", object.Name);
    query.bindValue(":Email", object.Email);
    query.bindValue(":Phone", object.Phone);
    query.bindValue(":Password", object.Password);
    query.bindValue(":Role", object.Role);
    query.exec();
    return true;
}

bool UsingDataBase::takePackageToDB(packageclass object)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Packages VALUES(:Country_name, :Hotel_name, :Cost_of_week, :Week_cast, :Packages_cast, :ID)");
    query.bindValue(":Country_name", object.Country_name);
    query.bindValue(":Hotel_name", object.Hotel_name);
    query.bindValue(":Cost_of_week", object.Cost_for_week);
    query.bindValue(":Week_cast", object.Week_cast);
    query.bindValue(":Packages_cast", object.Package_cast);
    query.bindValue(":ID", object.ID);
    query.exec();
    query.finish();
    if(true)
    {
        return true;
    }
}

bool UsingDataBase::getEmailFromDB(QString Email)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM Users WHERE Email = :Email");
    query.bindValue(":Email", Email);
    if (query.exec() && query.first())
    {
        int count = query.value(0).toInt();
        return count > 0;
    }
    else
    {
        return false;
    }
}

UsersClass UsingDataBase::getUserWithEmail(QString Email)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM Users WHERE Email = :Email");
    query.bindValue(":Email", Email);
    query.exec();
    while(query.next())
    {
        UsersClass user;
        user.Name = query.value(0).toString();
        user.Email = query.value(1).toString();
        user.Phone = query.value(2).toString();
        user.Password = query.value(3).toString();
        user.Role = query.value(4).toString();
        return user;
    }
}

bool UsingDataBase::updateDataIntoUser(QString Email, QString NewName, QString NewEmail, QString NewPhone, QString NewPassword, QString NewRole)
{
    QSqlQuery query;
    query.prepare("UPDATE Users SET Name = :NewName, Email = :NewEmail, Phone = :NewPhone, Password = :NewPassword, Role = :NewRole WHERE Email = :Email");
    query.bindValue(":Email", Email);
    query.bindValue(":NewName", NewName);
    query.bindValue(":NewEmail", NewEmail);
    query.bindValue(":NewPhone", NewPhone);
    query.bindValue(":NewPassword", NewPassword);
    query.bindValue(":NewRole", NewRole);
    query.exec();
    return true;
}

int UsingDataBase::findBiggestIdOfPackage()
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM Packages");
    if(query.exec() && query.first())
    {
        int count = query.value(0).toInt();
        return count;
    }
    else
    {
        return 1;
    }
}

packageclass UsingDataBase::findPackageWithID(int ID)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM Packages WHERE ID = :ID");
    query.bindValue(":ID", ID);
    query.exec();
    while(query.next())
    {
        packageclass package;
        package.Country_name = query.value(0).toString();
        package.Hotel_name = query.value(1).toString();
        package.Cost_for_week = query.value(2).toInt();
        package.Week_cast = query.value(3).toInt();
        package.Package_cast = query.value(4).toInt();
        return package;
    }

}

void UsingDataBase::updateDataIntoPackage(int ID, QString Country, QString Hotel, int Cost, int Weekcast, int Packcast)
{
    QSqlQuery query;
    query.prepare("UPDATE Packages SET Country = :Country, Hotel = :Hotel, Cost_for_week = :Cost, Week_cast = :Weekcast, Packages_cast = :Packcast WHERE ID = :ID");
    query.bindValue(":Country", Country);
    query.bindValue(":Hotel", Hotel);
    query.bindValue(":Cost", Cost);
    query.bindValue(":Weekcast", Weekcast);
    query.bindValue(":Packcast", Packcast);
    query.bindValue(":ID", ID);
    query.exec();
}

QString UsingDataBase::FindUserRole(QString login, QString password)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM Users WHERE Email = :login and Password = :password");
    query.bindValue(":login", login);
    query.bindValue(":password", password);
    query.exec();
    while(query.next())
    {
        if(query.value(4).toString() == "moder")
        {
            return "moder";
        }
        if(query.value(4).toString() == "admin")
        {
            return "admin";
        }
        if (query.value(4).toString() == "client")
        {
            return "client";
        }
    }
}

bool UsingDataBase::FindClient(QString login, QString password)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM Users WHERE Email = :login and password = :password");
    query.bindValue(":login", login);
    query.bindValue(":password", password);
    query.exec();
    while(query.next())
    {
        return true;
    }
}

UsersClass UsingDataBase::GetUserFromDB(QString login, QString password)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM Users WHERE Email = :login and password = :password");
    query.bindValue(":login", login);
    query.bindValue(":password", password);
    query.exec();
    if(query.first())
    {
        UsersClass user;
        user.Name = query.value(0).toString();
        user.Email = query.value(1).toString();
        user.Phone = query.value(2).toString();
        user.Password = query.value(3).toString();
        user.Role = query.value(4).toString();
        return user;
    }
}

QVector<UsersClass> UsingDataBase::GetAllEmployees()
{
    QVector<UsersClass> users;
    class UsersClass user;
    QSqlQuery query;
    query.exec("SELECT * FROM Users WHERE Role = 'admin' OR Role = 'moder'");
    while (query.next())
    {
        user.Name = query.value(0).toString();
        user.Email = query.value(1).toString();
        user.Phone = query.value(2).toString();
        user.Password = query.value(3).toString();
        user.Role = query.value(4).toString();
        users.append(user);
    }
    return users;
}

QVector<UsersClass> UsingDataBase::GetAllClients()
{
    QVector<UsersClass> users;
    class UsersClass user;
    QSqlQuery query;
    query.exec("SELECT * FROM Users WHERE Role = 'client'");
    while (query.next())
    {
        user.Name = query.value(0).toString();
        user.Email = query.value(1).toString();
        user.Phone = query.value(2).toString();
        user.Password = query.value(3).toString();
        user.Role = query.value(4).toString();
        users.append(user);
    }
    return users;
}
