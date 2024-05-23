#ifndef USERSCLASS_H
#define USERSCLASS_H
#include <QString>

class UsersClass
{
public:
    QString Name;
    QString Email;
    QString Phone;
    QString Password;
    QString Role;
    static UsersClass getUserFromString(QString line);
};

#endif // USERSCLASS_H
