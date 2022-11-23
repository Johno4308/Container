#include "palletlist.h"


PalletList::PalletList()
{}

PalletList::~PalletList()
{
    qDeleteAll(_palletList);
}

void PalletList::addPallet(Pallet *pallet)
{
    //compares the pallet number to the pallet number in the pallet list
    //if the pallet number matches the pallet number in the list the container
    // is added to the exsisting pallet
    //if the pallet does not match any of the number in the list the pallet is added as a new
    // pallet to the list
    for(int i = 0; i < _palletList.size(); i++)
    {
        if(_palletList[i]->getPalletNumber() == pallet->getPalletNumber()){
            _palletList.at(i)->addContainer(pallet->getContainer(0));
            return;
        }
    }
    if(pallet != nullptr)
    {
        _palletList.append(pallet);
    }
}

void PalletList::removePallet(Pallet *pallet)
{
    for(int i = 0; i < _palletList.size(); i++)
    {
        if(_palletList[i]->getPalletNumber() == pallet->getPalletNumber())
        {
            _palletList.removeAt(i);
            return;
        }
    }
}

int PalletList::getSize() const
{
    return _palletList.size();
}

Pallet *PalletList::getPallet(int index) const
{
    return _palletList.at(index);
}

void PalletList::clear()
{
    _palletList.clear();
}

void PalletList::setPalletList(PalletList *palletList)
{
    _palletList = palletList->_palletList;
}





