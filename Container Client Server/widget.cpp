//COS3711 Assignment 3
//Johnathan David Cookson 45051429
//8812125074088
#include "widget.h"
#include <QPushButton>
#include <QTableView>
#include <QLabel>
#include <QGridLayout>
#include <QHBoxLayout>


MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    buttonListen{new QPushButton},
    tableView{new QTableView},
    serverStatusLabel{new QLabel}
{
    buttonListen->setText("Start Listening");
    QHBoxLayout *listeningLayout(new QHBoxLayout);
    listeningLayout->addWidget(buttonListen);
    listeningLayout->addWidget(serverStatusLabel);
    QGridLayout *layout(new QGridLayout);
    layout->addLayout(listeningLayout, 0, 0);
    layout->addWidget(tableView, 1, 0);
    QWidget *setServer(new QWidget);



    setServer->setLayout(layout);


}

MainWindow::~MainWindow()
{
}
