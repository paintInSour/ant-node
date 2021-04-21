#ifndef TEXTMESSAGESERVICE_H
#define TEXTMESSAGESERVICE_H

#include <network/service/message/MessageProcessor.h>



class TextMessageProcessor : public MessageProcessor
{
public:
    TextMessageProcessor();
    bool isMatch(QString type);
    void processMessage(QJsonObject message);
};

#endif // TEXTMESSAGESERVICE_H
