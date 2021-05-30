#ifndef MESSAGECONVERTER_H
#define MESSAGECONVERTER_H

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <constant/NetworkConstant.h>
#include <iostream>


class MessageConverter
{
public:
    MessageConverter();

    static QJsonObject createBasicJsonMessage(){
        QJsonObject json;
        json.insert("host",HOST);
        json.insert("port",PORT);
        json.insert("uuid",PUBLIC_UUID);
        return json;
    }

    static QByteArray toTextMessage(QString text){
        QJsonObject json = createBasicJsonMessage();
        json.insert("type","TextMessage");
        json.insert("text",text);
        return jsonToByteArray(json);

    }

    static QByteArray toRegistrationNodeMessage(){
        QJsonObject json = createBasicJsonMessage();
        json.insert("type","RegistrationCall");
        return jsonToByteArray(json);
    }

    static QByteArray toRegistrationResponse(){
        QJsonArray jsonArray;
        foreach(auto node, NETWORK_NODE_LIST){
            QJsonObject jsonObject;
            jsonObject.insert("host",QString::fromStdString(node->host));
            jsonObject.insert("port",node->port);
            jsonObject.insert("uuid",QString::fromStdString(node->uuid));

            jsonArray.append(jsonObject);
        }
        QJsonObject jsonNodeList;
        jsonNodeList.insert("type","RegistrationResponse");
        jsonNodeList.insert("nodes",jsonArray);
        return jsonToByteArray(jsonNodeList);
    }

    static QByteArray jsonToByteArray(QJsonObject json){
        return QJsonDocument(json).toJson(QJsonDocument::Compact);
    }

    static QList<NodeDto*> toRegistrationResposneList(QJsonObject message){
        std::cout<<"converter"<<std::endl;
        QJsonArray nodeArray = message.take("nodes").toArray();

        QList<NodeDto*> nodeList;
        foreach(auto node,nodeArray){
            auto nodeObj = node.toObject();

            NodeDto *nodeDto = new NodeDto(nodeObj.take("host").toString().toStdString(),nodeObj.take("port").toInt(),nodeObj.take("uuid").toString().toStdString());
            nodeList.append(nodeDto);
        }
        return nodeList;
    }

    static NodeDto* toNodeDto(QJsonObject message){
      return new NodeDto(message.take("host").toString().toStdString(),message.take("port").toInt(),message.take("uuid").toString().toStdString());

    }

    static QByteArray toNodeDtoMessageTimeCheck(){
        QJsonObject json = createBasicJsonMessage();
        json.insert("type","timeCheck");
        return jsonToByteArray(json);
    }

    static QByteArray toNodeDtoMessageTimeChecked(){
        QJsonObject json = createBasicJsonMessage();
        json.insert("type","timeChecked");
        return jsonToByteArray(json);
    }


    static std::string toHostPort(std::string host,int port){
        std::string hostPort = host+":"+std::to_string(port);
        std::cout<<"Transformed to host("<<host<<"):port("<<port<<") :"<<hostPort<<std::endl;
        return hostPort;
    }
};

#endif // MESSAGECONVERTER_H
