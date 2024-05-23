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
