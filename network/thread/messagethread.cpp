#include "messagethread.h"
#include <iostream>
#include <network/service/TcpClient.h>

using namespace std;

MessageThread::MessageThread(std::string host,int port,QByteArray jsonMessage)
{
    this->host = host;
    this->port = port;
    this->jsonMessage = jsonMessage;
    this->start();
}


MessageThread::MessageThread(std::string host,int port)
{
    this->host = host;
    this->port = port;
}

void MessageThread::writeMessage(QByteArray jsonMessage){
    this->jsonMessage = jsonMessage;
    this->start();
}

void MessageThread::run()
{
    Client * client = new Client();
    if(!client->isConnected()){
        client->connectToHost(QString::fromStdString(this->host),this->port);
    }
    client->writeData(jsonMessage);


}
