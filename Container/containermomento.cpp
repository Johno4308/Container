//COS3711 ASSIGNMENT 3
//Johnathan David Cookson 8812125074088
//8812125074088
#include "containermomento.h"
#include "factory.h"


containerMomento::~containerMomento()
{
}

containerMomento::containerMomento()
{
    qDeleteAll(state);
}

void containerMomento::setState(QList<Container*> inState)
{
    QString className;
    Container *copyContainer;
    Factory containerFactory;

    state.clear();

    for(int count = 0; count < inState.count(); count++)
    {
        className = inState.at(count)->metaObject()->className();

        if(className == "Box")
        {
            copyContainer = containerFactory.createInstance(inState.at(count)->getHeight(),
                                             inState.at(count)->getWeight(),
                                             inState.at(count)->getVolume(),
                                             inState.at(count)->getCode(),
                                             inState.at(count)->getLength(),
                                             inState.at(count)->getWidth());
            if(copyContainer != nullptr)
            {
                state.append(copyContainer);
            }
        }
        else if(className == "Cylinder")
        {
            copyContainer = containerFactory.createInstance(inState.at(count)->getHeight(),
                                             inState.at(count)->getWeight(),
                                             inState.at(count)->getVolume(),
                                             inState.at(count)->getCode(),
                                             inState.at(count)->getDiameter());
            if(copyContainer != nullptr)
            {
                state.append(copyContainer);
            }
        }

    }
}



QList<Container *> containerMomento::getState()
{
    return state;
}
