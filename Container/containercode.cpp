//COS3711 ASSIGNMENT 3
//Johnathan David Cookson 8812125074088
//8812125074088
#include "containercode.h"

ContainerCode::ContainerCode()
{}

QString ContainerCode::createCode(char Type, int uniqueNum)
{
        QString containerCode;
        char slash = '/';
        QDate date = QDate::currentDate();
        QString Month;
        int year = date.year();
        int month = date.month();

        if(month < 10)
        {
           Month = "0";
           QString x = QString::number(month);
           Month.append(x);
        }
        else
        {
            Month = QString::number(month);
        }
        QString Year = QString::number(year);
        QString UniqueC = QString::number(uniqueNum);

        containerCode.append(Year);
        containerCode.append(slash);
        containerCode.append(Month);
        containerCode.append(slash);
        containerCode.append(Type);
        containerCode.append(UniqueC);

        return containerCode;
}



void ContainerCode::setCode(QString code)
{
    _code = code;
}




