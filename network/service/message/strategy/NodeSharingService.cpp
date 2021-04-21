#include "NodeSharingService.h"
#include <QByteArray>
#include <QJsonDocument>
#include <iostream>
#include <dto/NodeDto.h>

NodeSharingService::NodeSharingService()
{

}


bool NodeSharingService::isMatch(QString type){
    if(type == "RegistrationResponse"){
        return true;
    } else {
        return false;
    }
}

void NodeSharingService::processMessage(QJsonObject message){
    QJsonDocument doc(message);
    QByteArray ba = doc.toJson();
    std::cout<<"received node list : "<<std::endl<<ba.toStdString()<<std::endl;
}
