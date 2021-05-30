#include "TextMessageService.h"
#include <iostream>

using namespace std;

TextMessageProcessor::TextMessageProcessor()
{

}

bool TextMessageProcessor::isMatch(QString type){
    if(type == "TextMessage"){
        std::cout<<"TextMessage"<<std::endl;
        return true;
    } else {
        return false;
    }
}

void TextMessageProcessor::processMessage(QJsonObject message){
    QJsonValue textValue = message.take("text");

    cout<<"Received: "<<textValue.toString().toStdString();
}
