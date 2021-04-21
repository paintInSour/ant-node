#include "constant/NetworkConstant.h"

#include <QMap>
#include <QUuid>
#include <string>
#include "dto/NodeDto.h"

QString HOST = "127.0.0.1";
QString PUBLIC_UUID = QUuid::createUuid().toString();

const int MAIN_LOCAL_PORT = 8081;

QMap<std::string, NodeDto*> NETWORK_NODE_LIST = {{HOST.toStdString()+":"+QString(PORT).toStdString(), new NodeDto(HOST.toStdString(),PORT,PUBLIC_UUID.toStdString())}};
