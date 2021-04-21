#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QtCore>
#include <QtNetwork>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0);

public slots:
    bool connectToHost(QString host,int port);
    bool writeData(QByteArray data);
    bool isConnected();
    void readData();

private:
    QTcpSocket *socket;
};

#endif // TCPCLIENT_H
