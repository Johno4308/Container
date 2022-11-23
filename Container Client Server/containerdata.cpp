//COS3711 Assignment 3
//Johnathan David Cookson 45051429
//8812125074088
#include "containerdata.h"

ContainerData::ContainerData()
{

}
//overload constructor
ContainerData::ContainerData(QString pallet, QString containerType, QString code, QString height, QString breadthDiameter, QString length, QString weight)
{
    _Pallet = pallet;
    _ContainerType = containerType;
    _Code = code;
    _Height = height;
    _breadthDiameter = breadthDiameter;
    _Length = length;
    _Weight = weight;
}

//getters
QString ContainerData::getPallet()
{
    return _Pallet;
}

QString ContainerData::getContainerType()
{
    return _ContainerType;
}

QString ContainerData::getCode()
{
    return _Code;
}

QString ContainerData::getHeight()
{
    return _Height;
}

QString ContainerData::getBreadthDiameter()
{
    return _breadthDiameter;
}

QString ContainerData::getWeight()
{
    return _Weight;
}

QString ContainerData::getLength()
{
    return _Length;
}



