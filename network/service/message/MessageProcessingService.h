#ifndef MESSAGEPROCESSINGSERVICE_H
#define MESSAGEPROCESSINGSERVICE_H

#include "MessageProcessor.h"

#include <QByteArray>
#include <QTcpSocket>



class MessageProcessingService
{

public:
    QList<MessageProcessor* > messageProcessors;
    MessageProcessingService();
    void process(QByteArray message,QTcpSocket* socket);
};

#endif // MESSAGEPROCESSINGSERVICE_H
