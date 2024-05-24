#include "packageclass.h"
#include <QString>

packageclass packageclass::getPackageFromString(QString line)
{
    packageclass current_package;
    QString current_string;
    int counter = 0;
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == ',' && counter == 0)
        {
            current_package.Country_name = current_string;
            current_string = "";
            counter += 1;
            continue;
        }
        if (line[i] == ',' && counter == 1)
        {
            current_package.Hotel_name = current_string;
            current_string = "";
            counter += 1;
            continue;
        }
        if (line[i] == ',' && counter == 2)
        {
            current_package.Cost_for_week = current_string.toInt();
            current_string = "";
            counter += 1;
            continue;
        }
        if (line[i] == ',' && counter == 3)
        {
            current_package.Week_cast = current_string.toInt();
            current_string = "";
            counter += 1;
            continue;
        }
        if (line[i] == ',' && counter == 4)
        {
            current_package.Package_cast = current_string.toInt();
            current_string = "";
            counter += 1;
            continue;
        }
        if (line[i] != ',')
        {
            current_string += line[i];
        }
        if (counter == 5 && (i == (line.length()-1)))
        {
            current_package.ID = current_string.toInt();
            continue;
        }
    }
    return current_package;
}

