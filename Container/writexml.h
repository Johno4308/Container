//COS3711 ASSIGNMENT 3
//Johnathan David Cookson 8812125074088
//8812125074088
#ifndef WRITEXML_H
#define WRITEXML_H

#include "palletlist.h"
#include <QString>


//class to write XML using XMLStreamReader
class WriteXML :public QObject
{
    Q_OBJECT
public:
    //Initialised with a pallet list
    WriteXML(PalletList *palletList);

public slots:
    //slot is used to generate xml to be sent over the server
    void write();

signals:
    //signal is used to transfer the xml generated
    void signalResult(QString document);
    //signal indicates that the thread can stop
    void signalFinished();

private:
    PalletList *_palletList;

};

#endif // WRITEXML_H
