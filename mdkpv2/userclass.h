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
    int Display_mode;
    static UsersClass getUserFromString(QString line);
};

#endif // USERSCLASS_H
