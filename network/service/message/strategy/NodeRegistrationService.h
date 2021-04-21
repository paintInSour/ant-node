#ifndef NODEREGISTRATIONSERVICE_H
#define NODEREGISTRATIONSERVICE_H

#include <QJsonObject>
#include <QString>

#include <network/service/message/MessageProcessor.h>



class NodeRegistrationService:public MessageProcessor
{
public:
    NodeRegistrationService();
    bool isMatch(QString type);
    void processMessage(QJsonObject message);
};

#endif // NODEREGISTRATIONSERVICE_H
