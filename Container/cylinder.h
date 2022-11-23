//COS3711 ASSIGNMENT 3
//Johnathan David Cookson 8812125074088
//8812125074088
#ifndef CYLINDER_H
#define CYLINDER_H
#include "container.h"

class Factory;
//cylinder class that inherits from container
class Cylinder : public Container
{
    Q_OBJECT
    friend class Factory;

    Q_PROPERTY(int diameter READ getDiameter CONSTANT)

public:
    virtual ~Cylinder();
    Cylinder(int height, int weight, int volume, QString code, int diameter);

    int getLength() const;
    int getWidth() const;
    int getDiameter() const;

private:
    int c_diameter;


};

#endif // CYLINDER_H
