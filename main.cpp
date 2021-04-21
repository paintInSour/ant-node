#include <QCoreApplication>
#include <iostream>

#include "network/service/TcpServer.h"
#include "util/NetworkUtil.h"

#include "constant/NetworkConstant.h"

#include "util/TerminalMenuThread.h"
#include "dto/messagedto.h"

#include <QDataStream>

using namespace std;

int main(int argc, char *argv[])
{

    cout<<"Successfully satrted node..."<<endl;
    cout<<"Node uuid = "<<PUBLIC_UUID.toStdString()<<endl;

    QCoreApplication a(argc, argv);

    MyTcpServer * server = new MyTcpServer();
    cout<<"Node started listening port: "<<PORT;


    QTcpSocket socket;

    if(PORT != MAIN_LOCAL_PORT){
        socket.connectToHost(QHostAddress::LocalHost,MAIN_LOCAL_PORT);

        socket.waitForConnected();
    }
    //        NetworkUtil::writeMessage();
    MenuThread *menu = new MenuThread();
    menu->start();
    //        MessageDto dto;



    return a.exec();
}


