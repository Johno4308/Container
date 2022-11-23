//COS3711 ASSIGNMENT 3
//Johnathan David Cookson 8812125074088
//8812125074088
#include "pallet.h"
#include <QDebug>
#include "container.h"
#include "containerlist.h"


Pallet* Pallet::setContainer(Container *container, int number)
{
    Pallet *pallet = nullptr;
    int palletWeight = 0, palletVolume = 0;
    palletWeight = container->getWeight();
    palletVolume = container->getVolume();
    pallet = new Pallet(container, number, palletWeight, palletVolume);
    return pallet;
}


Pallet::Pallet(Container *container, int palletNumber, int palletWeight, int palletVolume):
    p_palletNumber{palletNumber},
    p_palletWeight{palletWeight},
    p_palletVolume{palletVolume},
    p_container{container}
{

}

int Pallet::getSize() const
{
    return _containerList->getSize();
}

void Pallet::addContainer(Container *container)
{
    _containerList->addContainer(container);
    setPalletVolume(getPalletVolume() + container->getVolume());
    setPalletWeight(getPalletWeight() + container->getWeight());
}

Container *Pallet::getContainer(int index) const
{
    return _containerList->getContainer(index);
}

Container *Pallet::getContainer() const
{
    return p_container;
}

int Pallet::getPalletNumber() const
{
    return p_palletNumber;
}



int Pallet::getPalletWeight() const
{
    return p_palletWeight;
}

int Pallet::getPalletVolume() const
{
    return p_palletVolume;
}

void Pallet::setPalletWeight(int palletWeight)
{
    p_palletWeight = palletWeight;
}

void Pallet::setPalletVolume(int palletVolume)
{
    p_palletVolume = palletVolume;
}

void Pallet::setPalletNumber(int palletNumber)
{
    p_palletNumber = palletNumber;
}









