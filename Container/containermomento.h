//COS3711 ASSIGNMENT 3
//Johnathan David Cookson 8812125074088
//8812125074088
#ifndef CONTAINERMOMENTO_H
#define CONTAINERMOMENTO_H

#include <QList>
#include "container.h"

//memento class used for the backup/restore function
class containerMomento
{

public:
    ~containerMomento();

private:
    friend class MainWindow;

    containerMomento();
    void setState(QList<Container*> inState);

    QList<Container*> getState();

    QList<Container*> state;

};

#endif // CONTAINERMOMENTO_H


//to do finish containter list
//implement this class
