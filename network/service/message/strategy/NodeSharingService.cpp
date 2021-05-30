#include "NodeSharingService.h"
#include <QByteArray>
#include <QJsonDocument>
#include <iostream>
#include <dto/NodeDto.h>
#include <converter/MessageConverter.h>

NodeSharingService::NodeSharingService()
{

}


bool NodeSharingService::isMatch(QString type){
    if(type == "RegistrationResponse"){
        std::cout<<"NodeSharing"<<std::endl;
        return true;
    } else {
        return false;
    }
}

void NodeSharingService::processMessage(QJsonObject message){
    QJsonDocument doc(message);
    QByteArray ba = doc.toJson();
    std::cout<<"received node list : "<<std::endl<<ba.toStdString()<<std::endl;
    QList<NodeDto*> nodes = MessageConverter::toRegistrationResposneList(message);
    foreach(auto node,nodes){
        if(!NETWORK_NODE_LIST.contains(node->host+":"+std::to_string(node->port))){
            std::cout<<"adding node : "<<node->port<<std::endl;
            NETWORK_NODE_LIST.insert(node->host+":"+std::to_string(node->port),node);
        }
    }

}
