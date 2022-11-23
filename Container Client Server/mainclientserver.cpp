//COS3711 Assignment 3
//Johnathan David Cookson 45051429
//8812125074088
#include "mainclientserver.h"

#include <QCloseEvent>
#include <QFileDialog>
#include <QMessageBox>
#include <QHeaderView>
#include <QStandardItem>
#include <QList>

#include <QDebug>

MainClientServer::MainClientServer():
      buttonListen{new QPushButton},
      tableView{new QTableView},
      serverStatusLabel{new QLabel},
      model{new QStandardItemModel},
      data{new ContainerData},
      server{new QTcpServer(this)}
{

    model->setHorizontalHeaderItem(0, new QStandardItem(QString("Pallet")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Container")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QString("Code")));
    model->setHorizontalHeaderItem(3, new QStandardItem(QString("Height")));
    model->setHorizontalHeaderItem(4, new QStandardItem(QString("Breadth/Diameter")));
    model->setHorizontalHeaderItem(5, new QStandardItem(QString("Length")));
    model->setHorizontalHeaderItem(6, new QStandardItem(QString("Weight")));
    setWindowTitle("Container Server");
    setFixedSize(1200, 400);

    int port(6164);
    host.setAddress(QHostAddress::LocalHost);
    server->listen(QHostAddress(QHostAddress::LocalHost), port);
    serverStatusLabel->setText("Listening to port 6164");
    qDebug() << "Connecting....";
    setupGUI();

}

MainClientServer::~MainClientServer()
{

}
//UI close event
void MainClientServer::closeEvent(QCloseEvent *event)
{
    int response;
    response = QMessageBox::warning(this, "Exit", "Are you sure you want to Exit ?",
                                    QMessageBox::Yes | QMessageBox::No);
    if (response == QMessageBox::Yes)
    {
        event->accept();
    }
    else
    {
        event->ignore();
    }
}
//adding data to widget
void MainClientServer::addingData()
{

    qDebug() << "adding data read" << _inData;
    //dataList = xmlReader->ReadXml();
    QList<ContainerData*> dataLists;

    dataLists = ReadXml();


    int i = 0;
    QString palletData, containerTypeData, codeData, heightData, BreadthWidthData, lengthData, weightData;

    do{

        data = dataList.at(i);
        palletData = data->getPallet();
        containerTypeData = data->getContainerType();
        codeData = data->getCode();
        heightData = data->getHeight();
        BreadthWidthData = data->getBreadthDiameter();
        lengthData = data->getLength();
        weightData = data->getWeight();

        appendRow(palletData, containerTypeData, codeData, heightData, BreadthWidthData, lengthData, weightData);
        i++;

    }while(i < dataList.size());

}
//appending rows
void MainClientServer::appendRow(QString pallet, QString containerType, QString code, QString height, QString breadthDiameter, QString length, QString weight)
{
    QList<QStandardItem*> row;

    row.append(new QStandardItem(pallet));
    row.append(new QStandardItem(containerType));
    row.append(new QStandardItem(code));
    row.append(new QStandardItem(height));
    row.append(new QStandardItem(breadthDiameter));
    row.append(new QStandardItem(length));
    row.append(new QStandardItem(weight));
    model->appendRow(row);
    return;
}

QByteArray MainClientServer::getByte() const
{
    return _inData;
}

void MainClientServer::setByte(QByteArray inData)
{
    _inData = inData;
}

//using DOM to parse through my QByteArray
QList<ContainerData *> MainClientServer::ReadXml()
{
    QByteArray byte;
    byte = getByte();

    document.setContent(byte);


    root = document.firstChildElement();
    QDomElement node = root.firstChildElement().toElement();

    //string declaring
    QString palletData, containerTypeData, codeData, heightData, BreadthWidthData, lengthData, weightData;

    while(node.isNull() == false)
    {
        if(node.isElement())
        {
            QDomElement palletElement = node.toElement();
            if(!palletElement.isNull()){
                if(palletElement.tagName() == "pallet"){

                    QDomAttr palletNumberNode = node.attributeNode("number");
                    palletData = palletNumberNode.value();

                    QDomElement containerTypeElement = palletElement.firstChildElement();
                    if(containerTypeElement.tagName() == "Box")
                    {
                        containerTypeData = "Box";
                        QDomElement boxTag = containerTypeElement.firstChildElement();
                        if(boxTag.tagName() == "code"){
                            codeData = boxTag.text();
                            boxTag = boxTag.nextSiblingElement().toElement();
                        }
                        if(boxTag.tagName() == "height"){
                            heightData = boxTag.text();
                            boxTag = boxTag.nextSiblingElement().toElement();
                        }
                        if(boxTag.tagName() == "weight"){
                            weightData = boxTag.text();
                            boxTag = boxTag.nextSiblingElement().toElement();
                        }
                        if(boxTag.tagName() == "length"){
                            lengthData = boxTag.text();
                            boxTag = boxTag.nextSiblingElement().toElement();
                        }
                        if(boxTag.tagName() == "breadth"){
                            BreadthWidthData = boxTag.text();
                            boxTag = boxTag.nextSiblingElement().toElement();
                        }

                        data = new ContainerData(palletData, containerTypeData, codeData, heightData, BreadthWidthData, lengthData, weightData);
                        _dataList.append(data);


                     containerTypeElement = containerTypeElement.nextSiblingElement().toElement();

                    }

                    if(containerTypeElement.tagName() == "Cylinder")
                    {
                        containerTypeData = "Cylinder";
                        lengthData = "";
                        QDomElement CylinderTag = containerTypeElement.firstChildElement();
                        if(CylinderTag.tagName() == "code"){
                            codeData = CylinderTag.text();
                            CylinderTag = CylinderTag.nextSiblingElement().toElement();
                        }
                        if(CylinderTag.tagName() == "height"){
                            heightData = CylinderTag.text();
                            CylinderTag = CylinderTag.nextSiblingElement().toElement();
                        }
                        if(CylinderTag.tagName() == "weight"){
                            weightData = CylinderTag.text();
                            CylinderTag = CylinderTag.nextSiblingElement().toElement();
                        }
                        if(CylinderTag.tagName() == "diameter"){
                            BreadthWidthData = CylinderTag.text();
                            CylinderTag = CylinderTag.nextSiblingElement().toElement();
                        }
                        data = new ContainerData(palletData, containerTypeData, codeData, heightData, BreadthWidthData, lengthData, weightData);
                        containerTypeElement = containerTypeElement.nextSiblingElement().toElement();
                        _dataList.append(data);
                    }
                }
            }
        }
        node = node.nextSiblingElement().toElement();

    }
    qDebug() << _dataList;

    return _dataList;
}

void MainClientServer::onNewConnection()
{
    sockets = server->nextPendingConnection();
    sockets->waitForBytesWritten(6000);

    qDebug() << "Socket Connected";



    readMessage();
}

void MainClientServer::readMessage()
{
    QByteArray inData;
    inData = sockets->readAll();
    sockets->waitForBytesWritten(6000);

    qDebug() << "Text Recieved";

    setByte(inData);

    addingData();

}


//UI setup
void MainClientServer::setupGUI()
{
    buttonListen->setText("Start Listening");
    buttonListen->setObjectName("listenButton");
    QHBoxLayout *listeningLayout(new QHBoxLayout);
    listeningLayout->addWidget(buttonListen);
    listeningLayout->addWidget(serverStatusLabel);
    QGridLayout *layout(new QGridLayout);
    layout->addLayout(listeningLayout, 0, 0);
    layout->addWidget(tableView, 1, 0);
    tableView->setModel(model);
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);



    this->setLayout(layout);
    connect(buttonListen,SIGNAL(clicked()), this, SLOT(onNewConnection()));


}
