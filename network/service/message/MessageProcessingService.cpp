#include "MessageProcessingService.h"

#include <QJsonDocument>
#include <QJsonObject>

#include <network/service/message/strategy/NodeRegistrationService.h>
#include <network/service/message/strategy/NodeSharingService.h>
#include <network/service/message/strategy/TextMessageService.h>
#include <network/service/message/strategy/AntRouteBuilderService.h>
#include "converter/MessageConverter.h"
#include <QTcpSocket>

MessageProcessingService::MessageProcessingService()
{
    messageProcessors.append(new TextMessageProcessor());
    messageProcessors.append(new NodeRegistrationService());
    messageProcessors.append(new NodeSharingService());
    messageProcessors.append(new AntRouteBuilderService());
}

void MessageProcessingService::process(QByteArray message,QTcpSocket* socket){
    QJsonDocument jsonDocument = QJsonDocument::fromJson(message);
    QJsonObject jsonObject = jsonDocument.object();
    QJsonValue typeValue = jsonObject.take("type");
//    std::cout<<"Processing message : "<<jsonDocument.toJson(QJsonDocument::JsonFormat()).toStdString()<<std::endl;
    std::cout<<"Processing message. Type : "<< typeValue.toString().toStdString()<<std::endl;

    foreach(auto strategy, messageProcessors){
        if(strategy->isMatch(typeValue.toString())){
            strategy->processMessage(jsonDocument.object());
        }
    }


}
