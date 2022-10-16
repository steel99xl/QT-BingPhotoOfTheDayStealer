#include "basiccallback.h"

BasicCallBack::BasicCallBack(QObject *parent)
    : QObject{parent}
{

}

void BasicCallBack::test(){

    std::cout << "UWU it workded" << std::endl;


    connect(manager, &QNetworkAccessManager::finished, this, &BasicCallBack::replyFinished);

    manager->get(QNetworkRequest(QUrl("http://qt-project.org")));


}

void BasicCallBack::replyFinished(QNetworkReply *reply){
    if(reply->error() == QNetworkReply::NetworkError::NoError){
        std::cout << reply->readAll() << std::endl;
    } else{
        std::cout << reply->errorString() << std::endl;
    }

}

