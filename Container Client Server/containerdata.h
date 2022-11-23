//COS3711 Assignment 3
//Johnathan David Cookson 45051429
//8812125074088
#ifndef CONTAINERDATA_H
#define CONTAINERDATA_H
#include <QString>

//class to store all incoming QByteArray data
class ContainerData
{
public:
    ContainerData();
    ContainerData(QString pallet, QString containerType, QString code, QString height, QString breadthDiameter, QString length, QString weight);
    QString getPallet();
    QString getContainerType();
    QString getCode();
    QString getHeight();
    QString getBreadthDiameter();
    QString getLength();
    QString getWeight();

private:
    QString _Pallet;
    QString _ContainerType;
    QString _Code;
    QString _Height;
    QString _breadthDiameter;
    QString _Length;
    QString _Weight;
};

#endif // CONTAINERDATA_H
