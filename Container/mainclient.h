//COS3711 ASSIGNMENT 3
//Johnathan David Cookson 8812125074088
//8812125074088
#ifndef MAINCLIENT_H
#define MAINCLIENT_H

#include <QMainWindow>
class QAction;
class QMenu;
class QToolBar;
class QTabWidget; // added
class MainWindow;

class MainClient : public QMainWindow
{
    Q_OBJECT

public:
    MainClient(QWidget *parent = nullptr);
    ~MainClient();
    //Override close event
    void closeEvent(QCloseEvent *event);

private slots:
    //slot used to display any sent text in the status bar    //    void showAbout();   //commented out
    void slot_updateStatusBar(QString text);        //added
    // slot is used to display a popup window for about or help //    void showHelp(); //commented out
    void slot_popupView();

private:
    /*Custom class objects*/
    MainWindow *_mainWidget;

    //Pre-Application setups for Action + Menu + toolbar + object names

    void preSetup();
    void setupObjectNames();
    void setupActions();
    void setupMenus();
    void setupToolbar();
    void setupConnections();

    //Pre-application Member Variables
    // QActions
    QAction *_actExit;
    QAction *_actBackup;
    QAction *_actRestore;
    QAction *_actPostXML;
    QAction *_actAbout;
    QAction *_actHelp;
    // QMenu
    QMenu *_mnuFile;
    QMenu *_mnuBackup;
    QMenu *_mnuPost;
    QMenu *_mnuHelp;
    //Toolbar
    QToolBar *_toolbar;

    //Constriants - to help minimize 'magic numbers'
    int _toolbarSpacing = 20;
    const char *_exitTip = "Exit the appication";
    const char *_backupTip = "Backup the application";
    const char *_restoreTip = "Restore the application";
    const char *_postXMLTip = "Post XML to the server";
    const char *_aboutTip = "Show the application's About box";
    const char *_helpTip = "Show the application's Help box";
    QString _defaultStatusText = "Ready";

};
#endif // MAINCLIENT_H
