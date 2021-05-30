#include "TcpClient.h"
#include <iostream>

using namespace std;


Client::Client(QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket(this);

    connect(socket, &QTcpSocket::readyRead, this,&Client::readData);
}

bool Client::connectToHost(QString host,int port)
{
    socket->connectToHost(host, port);

    return socket->waitForConnected();
}

bool Client::writeData(QByteArray data)
{
    if(socket->state() == QAbstractSocket::ConnectedState)
    {
        socket->write(data); //write the data itself
        return socket->waitForBytesWritten();
    }
    else
        return false;
}

bool Client::isConnected(){
    return socket->state() == QAbstractSocket::ConnectedState;
}

void Client::readData()
{
    cout<<"Reading data(CLIENT)"<<endl;
    while(socket->bytesAvailable()>0)
    {
        QByteArray array = socket->readAll();

        cout<< array.toStdString();

//        socket->write(array);
    }
    cout<<endl<<"Ended reading data(CLIENT)"<<endl;
}
