#ifndef MESSAGEPROCESSINGSERVICE_H
#define MESSAGEPROCESSINGSERVICE_H

#include "MessageProcessor.h"

#include <QByteArray>



class MessageProcessingService
{

public:
    QList<MessageProcessor* > messageProcessors;
    MessageProcessingService();
    void process(QByteArray message);
};

#endif // MESSAGEPROCESSINGSERVICE_H
