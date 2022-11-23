//COS3711 ASSIGNMENT 3
//Johnathan David Cookson 8812125074088
//8812125074088
#ifndef CONTAINERCARETAKER_H
#define CONTAINERCARETAKER_H

#include "containermomento.h"

//Ron said we must create this for the assignment,
//I didnt call it as only 1 instance of backup/restore was required
class ContainerCareTaker
{
public:
    ContainerCareTaker();

    void requestMemento(containerMomento *memento);
    containerMomento* restoreMemento();
    bool mementoAvaliable();

private:
    QList<containerMomento*> mementos;
    bool isMemento;
};

#endif // CONTAINERCARETAKER_H
