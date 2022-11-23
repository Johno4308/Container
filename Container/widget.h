//COS3711 ASSIGNMENT 3
//Johnathan David Cookson 8812125074088
//8812125074088
#ifndef WIDGET_H
#define WIDGET_H

//UI that contains public slot functions for numerous signals
#include <QDebug>

#include "factory.h"
#include "containercode.h"
#include "containerlist.h"
#include "palletlist.h"
#include "containercaretaker.h"
#include "containermomento.h"
#include "pallet.h"
#include "writexml.h"
#include <QModelIndex>

#include <QWidget>
class QSpinBox;
class QPushButton;
class QListWidget;
class QTextEdit;
class QTabWidget;
class QStandardItemModel;
class QModelIndex;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    //signal is used to display any sent text in the status bar
    void signalUpdateStatusBar(QString text);
    //Signal is used to send XML returned to server
    void signal_sendXML(QString xml);
public:
    void resetBoxSpin();
    void resetCylinderSpin();
    void setUniqueNum(int num);
    int getUniqueNum() const;
    containerMomento* createMemento();
    void setMemento(containerMomento* memento);


public slots:
    void addContainer();
    void backUpRestore();
    void addPallet();
    void postXML();
    void appendXML(QString XML);
    void sendXML(QString XML);


private:
    QSpinBox    *  box_breadth,
                *  box_length,
                *  box_height,
                *  box_weight,
                *  cylinder_diameter,
                *  cylinder_height,
                *  cylinder_weight,
                *  palletNumber;
    QPushButton *  buttonAddBox,
                *  buttonAddCylinder,
                *  buttonMoveToPallet,
                *  buttonBackupRestore,
                *  buttonPostXML;
    QListWidget *  displayUnallocated;


    QTextEdit   *  displayPalletXML;
    QTabWidget  *  tabWidget;
    QStandardItemModel *model;
    QModelIndex index;
    Factory     * newContainer;
    int           uniqueNum = 0, backUpState = 0;
    ContainerCode *containerCode;
    ContainerList *containerlist;
    PalletList *palletList;
    Pallet* pallet;
    WriteXML *_xmlPost;
    ContainerCareTaker *caretaker;
    containerMomento *memento;
};

#endif // WIDGET_H
