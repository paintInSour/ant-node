#include "TcpServer.h"
#include <QDebug>
#include <QCoreApplication>
#include <iostream>

#include <QJsonDocument>
#include <QJsonObject>
#include <QTcpServer>

#include "util/NetworkUtil.h"
#include "constant/NetworkConstant.h"

#include <network/service/message/MessageProcessingService.h>

using namespace std;

MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent)
{

    mTcpServer = new QTcpServer(this);

    connect(mTcpServer, &QTcpServer::newConnection, this, &MyTcpServer::slotNewConnection);

    NetworkUtil::setUpPort(mTcpServer);

    if(PORT != MAIN_LOCAL_PORT){
        cout<<"Network node list :"<<endl;
        for(NodeDto *nodeDto : NETWORK_NODE_LIST){
            cout<<"\tnode:"<<nodeDto->uuid<<" host: "<<nodeDto->host<<":"<<nodeDto->port<<endl;
        }
    }

}

void MyTcpServer::slotNewConnection()
{
    mTcpSocket = mTcpServer->nextPendingConnection();

    cout<<"New connection received :"<<mTcpSocket->peerAddress().toString().toStdString()<<":"<<mTcpSocket->peerPort()<<endl;

    connect(mTcpSocket, &QTcpSocket::readyRead, this, &MyTcpServer::slotServerRead);
    connect(mTcpSocket, &QTcpSocket::disconnected, this, &MyTcpServer::slotClientDisconnected);
}

void MyTcpServer::slotServerRead()
{
    MessageProcessingService messageProcessingService;
    cout<<"Reading data(SERVER)"<<endl;
    while(mTcpSocket->bytesAvailable()>0)
    {
        QByteArray array = mTcpSocket->readAll();


        messageProcessingService.process(array,mTcpSocket);
    }
    cout<<endl<<"Ended reading data(SERVER)"<<endl;
}

void MyTcpServer::slotClientDisconnected()
{
    mTcpSocket->close();
}

void MyTcpServer::writeMessage(QString message,int port, QString host){
    QTcpSocket socket;
    socket.connectToHost(host,port);

    bool connected = socket.waitForConnected();
    cout<<"Connected to write message : "<< connected<<endl;
    if(socket.state() == QAbstractSocket::ConnectedState){
        QByteArray byteArray = message.toUtf8();
        socket.write(byteArray);
        socket.waitForBytesWritten();
    }else{
        cout<<"Error while writing message. Message = "<<message.toStdString()<<std::endl;
    }

}

