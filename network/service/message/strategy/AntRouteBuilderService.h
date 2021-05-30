#ifndef ANTROUTEBUILDERSERVICE_H
#define ANTROUTEBUILDERSERVICE_H

#include <network/service/message/MessageProcessor.h>
#include <QJsonObject>
#include <QString>
#include <dto/NodeDto.h>


class AntRouteBuilderService:public MessageProcessor
{
public:
    AntRouteBuilderService();
    bool isMatch(QString type);
    void processMessage(QJsonObject message);
    void buildRoute();
    void updateNodeResponseTime(NodeDto* nodeDto);


};

#endif // ANTROUTEBUILDERSERVICE_H
