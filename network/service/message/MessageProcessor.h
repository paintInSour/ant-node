#ifndef MESSAGEPROCESSOR_H
#define MESSAGEPROCESSOR_H

#include <QJsonObject>
#include <QObject>
#include <QString>

class MessageProcessor
{

public:
    virtual bool isMatch(QString type);
    virtual void processMessage(QJsonObject message);
};

#endif // MESSAGEPROCESSOR_H
