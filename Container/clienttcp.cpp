#include "clienttcp.h"
#include <QMessageBox>

ClientTCP::ClientTCP():
    _socket{new QTcpSocket}
{}

void ClientTCP::send(QByteArray data)
{
    //connect is made | data is sent | connection is closed
    _socket->connectToHost(_host, _port);
    //only wait three seconds to connect
    if(_socket->waitForConnected(3000)){
        _socket->write(data);
        QMessageBox::information(nullptr, "Delievered", "The information has been sent to the server");
        _socket->close();
        return;
    }else{
        QMessageBox::critical(nullptr, "Error", "The data could not be deleivered to he server");
        _socket->close();
        return;
    }

    _socket->close();
}
