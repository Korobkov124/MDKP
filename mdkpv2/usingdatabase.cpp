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
    if (!db.tables().contains("Users"))
    {
        QSqlQuery query;
        query.exec("CREATE TABLE Users (name TEXT, Email TEXT PRIMARY KEY, Phone TEXT, Password TEXT, Role TEXT, Display_mode INTEGER);");
        query.exec("INSERT INTO Users VALUES('Andrey', 'RKN@mail.ru', '+7(902)9705032', 'Kirill123', 'moder', 1)");
    }
    if (!db.tables().contains("Packages"))
    {
        QSqlQuery query;
        query.exec("CREATE TABLE Packages (Country TEXT, Hotel TEXT, Cost_for_week INTEGER, Week_cast INTEGER, Packages_cast INTEGER, ID INTEGER PRIMARY KEY, Display_mode  INTEGER);");
    }
    if (!db.tables().contains("Buyed_packages"))
    {
        QSqlQuery query;
        query.exec("CREATE TABLE Buyed_packages (ID INTEGER PRIMARY KEY, ID_package INTEGER REFERENCES Packages (ID), Email_user TEXT REFERENCES Users (Email), Quantity_of_packages INTEGER);");
    }
}

QVector<packageclass> UsingDataBase::getAllPackages()
{
    QVector<packageclass> packages;
    class packageclass package;
    QSqlQuery query;
    query.exec("SELECT * FROM Packages");
    while(query.next())
    {
        package.Country_name = query.value(0).toString();
        package.Hotel_name = query.value(1).toString();
        package.Cost_for_week = query.value(2).toInt();
        package.Week_cast = query.value(3).toInt();
        package.Package_cast = query.value(4).toInt();
        package.ID = query.value(5).toInt();
        package.Display_mode = query.value(6).toInt();
        if (package.Display_mode == 1)
        {
            packages.append(package);
        }
    }
    return packages;
}

void UsingDataBase::DeleteEmployee(QString login)
{
    QSqlQuery query;
    query.prepare("UPDATE Users SET Display_mode = 0 WHERE Email = :login");
    query.bindValue(":login", login);
    query.exec();
}

void UsingDataBase::DeletePackage(int ID)
{
    QSqlQuery query;
    query.prepare("UPDATE Packages SET Display_mode = 0 WHERE ID = :ID");
    query.bindValue(":ID", ID);
    query.exec();
}

bool UsingDataBase::takeUserToDB(UsersClass object)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Users VALUES(:Name, :Email, :Phone, :Password, :Role, 1)");
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
    query.prepare("INSERT INTO Packages VALUES(:Country_name, :Hotel_name, :Cost_of_week, :Week_cast, :Packages_cast, :ID, :Display_mode)");
    query.bindValue(":Country_name", object.Country_name);
    query.bindValue(":Hotel_name", object.Hotel_name);
    query.bindValue(":Cost_of_week", object.Cost_for_week);
    query.bindValue(":Week_cast", object.Week_cast);
    query.bindValue(":Packages_cast", object.Package_cast);
    query.bindValue(":ID", object.ID);
    query.bindValue(":Display_mode", 1);
    query.exec();
    return true;
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
        user.Display_mode = query.value(5).toInt();
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
    query.prepare("SELECT * FROM Packages WHERE ID = :ID AND Display_mode = 1");
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
        package.ID = ID;
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

QVector<BuyedPackageClass> UsingDataBase::getBuyedPackages(QString Email)
{
    QVector<BuyedPackageClass> BuyedPackages;
    class BuyedPackageClass package;
    QSqlQuery query;
    query.prepare("SELECT * FROM Buyed_packages WHERE Email_user = :Email");
    query.bindValue(":Email", Email);
    query.exec();
    while(query.next())
    {
        package.ID = query.value(0).toInt();
        package.ID_package = query.value(1).toInt();
        package.Email_user = query.value(2).toString();
        package.Quantity_of_packages = query.value(3).toInt();
        QVector<QString> params = UsingDataBase::getCountryHotelTotalCost(package.ID_package);
        package.Country_name = params[0];
        package.Hotel_name = params[1];
        package.TotalCost = (params[2].toInt() * params[3].toInt() * package.Quantity_of_packages);
        BuyedPackages.append(package);
    }
    return BuyedPackages;
}

