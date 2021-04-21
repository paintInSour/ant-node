#ifndef NETWORKUTIL_H
#define NETWORKUTIL_H

#include <QList>
#include <QTcpServer>

class NetworkUtil
{
private:
    NetworkUtil();
public:
    static void setUpPort(QTcpServer *tcpServer);

    static void writeMessage();

};

#endif // NETWORKUTIL_H
