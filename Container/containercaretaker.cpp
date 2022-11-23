//COS3711 ASSIGNMENT 3
//Johnathan David Cookson 8812125074088
//8812125074088
#include "containercaretaker.h"

ContainerCareTaker::ContainerCareTaker()
{
}

void ContainerCareTaker::requestMemento(containerMomento *memento)
{
    mementos.append(memento);

    if(mementos.count() > 5)
    {
        mementos.removeLast();
    }
}

containerMomento *ContainerCareTaker::restoreMemento()
{
    if(mementos.count() > 1){
        isMemento = true;
    }else{
      isMemento = false;
    }

    if(!mementos.isEmpty()){
    return mementos.takeFirst();
    }
    return nullptr;
}

bool ContainerCareTaker::mementoAvaliable()
{
    return isMemento;
}
