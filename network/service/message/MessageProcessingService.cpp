#include "MessageProcessingService.h"

#include <QJsonDocument>
#include <QJsonObject>

#include <network/service/message/strategy/NodeRegistrationService.h>
#include <network/service/message/strategy/NodeSharingService.h>
#include <network/service/message/strategy/TextMessageService.h>

MessageProcessingService::MessageProcessingService()
{
    messageProcessors.append(new TextMessageProcessor());
    messageProcessors.append(new NodeRegistrationService());
    messageProcessors.append(new NodeSharingService());
}

void MessageProcessingService::process(QByteArray message){
    QJsonDocument jsonDocument = QJsonDocument::fromJson(message);
    QJsonObject jsonObject = jsonDocument.object();
    QJsonValue typeValue = jsonObject.take("type");

    foreach(auto strategy, messageProcessors){
        if(strategy->isMatch(typeValue.toString())){
            strategy->processMessage(jsonObject);
        }
    }


}
