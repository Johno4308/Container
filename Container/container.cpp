//COS3711 ASSIGNMENT 3
//Johnathan David Cookson 8812125074088
//8812125074088
#include "container.h"

Container::Container(int Height, int Weight, int Volume, QString Code):
    _height{Height},
    _weight{Weight},
    _volume{Volume},
    _code{Code}
{}

Container::~Container()
{}

int Container::getWeight() const
{
    return _weight;
}

int Container::getHeight() const
{
    return _height;
}

int Container::getVolume() const
{
    return _volume;
}

QString Container::getCode() const
{
    return _code;
}




