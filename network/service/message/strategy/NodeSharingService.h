#ifndef NODESHARINGSERVICE_H
#define NODESHARINGSERVICE_H

#include <QJsonObject>
#include <QString>

#include <network/service/message/MessageProcessor.h>



class NodeSharingService: public MessageProcessor
{
public:
    NodeSharingService();
    bool isMatch(QString type);
    void processMessage(QJsonObject message);
};

#endif // NODESHARINGSERVICE_H
