//COS3711 ASSIGNMENT 3
//Johnathan David Cookson 8812125074088
//8812125074088
#ifndef CONTAINER_H
#define CONTAINER_H
#include <QObject>

class Factory;

//container class that has virtual functions for box and cylinder
class Container : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int weight READ getWeight CONSTANT)
    Q_PROPERTY(int height READ getHeight CONSTANT)
    Q_PROPERTY(int volume READ getVolume CONSTANT)
    Q_PROPERTY(QString code READ getCode CONSTANT)

public:
    Container(int height, int weight, int volume, QString code);
    virtual ~Container();

    int getWeight() const;
    int getUnique_num() const;
    int getHeight() const;
    int getVolume() const;

    virtual int getDiameter() const =0;
    virtual int getLength() const =0;
    virtual int getWidth() const =0;


    QString getCode() const;


private:
    int _height,
        _weight,
        _volume;
    QString _code;
};

#endif // CONTAINER_H


