#include "NodeRegistrationService.h"
#include "constant/NetworkConstant.h"
#include <iostream>

#include <dto/NodeDto.h>

#include <QJsonDocument>


NodeRegistrationService::NodeRegistrationService()
{

}

bool NodeRegistrationService::isMatch(QString type){
    if(type == "RegistrationCall"){
        std::cout<<"NodeRegistration"<<std::endl;
        return true;
    } else {
        return false;
    }
}

void NodeRegistrationService::processMessage(QJsonObject message){

    QJsonValue hostValue = message.take("host");
    QJsonValue portValue = message.take("port");
    QJsonValue uuidValue = message.take("uuid");

    NodeDto *nodeDto = new NodeDto(hostValue.toString().toStdString(),portValue.toInt(),uuidValue.toString().toStdString());

    NETWORK_NODE_LIST.insert(nodeDto->host+":"+std::to_string(nodeDto->port), nodeDto);

    std::cout<<"Registered node uuid: "<<uuidValue.toString().toStdString()<<" host: "<<hostValue.toString().toStdString()<<":"<<portValue.toInt();

}


