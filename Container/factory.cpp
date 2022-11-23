//COS3711 ASSIGNMENT 3
//Johnathan David Cookson 8812125074088
//8812125074088
#include "factory.h"
#include "box.h"
#include "cylinder.h"


Factory::Factory()
{}

Container *Factory::createInstance(int height, int weight, int volume, QString code, int length, int width)
{
    return new Box(height, weight, volume, code, length, width);
}

Container *Factory::createInstance(int height, int weight, int volume, QString code, int diameter)
{
    return new Cylinder(height, weight, volume, code, diameter);
}


