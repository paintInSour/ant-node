#ifndef MESSAGECONVERTER_H
#define MESSAGECONVERTER_H

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include<constant/NetworkConstant.h>


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
};

#endif // MESSAGECONVERTER_H
