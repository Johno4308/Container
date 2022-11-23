//COS3711 ASSIGNMENT 3
//Johnathan David Cookson 8812125074088
//8812125074088
#include "widget.h"
#include <QSpinBox>
#include <QPushButton>
#include <QListWidget>
#include <QTextEdit>
#include <QGroupBox>
#include <QGridLayout>
#include <QLabel>
#include <QTabWidget>
#include <QMessageBox>
#include <QtMath>
#include <QStandardItemModel>
#include <QThread>
#include "clienttcp.h"
#include <QItemSelectionModel>
#include <QModelIndexList>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    box_breadth{new QSpinBox},
    box_length{new QSpinBox},
    box_height{new QSpinBox},
    box_weight{new QSpinBox},
    cylinder_diameter{new QSpinBox},
    cylinder_height{new QSpinBox},
    cylinder_weight{new QSpinBox},
    palletNumber{new QSpinBox},
    buttonAddBox{new QPushButton("Add box")},
    buttonAddCylinder{new QPushButton("Add cylinder")},
    buttonMoveToPallet{new QPushButton("Move to pallet")},
    buttonBackupRestore{new QPushButton("Backup")},
    buttonPostXML{new QPushButton("Post XML to network")},
    displayUnallocated{new QListWidget},
    displayPalletXML{new QTextEdit{this}},
    tabWidget{new QTabWidget},
    model{new QStandardItemModel},
    newContainer{new Factory},
    containerCode{new ContainerCode},
    containerlist{new ContainerList},
    palletList{new PalletList},
    _xmlPost{new WriteXML(palletList)},
    caretaker{new ContainerCareTaker}
{
    box_breadth->setValue(1);
    box_length->setValue(1);
    box_height->setValue(1);
    box_weight->setValue(1);
    cylinder_diameter->setValue(1);
    cylinder_height->setValue(1);
    cylinder_weight->setValue(1);
    palletNumber->setValue(1);
    palletNumber->setMaximum(9999);
    // Tab 1 - Containers
    QGroupBox *boxGroup(new QGroupBox("Box"));
    QGridLayout *boxlayout(new QGridLayout);
    boxGroup->setLayout(boxlayout);
    QLabel *labelBBreadth(new QLabel("Breadth"));
    boxlayout->addWidget(labelBBreadth, 0, 0);
    boxlayout->addWidget(box_breadth, 0, 1);
    QLabel *labelBLength(new QLabel("Length"));
    boxlayout->addWidget(labelBLength, 1, 0);
    boxlayout->addWidget(box_length, 1, 1);
    QLabel *labelBHeight(new QLabel("Height"));
    boxlayout->addWidget(labelBHeight, 2, 0);
    boxlayout->addWidget(box_height, 2, 1);
    QLabel *labelBWeight(new QLabel("Weight"));
    boxlayout->addWidget(labelBWeight, 3, 0);
    boxlayout->addWidget(box_weight, 3, 1);
    boxlayout->addWidget(buttonAddBox, 4, 0, 1, 2);
    buttonAddBox->setObjectName("BoxButton");
    buttonAddBox->setIcon(QIcon(":/images/box_icon.ico"));

    QGroupBox *cylinderGroup(new QGroupBox("Cylinder"));
    QGridLayout *cylinderlayout(new QGridLayout);
    cylinderGroup->setLayout(cylinderlayout);
    QLabel *labelCDiameter(new QLabel("Diameter"));
    cylinderlayout->addWidget(labelCDiameter, 0, 0);
    cylinderlayout->addWidget(cylinder_diameter, 0, 1);
    QLabel *labelCHeight(new QLabel("Height"));
    cylinderlayout->addWidget(labelCHeight, 1, 0);
    cylinderlayout->addWidget(cylinder_height, 1, 1);
    QLabel *labelCWeight(new QLabel("Weight"));
    cylinderlayout->addWidget(labelCWeight, 2, 0);
    cylinderlayout->addWidget(cylinder_weight, 2, 1);
    QLabel *labelBlank1(new QLabel);
    cylinderlayout->addWidget(labelBlank1, 3, 0);
    cylinderlayout->addWidget(buttonAddCylinder, 4, 0, 1, 2);
    buttonAddCylinder->setObjectName("CylinderButton");
    buttonAddCylinder->setIcon(QIcon(":/images/cylinder_icon.png"));


    QWidget *bottomWidget(new QWidget);
    QGridLayout *bottomLayout(new QGridLayout);
    bottomWidget->setLayout(bottomLayout);
    QLabel *labelListOf(new QLabel("List of unallocated containers"));
    bottomLayout->addWidget(labelListOf, 0, 0);
    QLabel *labelClickOn(new QLabel("Click on item in list, choose a pallet number, and Move the container to that pallet"));
    labelClickOn->setWordWrap(true);

    bottomLayout->addWidget(displayUnallocated, 1, 0, 5, 1);
    bottomLayout->addWidget(labelClickOn, 1, 1);
    bottomLayout->addWidget(palletNumber, 2, 1);
    palletNumber->setMinimum(1);
    bottomLayout->addWidget(buttonMoveToPallet, 3, 1);
    QLabel *labelBlank2(new QLabel);
    cylinderlayout->addWidget(labelBlank2, 4, 1);
    bottomLayout->addWidget(buttonBackupRestore, 5, 1);

    QWidget *containerWidget(new QWidget);
    QGridLayout *tabLayoutContainer(new QGridLayout);
    tabLayoutContainer->addWidget(boxGroup, 0, 0);
    tabLayoutContainer->addWidget(cylinderGroup, 0, 1);
    tabLayoutContainer->addWidget(bottomWidget, 1, 0, 1, 2);
    containerWidget->setLayout(tabLayoutContainer);

    // Tab 2 - Post XML
    QWidget *postWidget(new QWidget);
    QVBoxLayout *postLayout(new QVBoxLayout);
    postWidget->setLayout(postLayout);
    postLayout->addWidget(buttonPostXML);
    postLayout->addWidget(displayPalletXML);

    tabWidget->addTab(containerWidget, tr("Containers"));
    tabWidget->addTab(postWidget, tr("Post Xml"));
    // setting main widget
    QVBoxLayout *vertical(new QVBoxLayout);
    vertical->addWidget(tabWidget);
    vertical->setContentsMargins(0, 0, 0, 0);
    setLayout(vertical);

    connect(buttonAddBox,SIGNAL(clicked()), this, SLOT(addContainer()));
    connect(buttonAddCylinder,SIGNAL(clicked()), this, SLOT(addContainer()));
    connect(buttonBackupRestore,SIGNAL(clicked()), this, SLOT(backUpRestore()));
    connect(buttonMoveToPallet,SIGNAL(clicked()), this, SLOT(addPallet()));
    connect(buttonPostXML,SIGNAL(clicked()), this, SLOT(postXML()));

}

