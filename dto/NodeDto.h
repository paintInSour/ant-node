#ifndef NODEDTO_H
#define NODEDTO_H

#include <string>



class NodeDto
{
public:
    NodeDto(std::string host,int port);
    NodeDto(std::string host,int port,std::string uuid);
    std::string host;
    std::string uuid;
    int port;
};

#endif // NODEDTO_H
