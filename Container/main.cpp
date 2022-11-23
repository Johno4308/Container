//COS3711 ASSIGNMENT 3
//Johnathan David Cookson 8812125074088
//8812125074088

//RAN OUT OF TIME SORRY....

#include <QApplication>
#include <QSplashScreen>
#include <QTimer>
#include "mainclient.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QPixmap pixmap(":/images/splash_image_45051429.jpg");
    QSplashScreen splash(pixmap, Qt::WindowStaysOnTopHint);
    splash.show();

    MainClient mc;

    QTimer::singleShot(3000, &mc, &QWidget::show);
    QTimer::singleShot(3000, &splash, &QWidget::close);
    //mc.show();

    return a.exec();
}
