#ifndef MESSAGETHREAD_H
#define MESSAGETHREAD_H

#include <QThread>
#include <string>



class MessageThread: public QThread
{
    Q_OBJECT
public:
    std::string host;
    int port;
    QByteArray jsonMessage;

    MessageThread();
    MessageThread(std::string host, int port);
    MessageThread(std::string host, int port,QByteArray jsonMessage);

    void run() override;

    void writeMessage(QByteArray jsonMessage);

};

#endif // MESSAGETHREAD_H
