//COS3711 ASSIGNMENT 3
//Johnathan David Cookson 8812125074088
//8812125074088
#ifndef CONTAINERLIST_H
#define CONTAINERLIST_H


#include "container.h"

//list used to append containers.
#include <QList>
class ContainerList
{
public:
    ContainerList();

    void addContainer(Container *container); // right one
    void clear();
    QList<Container*> &getList();
    void setList(QList<Container*> list);
    int getSize() const;
    Container *getContainer(int location);

private:
      QList<Container*> containerList;


};



#endif // CONTAINERLIST_H
