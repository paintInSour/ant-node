#include "NetworkUtil.h"
#include "constant/NetworkConstant.h"

#include <QProcess>
#include <iostream>

#include "network/service/TcpClient.h"
#include "converter/MessageConverter.h"

#include <network/thread/messagethread.h>

using namespace std;

int PORT = 8081;

NetworkUtil::NetworkUtil()
{

}

void NetworkUtil::setUpPort(QTcpServer *tcpServer){

    cout<<"Try to connect to port :"<<PORT<<endl;
    try{
        if(!tcpServer->listen(QHostAddress::LocalHost, PORT)){
            cout << "Unable to connect to port :"<<PORT<<endl;
            PORT++;
            setUpPort(tcpServer);
        } else {
            cout<<"Server connected to listen port :"<<PORT<<endl;
        }
    }catch(...){
        cout<<"Unexpected error while setting port"<<endl
           <<"Exiting application..."<<endl;
        exit(1);
    }

}

void NetworkUtil::writeMessage(){
    string host;
    int port;
    string message;

    char action;
    cout<<endl<<"enter action"<<endl;
    cin>>action;
    while(action !='q'){
        if(action == 'a'){
//            QProcess::execute("startup.sh");
            cout<<endl<<"Enter host:";
            cin>>host;
            cout<<endl<<"Enter port:";
            cin>>port;
            cout<<endl<<"Enter message:";
            cin>>message;

            QByteArray jsonMessage = MessageConverter::toTextMessage(QString::fromStdString(message));

            MessageThread *messageThread = new MessageThread(host,port,jsonMessage);
        }
        if(action == 'r'){
            cout<<"registering.."<<endl;
            cout<<endl<<"Enter host:";
            cin>>host;
            cout<<endl<<"Enter port:";
            cin>>port;

            QByteArray jsonMessage = MessageConverter::toRegistrationNodeMessage();
            MessageThread *messageThread = new MessageThread(host,port,jsonMessage);

        }
        if(action == 'n'){
            cout<<"node list"<<endl;
            cout<<endl<<"Enter host:";
            cin>>host;
            cout<<endl<<"Enter port:";
            cin>>port;

            QByteArray jsonMessage = MessageConverter::toRegistrationResponse();
            cout<<"message : "<<jsonMessage.toStdString()<<endl;
            MessageThread *messageThread = new MessageThread(host,port,jsonMessage);

        }

        cout<<endl<<"Enter action. Text message -a, Register -r, Node list -n"<<endl;

        cin>>action;
    }
}
