#ifndef TERMINALMENUTHREAD_H
#define TERMINALMENUTHREAD_H

#include <QThread>
#include <util/NetworkUtil.h>

class MenuThread : public QThread
{
    Q_OBJECT
protected:
    void run() override{
        NetworkUtil::writeMessage();
    }
};

#endif // TERMINALMENUTHREAD_H

