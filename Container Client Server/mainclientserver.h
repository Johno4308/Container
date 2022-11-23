//COS3711 Assignment 3
//Johnathan David Cookson 45051429
//8812125074088
#ifndef MAINCLIENTSERVER_H
#define MAINCLIENTSERVER_H
//mainwindow layout
#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QTableView>
#include <QLabel>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QList>
#include <QDomDocument>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>

#include "containerdata.h"

//main class for UI and reading DOM, I moved DOM into this class as I was really struggling to
//get my list<dataclass> to get the return on my DOM function. It kept "pulling the out of range error"
//I can see however that my QByteArray does receive the data.
class MainClientServer : public QWidget
{
    Q_OBJECT
public:
    MainClientServer();
    ~MainClientServer();
    void closeEvent(QCloseEvent *event);
    void addingData();
    void appendRow(QString pallet, QString containerType, QString code,
                   QString height, QString breadthDiameter, QString length, QString weight);

    QByteArray getByte() const;
    void setByte(QByteArray inData);

    QList<ContainerData*> ReadXml();

public slots:
    void onNewConnection();
    void readMessage();


private:
    void setupGUI();
    QPushButton     *  buttonListen;
    QTableView      *  tableView;
    QLabel          *  serverStatusLabel;
    QList<ContainerData*> dataList;


    QString file_name;
    QStandardItemModel *model;
    QByteArray _inData;
    QList<ContainerData*> _dataList;
    QDomDocument document;
    ContainerData *data;
    QDomElement root;

    QTcpServer *server;
    QTcpSocket *sockets;
    QHostAddress host;
};

#endif // MAINCLIENTSERVER_H
