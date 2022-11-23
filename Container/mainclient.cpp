//COS3711 ASSIGNMENT 3
//Johnathan David Cookson 8812125074088
//8812125074088
#include "mainclient.h"
#include "widget.h"
#include "popupview.h"


#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QLayout>
#include <QStatusBar>
#include <QMessageBox>
#include <QCloseEvent>
#include <QTextBrowser>

MainClient::MainClient(QWidget *parent)
    : QMainWindow(parent),
      _mainWidget{new MainWindow()}
{
    //sets everything prior to  the application being shown
    preSetup();
    //Central widget - adds the mainWidget to the mainwindow
    setCentralWidget(_mainWidget);

}

MainClient::~MainClient()
{}

void MainClient::preSetup()
{
    this->setWindowIcon(QIcon(":/images/box_icon.ico"));
    slot_updateStatusBar(_defaultStatusText);
    setupActions();
    setupMenus();
    setupToolbar();
    setupObjectNames();
    setupConnections();
}

void MainClient::setupObjectNames()
{
    //about and help action names to utilize the same slot
    _actHelp->setObjectName("help");
    _actAbout->setObjectName("about");
}

void MainClient::setupActions()
{
    _actExit = new QAction(QIcon(":/images/exit.png"), tr("&Exit"), this);
    /*status*/_actExit->setStatusTip(tr(_exitTip));
    /*Tooltip*/_actExit->setToolTip(_exitTip);
    _actBackup = new QAction(QIcon(":/images/backup.png"), tr("&Backup"), this);
    /*status*/_actBackup->setStatusTip(tr(_backupTip));
    /*Tooltip*/_actBackup->setToolTip(_backupTip);
    _actRestore = new QAction(QIcon(":/images/restore.png"), tr("*Restore"), this);
    /*status*/_actRestore->setStatusTip(tr(_restoreTip));
    /*Tooltip*/_actRestore->setToolTip(_restoreTip);
    _actPostXML = new QAction(QIcon(":/images/xml.png"), tr("&Post to XML"), this);
    /*status*/_actPostXML->setStatusTip(tr(_postXMLTip));
    /*Tooltip*/_actPostXML->setToolTip(_postXMLTip);
    _actAbout = new QAction(QIcon(":/images/info.png"), tr("&About"), this);
    /*status*/_actAbout->setStatusTip(tr(_aboutTip));
    /*Tooltip*/_actAbout->setToolTip(_aboutTip);
    _actHelp = new QAction(QIcon(":/images/help.png"), tr("&Help"), this);
    /*status*/_actHelp->setStatusTip(tr(_helpTip));
    /*Tooltip*/_actHelp->setToolTip(_helpTip);
}

void MainClient::setupMenus()
{
    // Set up QMenus as required

    _mnuFile = menuBar()->addMenu(tr("&File"));
    _mnuFile->addSeparator();
    _mnuFile->addAction(_actExit);

    _mnuBackup = menuBar()->addMenu(tr("&Backup"));
    _mnuBackup->addAction(_actBackup);
    _mnuBackup->addAction(_actRestore);

    _mnuPost = menuBar()->addMenu("&Post to XML");
    _mnuPost->addAction(_actPostXML);

    _mnuHelp = menuBar()->addMenu(tr("Help"));
    _mnuHelp->addAction(_actAbout);
    _mnuHelp->addAction(_actHelp);
}

void MainClient::setupToolbar()
{
    _toolbar = addToolBar(tr("&Main"));
    _toolbar->layout()->setSpacing(_toolbarSpacing);
    //actions for tool bar
    _toolbar->addAction(_actBackup);
    _toolbar->addAction(_actRestore);
    _toolbar->addAction(_actPostXML);

}

void MainClient::setupConnections()
{
    //connections
    connect(_actExit, &QAction::triggered, this, &QMainWindow::close);
    connect(_actAbout, &QAction::triggered, this, &MainClient::slot_popupView);
    connect(_actHelp, &QAction::triggered, this, &MainClient::slot_popupView);
    //connect to widget slots
    connect(_actPostXML, &QAction::triggered, _mainWidget, &MainWindow::postXML);
    connect(_actBackup, &QAction::triggered, _mainWidget, &MainWindow::backUpRestore);
    connect(_actRestore, &QAction::triggered, _mainWidget, &MainWindow::backUpRestore);
    connect(_mainWidget, &MainWindow::signalUpdateStatusBar, this, &MainClient::slot_updateStatusBar);

}

void MainClient::slot_updateStatusBar(QString text)
{
    statusBar()->showMessage(text);
}

void MainClient::slot_popupView()
{
    /*PopupView is a class that is used to create a popup window
    that can be used to display information to the user*/
    popupview *pv = new popupview;
    pv->setAttribute(Qt::WA_DeleteOnClose);
    QString objName = sender()->objectName();
    if(objName == "about"){
        pv->setWindowIcon(QIcon(":/images/info.png"));
        pv->setWindowTitle(tr("About"));
        pv->display(":/html/About.html");
    }else if(objName == "help"){
        pv->setWindowIcon(QIcon(":/images/help.png"));
        pv->setWindowTitle(tr("Help"));
        pv->display(":/html/help.html");
    }else{
        delete pv;
        QMessageBox::critical(this, tr("Error"), tr("Unknown object name"));
    }
}

void MainClient::closeEvent(QCloseEvent *event)
{
    int response;
    response = QMessageBox::warning(this, "Exit", "Are you sure you want to Exit ?",
                                    QMessageBox::Yes | QMessageBox::No);
    if (response == QMessageBox::Yes) { event->accept(); }
    else { event->ignore(); }
}























