//COS3711 ASSIGNMENT 3
//Johnathan David Cookson 8812125074088
//8812125074088
#include "writexml.h"
#include "palletlist.h"
#include "pallet.h"
#include "container.h"

#include <QDomDocument>
#include <QDomElement>
#include <QMetaObject>
#include <QMetaProperty>

WriteXML::WriteXML(PalletList *palletList):
    _palletList{palletList}
{}

void WriteXML::write()
{
    QDomDocument document;
    QDomElement root = document.createElement("pallets");
    root.setAttribute("NumberOfPallets", _palletList->getSize());
    document.appendChild(root);

    //cycles through the pallet list and gets each individual pallet
    for(int i = 0; i < _palletList->getSize(); i++)
    {
        Pallet *palletObj = _palletList->getPallet(i);
        QDomElement pallet = document.createElement("pallet");
        pallet.setAttribute("weight", palletObj->getPalletWeight());
        pallet.setAttribute("volume", palletObj->getPalletVolume());
        pallet.setAttribute("number", palletObj->getPalletNumber());
        root.appendChild(pallet);

        //cycles through the container list and gets each individual container
        for(int j = 0; j < palletObj->getSize(); j++)
        {
            Container *containerObj = palletObj->getContainer(j);
            QString containerName = QString(containerObj->metaObject()->className());
            QDomElement container = document.createElement(containerName);
            pallet.appendChild(container);

            //cycles through the properties of the container using QMetaObjects and adds them to the xml
            for(int k = 1; k < containerObj->metaObject()->propertyCount(); k++)
            {
                QMetaProperty property = containerObj->metaObject()->property(k);
                QString propertyName = QString(property.name());
                QString propertyValue = QString(property.read(containerObj).toString());

                QDomElement containerProperty = document.createElement(propertyName);
                QDomText value = document.createTextNode(propertyValue);
                containerProperty.appendChild(value);
                container.appendChild(containerProperty);
            }
        }
    }
    //emits result in form of a signal to be used by MainWindow to send to server and display
    emit signalResult(document.toString());
    //emits finished signal to indicate that the threat can stop
    emit signalFinished();

}