MainWindow::~MainWindow()
{
}

void MainWindow::resetBoxSpin()
{
    box_breadth->setValue(1);
    box_length->setValue(1);
    box_height->setValue(1);
    box_weight->setValue(1);
}

void MainWindow::resetCylinderSpin()
{
    cylinder_diameter->setValue(1);
    cylinder_height->setValue(1);
    cylinder_weight->setValue(1);
}

void MainWindow::setUniqueNum(int num)
{
    uniqueNum = num;
}

int MainWindow::getUniqueNum() const
{
    return uniqueNum;
}

containerMomento *MainWindow::createMemento()
{
    containerMomento *memento = new containerMomento;
    memento->setState(containerlist->getList());

    return memento;
}

void MainWindow::setMemento(containerMomento *memento)
{
    if(memento != 0)
    {
        containerlist->setList(memento->getState());
    }
}

//function to add a box or cylinder
//the listWidget gets updated and the spinBoxs are reset
void MainWindow::addContainer()
{
    QObject *whichType = sender();



    if(whichType == buttonAddBox)
    {
        int weight, volume, height, length, width, uniqueNum, x = 1;
        char b = 'B';

        width = box_breadth->value();
        length = box_length->value();
        height = box_height->value();
        weight = box_weight->value();

        if(width < x || length < x || height < x || weight < x)
        {
            QMessageBox::warning(this, "Invalid Input", "Please make sure all input is 1 unit or higher!");
        }
        else
        {
            volume = (length * width * height);
            uniqueNum = getUniqueNum();
            uniqueNum++;

            setUniqueNum(uniqueNum);
            QString code;
            code = containerCode->createCode(b, uniqueNum);


            Container *container = newContainer->createInstance(height, weight, volume, code, length, width);

            code = container->getCode();
            displayUnallocated->addItem(code);
            containerlist->addContainer(container);
            resetBoxSpin();
        }
    }
    else if(whichType == buttonAddCylinder)
    {
        float height, weight, volume, uniqueNum, diameter, x = 1;
        char c = 'C';

        height = cylinder_height->value();
        weight = cylinder_weight->value();
        diameter = cylinder_diameter->value();
        if(height < x || weight < x || diameter < x)
        {
            QMessageBox::warning(this, "Invalid Input", "Please make sure all input is 1 unit or higher!");
        }
        else
        {
            float x, y;
            x = diameter / 2;
            y = (M_PI * (x * x)) * height;
            volume = (int)y;
            uniqueNum = getUniqueNum();
            uniqueNum++;
            setUniqueNum(uniqueNum);

            QString code;
            code = containerCode->createCode(c, uniqueNum);
            displayUnallocated->addItem(code);


            Container* container = newContainer->createInstance(height, weight, volume, code, diameter);
            containerlist->addContainer(container);
            resetCylinderSpin();
        }
    }

}