QVector<QString> UsingDataBase::getCountryHotelTotalCost(int ID)
{
    QSqlQuery query;
    query.prepare("SELECT Country, Hotel, Cost_for_week, Week_cast FROM Packages WHERE ID = :ID");
    query.bindValue(":ID", ID);
    query.exec();
    while(query.next())
    {
        QVector<QString> params;
        QString Country = query.value(0).toString();
        params.append(Country);
        QString Hotel = query.value(1).toString();
        params.append(Hotel);
        int Cost_for_week = query.value(2).toInt();
        params.append(QString::number(Cost_for_week));
        int Week_cast = query.value(3).toInt();
        params.append(QString::number(Week_cast));
        return params;
    }
}

bool UsingDataBase::getPasswordFromDB(QString Password)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM Users WHERE Password = :Password");
    query.bindValue(":Password", Password);
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

bool UsingDataBase::getPackageBuyed(int ID_package, QString Email_user, int Quantity_of_packages)
{
    QSqlQuery query;
    packageclass package1 = UsingDataBase::findPackageWithID(ID_package);
    if (package1.Package_cast > Quantity_of_packages)
    {
        int pack_diff = package1.Package_cast - Quantity_of_packages;
        query.prepare("UPDATE Packages SET Packages_cast = :pack_diff WHERE ID = :ID_package");
        query.bindValue(":pack_diff", pack_diff);
        query.bindValue(":ID_package", ID_package);
        query.exec();
        QSqlQuery query1;
        int buyed_package_id = (UsingDataBase::findBiggestIdOfBuyedPackage() + 1);
        query1.prepare("INSERT INTO Buyed_packages VALUES(:buyed_package_id, :ID_package, :Email_user, :Quantity_of_packages)");
        query1.bindValue(":buyed_package_id", buyed_package_id);
        query1.bindValue(":ID_package", ID_package);
        query1.bindValue(":Email_user", Email_user);
        query1.bindValue(":Quantity_of_packages", Quantity_of_packages);
        query1.exec();
        return true;
    }
    if (package1.Package_cast == Quantity_of_packages)
    {
        query.prepare("UPDATE Packages SET Packages_cast = 0, Display_mode = 0 WHERE ID = :ID_package");
        query.bindValue(":ID_package", ID_package);
        query.exec();
        QSqlQuery query1;
        int buyed_package_id = (UsingDataBase::findBiggestIdOfBuyedPackage() + 1);
        query1.prepare("INSERT INTO Buyed_packages VALUES(:buyed_package_id, :ID_package, :Email_user, :Quantity_of_packages)");
        query1.bindValue(":buyed_package_id", buyed_package_id);
        query1.bindValue(":ID_package", ID_package);
        query1.bindValue(":Email_user", Email_user);
        query1.bindValue(":Quantity_of_packages", Quantity_of_packages);
        query1.exec();
        return true;
    }
    return false;
}

int UsingDataBase::findBiggestIdOfBuyedPackage()
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM Buyed_packages");
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

QString UsingDataBase::FindUserRole(QString login, QString password)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM Users WHERE Email = :login and Password = :password and Display_mode = 1");
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
    return "empty";
}

bool UsingDataBase::FindClient(QString login, QString password)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM Users WHERE Email = :login and password = :password and Display_mode = 1");
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
    query.prepare("SELECT * FROM Users WHERE Email = :login and password = :password and Display_mode = 1");
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
        user.Display_mode = 1;
        return user;
    }
}

QVector<UsersClass> UsingDataBase::GetAllEmployees()
{
    QVector<UsersClass> users;
    class UsersClass user;
    QSqlQuery query;
    query.exec("SELECT * FROM Users WHERE (Display_mode = 1 AND Role = 'admin') OR (Display_mode = 1 AND Role = 'moder')");
    while (query.next())
    {
        user.Name = query.value(0).toString();
        user.Email = query.value(1).toString();
        user.Phone = query.value(2).toString();
        user.Password = query.value(3).toString();
        user.Role = query.value(4).toString();
        user.Display_mode = 1;
        users.append(user);
    }
    return users;
}

QVector<UsersClass> UsingDataBase::GetAllClients()
{
    QVector<UsersClass> users;
    class UsersClass user;
    QSqlQuery query;
    query.exec("SELECT * FROM Users WHERE Role = 'client' and Display_mode = 1");
    while (query.next())
    {
        user.Name = query.value(0).toString();
        user.Email = query.value(1).toString();
        user.Phone = query.value(2).toString();
        user.Password = query.value(3).toString();
        user.Role = query.value(4).toString();
        user.Display_mode = 1;
        users.append(user);
    }
    return users;
}
