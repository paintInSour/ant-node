#include "NodeDto.h"

#include <QString>
#include <string>

NodeDto::NodeDto(std::string host,int port)
{
    this->host = host;
    this->port = port;
}

NodeDto::NodeDto(std::string host,int port,std::string uuid)
{
    this->host = host;
    this->port = port;
    this->uuid = uuid;
}
