#ifndef NETWORKCONSTANT_H
#define NETWORKCONSTANT_H


#include <QList>

#include <dto/NodeDto.h>

extern int PORT;
extern QString HOST;

extern QString PUBLIC_UUID;

extern const int MAIN_LOCAL_PORT;

extern QMap<std::string,NodeDto*> NETWORK_NODE_LIST;

extern QMap<std::string,NodeDto*> NETWORK_ROUTE_LIST;


#endif // NETWORKCONSTANT_H
