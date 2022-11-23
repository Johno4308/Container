//COS3711 ASSIGNMENT 3
//Johnathan David Cookson 8812125074088
//8812125074088
#ifndef FACTORY_H
#define FACTORY_H
#include "container.h"
//#include "containermomento.h"

//factory class to create instances on box and cylinder
class Factory
{
//    friend containerMomento;
public:
    Factory();
    static Container* createInstance(int height, int weight, int volume, QString code, int length, int width);
    static Container* createInstance(int height, int weight, int volume, QString code, int diameter);
};

#endif // FACTORY_H
