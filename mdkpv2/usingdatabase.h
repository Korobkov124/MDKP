#ifndef USINGDATABASE_H
#define USINGDATABASE_H
#include <QSqlDatabase>
#include <QSqlQuery>

class UsingDataBase
{
public:
    QSqlDatabase users_db = QSqlDatabase::addDatabase("QSQLITE");;
    QSqlQuery query;
    QString FindUserRole(QString login, QString password);
    bool FindClient(QString login, QString password);
};

#endif // USINGDATABASE_H
