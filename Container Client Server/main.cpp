//COS3711 Assignment 3
//Johnathan David Cookson 45051429
//8812125074088
#include <QApplication>
#include <mainclientserver.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainClientServer mcs;

    mcs.show();


    return a.exec();
}
