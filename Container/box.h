//COS3711 ASSIGNMENT 3
//Johnathan David Cookson 8812125074088
//8812125074088
#ifndef BOX_H
#define BOX_H
#include "container.h"

//my Box class that inherits from container
class Box : public Container
{
    Q_OBJECT
    Q_PROPERTY(int length READ getLength CONSTANT)
    Q_PROPERTY(int width READ getWidth CONSTANT)

public:
    virtual ~Box();
    Box(int height, int weight, int volume, QString code, int length, int width);

    int getLength() const;
    int getWidth() const;
    int getDiameter() const;
    QString getContainerCode();

private:
    int _length,
        _width;
    QString _code;

};

#endif // BOX_H
