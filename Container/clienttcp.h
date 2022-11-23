#ifndef CLIENTTCP_H
#define CLIENTTCP_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include <QByteArray>


class ClientTCP : public QObject
{
    Q_OBJECT
public:
    ClientTCP();
    void send(QByteArray data);
private:
    QTcpSocket *_socket;
    QHostAddress _host = QHostAddress::LocalHost;
    quint16 _port = 6164;
};

#endif // CLIENTTCP_H
