#include "basiccallback.h"

BasicCallBack::BasicCallBack(QObject *parent)
    : QObject{parent}
{

}

void BasicCallBack::test(){

    std::cout << "UWU it workded" << std::endl;

    manager = new QNetworkAccessManager(this);

    connect(manager, &QNetworkAccessManager::finished, this, &BasicCallBack::replyFinished);

    manager->get(QNetworkRequest(QUrl("http://qt-project.org")));


}

void BasicCallBack::replyFinished(QNetworkReply *reply){
    if(reply->error() == QNetworkReply::NetworkError::NoError){
        QString data = (QString)reply->readAll();
        QByteArray Bdata = data.toLocal8Bit();
        const char *output = Bdata.data();
        std::cout << output << std::endl;
    } else{
        QString data = (QString)reply->errorString();
        QByteArray Bdata = data.toLocal8Bit();
        const char *output = Bdata.data();
        std::cout << output << std::endl;
    }

}