//slot for the backup and restore function
void MainWindow::backUpRestore()
{
    QList<Container*> container;
    backUpState++;
    if(backUpState % 2 != 0)
    {
        caretaker->requestMemento(memento = createMemento());
        setMemento(memento);
        buttonBackupRestore->setText("Restore");
    }
    else if(backUpState % 2 == 0)
    {
        container = memento->getState();
        displayUnallocated->clear();
        for(int loop = 0; loop < container.size(); loop++)
        {
            QString uploadCode;
            uploadCode = container.at(loop)->getCode();
            displayUnallocated->addItem(uploadCode);
            buttonBackupRestore->setText("BackUp");
        }
    }

}

//slot to add a container to a selected pallet.
//the container is removed from the listWidget
void MainWindow::addPallet()
{
    int number;
    QItemSelectionModel *selection = displayUnallocated->selectionModel();
    QModelIndexList indexList = selection->selectedRows();

    QString contents;
    QVariant code;
    QList<Container*> list;
    Container *container;
    Pallet * testpallet;


    list = containerlist->getList();
    number = palletNumber->value();


    for(int i = 0; i < indexList.count(); i++)
    {
        index = indexList.at(i);
        code = index.data();
        contents = code.toString();
    }

    for(int i = 0; i < list.count(); i++)
    {
        if(contents == list.at(i)->getCode() && list.at(i)->getLength() > 0)
        {

            container = newContainer->createInstance(list.at(i)->getHeight(),
                                                    list.at(i)->getWeight(),
                                                    list.at(i)->getVolume(),
                                                    list.at(i)->getCode(),
                                                    list.at(i)->getLength(),
                                                    list.at(i)->getWidth());
            testpallet = pallet->setContainer(container, number);
            delete displayUnallocated->takeItem(displayUnallocated->currentRow());
            palletList->addPallet(testpallet);
        }
        else if(contents == list.at(i)->getCode() && list.at(i)->getLength() == 0)
        {
            Pallet * testpallet;
            container = newContainer->createInstance(list.at(i)->getHeight(),
                                                    list.at(i)->getWeight(),
                                                    list.at(i)->getVolume(),
                                                    list.at(i)->getCode(),
                                                    list.at(i)->getDiameter());
            testpallet = pallet->setContainer(container, number);
            delete displayUnallocated->takeItem(displayUnallocated->currentRow());
            palletList->addPallet(testpallet);
        }
    }


}

void MainWindow::postXML()
{
    //Post XML to server
    if(palletList->getSize() > 0)
    {
        //Ensures the user truly wants to generate the xml
        if(QMessageBox::Yes == QMessageBox::question(this, "Post XML", "Are you sure you want"
                                                     "to post the XML to the server")){
            QThread *thread = new QThread{};
            WriteXML *writeXML = new WriteXML{palletList};

            //runs the XML in a separate thread
            writeXML->moveToThread(thread);
            connect(thread, &QThread::started, writeXML, &WriteXML::write);
            connect(writeXML, &WriteXML::signalFinished, thread, &QThread::quit);
            connect(writeXML, &WriteXML::signalFinished, writeXML, &WriteXML::deleteLater);
            connect(writeXML, SIGNAL(signalResult(QString)), this, SLOT(appendXML(QString)));
            thread->start();
        }else{
            emit signalUpdateStatusBar(tr("XML not posted"));
        }
    }else{
        //the past pallet list is empty
        QMessageBox::warning(this, "Post XML", "There are no pallets to post");
    }
}

void MainWindow::appendXML(QString XML)
{
    //appends the generated xml to display on the pallet text box
    displayPalletXML->clear();
    displayPalletXML->append(XML);
    displayPalletXML->setReadOnly(true);

    emit sendXML(XML);
}

void MainWindow::sendXML(QString XML)
{
    QByteArray data = QString(XML).toUtf8();
    ClientTCP *tcp = new ClientTCP{};
    tcp->send(data);
}



