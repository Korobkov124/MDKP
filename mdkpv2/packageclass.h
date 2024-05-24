#ifndef PACKAGECLASS_H
#define PACKAGECLASS_H
#include <QString>

class packageclass
{
public:
    QString Country_name;
    QString Hotel_name;
    int Cost_for_week;
    int Week_cast;
    int Package_cast;
    int ID;
    packageclass getPackageFromString(QString line);
};

#endif // PACKAGECLASS_H
