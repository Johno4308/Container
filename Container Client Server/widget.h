//COS3711 Assignment 3
//Johnathan David Cookson 45051429
//8812125074088
#ifndef WIDGET_H
#define WIDGET_H
//widget class
#include <QWidget>




class QPushButton;
class QLabel;
class QTableView;



class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QPushButton     *  buttonListen;
    QTableView      *  tableView;
    QLabel          *  serverStatusLabel;



};

#endif // WIDGET_H
