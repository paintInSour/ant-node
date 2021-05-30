#include "AntRouteBuilderService.h"
#include "constant/NetworkConstant.h"
#include "network/thread/messagethread.h"
#include "converter/MessageConverter.h"
#include "util/TimeUtil.h"


AntRouteBuilderService::AntRouteBuilderService()
{

}

bool AntRouteBuilderService::isMatch(QString type){
    if(type.contains("time")){
        std::cout<<"AntRoutBuilding"<<std::endl;
        return true;
    } else {
        return false;
    }

}

void AntRouteBuilderService::processMessage(QJsonObject message){

    std::cout<<"Processing message : "<<QJsonDocument(message).toJson(QJsonDocument::Compact).toStdString()<<std::endl;
    QJsonValue typeValue = message.take("type");
    std::cout<<"Processing type :"<<typeValue.toString().toStdString()<<std::endl;

    if(typeValue.toString().toStdString().compare("timeCheck")==0){
        std::cout<<"Received timeCheck request."<<std::endl;
        new MessageThread(message.take("host").toString().toStdString(),message.take("port").toInt(),MessageConverter::toNodeDtoMessageTimeChecked());

    }
    if(typeValue.toString().toStdString().compare("timeChecked")==0){
        std::cout<<"Received check time response"<<std::endl;
        NodeDto *node = MessageConverter::toNodeDto(message);
        updateNodeResponseTime(node);
    }
    else{
       std::cout<<"Type : "<<typeValue.toString().toStdString()<<std::endl;
    }
}

void AntRouteBuilderService::buildRoute(){
    foreach(auto node, NETWORK_NODE_LIST){

        if(MessageConverter::toHostPort(node->host,node->port)!=MessageConverter::toHostPort(HOST.toStdString(),PORT)){
            QByteArray message = MessageConverter::toNodeDtoMessageTimeCheck();
            std::cout<<"Build route to "<<node->host<<":"<<node->port<<std::endl;
            NodeDto* networkNode = new NodeDto(node->host,node->port,node->uuid);

            networkNode->timeCheckStart = TimeUtil::getTime();
            NETWORK_ROUTE_LIST.insert(MessageConverter::toHostPort(networkNode->host,networkNode->port),networkNode);

            new MessageThread(node->host,node->port,message);
        }
    }
}

void AntRouteBuilderService::updateNodeResponseTime(NodeDto* nodeDto){
    std::string nodeKey= MessageConverter::toHostPort(nodeDto->host,nodeDto->port);
    std::cout<<"Updating node time : "<<nodeKey<<std::endl;
    NodeDto *node = NETWORK_ROUTE_LIST.take(nodeKey);
    node->timeCheckEnd = TimeUtil::getTime();
    long timeCheck = node->timeCheckEnd - node->timeCheckStart;
    node->time = timeCheck;
    NETWORK_ROUTE_LIST.insert(nodeKey,node);
    std::cout<<"Updated node "<<nodeKey<<", time : "<<timeCheck<<std::endl;

}
