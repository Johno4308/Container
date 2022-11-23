//COS3711 ASSIGNMENT 3
//Johnathan David Cookson 8812125074088
//8812125074088
#include "containerlist.h"
#include <QDebug>
#include <QMetaObject>
#include <QMetaProperty>
#include "factory.h"


ContainerList::ContainerList()
{}


void ContainerList::addContainer(Container *container)
{
    containerList.append(container);
}

void ContainerList::clear()
{
    int row = containerList.size();
    if(row > 0)
    {
        qDeleteAll(containerList);
        containerList.clear();
    }
}

QList<Container *> &ContainerList::getList()
{
    return containerList;
}

void ContainerList::setList(QList<Container *> list)
{
    QString className;
    Container *copyContainer;
    Factory containerFactory;

    clear();

    for(int count = 0; count < list.count(); count++)
    {
        className = list.at(count)->metaObject()->className();

        if(className == "Box")
        {
            copyContainer = containerFactory.createInstance(list.at(count)->getHeight(),
                                             list.at(count)->getWeight(),
                                             list.at(count)->getVolume(),
                                             list.at(count)->getCode(),
                                             list.at(count)->getLength(),
                                             list.at(count)->getWidth());
            if(copyContainer != nullptr)
            {
                addContainer(copyContainer);
            }
        }
        else if(className == "Cylinder")
        {
            copyContainer = containerFactory.createInstance(list.at(count)->getHeight(),
                                             list.at(count)->getWeight(),
                                             list.at(count)->getVolume(),
                                             list.at(count)->getCode(),
                                             list.at(count)->getDiameter());
            if(copyContainer != nullptr)
            {
                addContainer(copyContainer);
            }
        }
    }
}

int ContainerList::getSize() const
{
    return containerList.size();
}

Container *ContainerList::getContainer(int location)
{
    return containerList.at(location);
}






































