#include "usingdatabase.h"
#include <QMessageBox>

QString UsingDataBase::FindUserRole(QString login, QString password)
{
    users_db.setDatabaseName("./users_bd.db");
    if (users_db.isOpen())
    {
        qDebug() << "OPEN";
    }
    else
    {
        users_db.open();
        qDebug() << "IS OPEN NOW";
    }
    query.prepare("SELECT * FROM employees WHERE Email = :login and Password = :password");
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
    }
}

bool UsingDataBase::FindClient(QString login, QString password)
{
    users_db.setDatabaseName("./users_bd.db");
    if (users_db.isOpen())
    {
        qDebug() << "OPEN";
    }
    else
    {
        users_db.open();
        qDebug() << "IS OPEN NOW";
    }
    query.prepare("SELECT * FROM clients WHERE Email = :login and password = :password");
    query.bindValue(":login", login);
    query.bindValue(":password", password);
    query.exec();
    while(query.next())
    {
        return true;
    }
}
