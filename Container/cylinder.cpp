//COS3711 ASSIGNMENT 3
//Johnathan David Cookson 8812125074088
//8812125074088
#include "cylinder.h"

Cylinder::~Cylinder()
{}


Cylinder::Cylinder(int height, int weight, int volume, QString code, int diameter):
    Container{height, weight, volume, code},
    c_diameter{diameter}
{}

int Cylinder::getLength() const
{
    return 0;
}

int Cylinder::getWidth() const
{
    return 0;
}

int Cylinder::getDiameter() const
{
    return c_diameter;
}
