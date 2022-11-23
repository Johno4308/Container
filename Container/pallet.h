//COS3711 ASSIGNMENT 3
//Johnathan David Cookson 8812125074088
//8812125074088
#ifndef PALLET_H
#define PALLET_H
#include <QObject>

#include <QList>
class Container;
class ContainerList;

//pallet class that assignments n number of containers to a pallet and its spin box number
class Pallet : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Container p_container READ getContainer CONSTANT)
    Q_PROPERTY(int p_palletWeight READ getPalletWeight CONSTANT)
    Q_PROPERTY(int p_palletVolume READ getPalletVolume CONSTANT)

public:
    Pallet* setContainer(Container *container, int number);
    Pallet(Container *container, int palletNumber, int palletWeight, int palletVolume); //new code
    int getSize() const;
    void addContainer(Container* container);


    Container* getContainer(int index) const;//new code
    Container* getContainer() const;
    int getPalletNumber() const;
    int getPalletWeight() const;//new code
    int getPalletVolume() const;//new code

private:

    void setPalletWeight(int palletWeight);
    void setPalletVolume(int palletVolume);
    void setPalletNumber(int palletNumber);

    int p_palletNumber;
    int p_palletWeight;//new code
    int p_palletVolume;//new code
    Container *p_container; //new code
    ContainerList *_containerList;

};


#endif // PALLET_H
