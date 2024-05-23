#include "userclass.h"
#include <QString>

UsersClass UsersClass::getUserFromString(QString line)
{
    UsersClass current_user;
    QString current_string;
    int counter = 0;
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == ',' && counter == 0)
        {
            current_user.Name = current_string;
            current_string = "";
            counter += 1;
            continue;
        }
        if (line[i] == ',' && counter == 1)
        {
            current_user.Email = current_string;
            current_string = "";
            counter += 1;
            continue;
        }
        if (line[i] == ',' && counter == 2)
        {
            current_user.Phone = current_string;
            current_string = "";
            counter += 1;
            continue;
        }
        if (line[i] == ',' && counter == 3)
        {
            current_user.Password = current_string;
            current_string = "";
            counter += 1;
            continue;
        }
        if (line[i] != ',')
        {
            current_string += line[i];
        }
        if (counter == 4 && (i == (line.length()-1)))
        {
            current_user.Role = current_string;
            continue;
        }
    }
    return current_user;
}
