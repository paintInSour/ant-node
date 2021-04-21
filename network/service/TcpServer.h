#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

extern int PORT;

class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = 0);

public slots:
    void slotNewConnection();
    void slotServerRead();
    void slotClientDisconnected();

    void writeMessage(QString message,int port, QString host);

private:
    QTcpServer * mTcpServer;
    QTcpSocket * mTcpSocket;
};

#endif // TCPSERVER_H
