//COS3711 ASSIGNMENT 3
//Johnathan David Cookson 8812125074088
//8812125074088
#include "box.h"

Box::~Box()
{}

Box::Box(int height, int weight, int volume, QString code, int length, int width):
    Container{height, weight, volume, code},
    _length{length},
    _width{width}
{}

int Box::getLength() const
{
    return _length;
}

int Box::getWidth() const
{
    return _width;
}

int Box::getDiameter() const
{
    return 0;
}

QString Box::getContainerCode()
{
    return _code;
}

