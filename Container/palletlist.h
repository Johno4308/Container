//COS3711 ASSIGNMENT 3
//Johnathan David Cookson 8812125074088
//8812125074088
#ifndef PALLETLIST_H
#define PALLETLIST_H

#include "pallet.h"
#include <QList>

//palletlist class that appends pallets to a list
class PalletList
{
public:
    PalletList();
    ~PalletList();
    //standard list functions
    void addPallet(Pallet *pallet);
    void removePallet(Pallet *pallet);
    int getSize() const;
    Pallet *getPallet(int index) const;
    void clear();
    void setPalletList(PalletList* palletList);

private:
    QList<Pallet*> _palletList;

};

#endif // PALLETLIST_H
