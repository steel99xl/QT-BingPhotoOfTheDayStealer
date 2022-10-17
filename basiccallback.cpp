#include "basiccallback.h"

BasicCallBack::BasicCallBack(QObject *parent)
    : QObject{parent}
{

}

void BasicCallBack::test(){

    std::cout << "UWU it workded" << std::endl;


    StolenImage ImageToSteal;
    ImageToSteal.PageBuffer = BingGetter(ImageToSteal);

    //wait for connection

    BaseData = "";


    ImageToSteal.Url = BingPageToWallPaper(ImageToSteal);
    std::cout << "Getting Photo" << std::endl;

    ImageToSteal.HasUrl = true;
    ImageToSteal.FileName = BingPageToWallPaper(ImageToSteal);

    ImageToSteal.PageBuffer = BingGetter(ImageToSteal);



    SaveStolenImage(ImageToSteal);
    std::cout << "Thing Done" << std::endl;
    //std::cout << BaseData.toStdString() << std::endl;

    //return ImageToSteal.FileName.c_str();

}

void BasicCallBack::replyFinished(QNetworkReply *reply){
    if(reply->error() == QNetworkReply::NetworkError::NoError){
        this->BaseData = (QString)reply->readAll();
    } else{
        this->BaseData = (QString)reply->errorString();
    }

}




// Yes it just gets the bing homepage...
std::string BasicCallBack::BingGetter(StolenImage ImageToSteal){
    std::string data;

    manager = new QNetworkAccessManager(this);

    manager->setAutoDeleteReplies(true);

    QEventLoop loop;
    //connect(manager, &QNetworkAccessManager::finished, this, &BasicCallBack::replyFinished);
    if(ImageToSteal){
        QNetworkReply *Temp = manager->get(QNetworkRequest(QUrl((QString)ImageToSteal.Url.c_str())));
        connect(Temp, &QNetworkReply::finished, &loop, &QEventLoop::quit);
        loop.exec();
        data = (std::string)Temp->readAll().toStdString();

    } else {
        QNetworkReply *Temp = manager->get(QNetworkRequest(QUrl((QString)BingLink)));
        connect(Temp, &QNetworkReply::finished, &loop, &QEventLoop::quit);
        loop.exec();
        data = (std::string)Temp->readAll().toStdString();
    }


    return data;
}

std::string BasicCallBack::BingPageToWallPaper(StolenImage ImageToSteal){
    std::string Output; // This is will be the url to the wallpaper

    std::size_t StartPos = ImageToSteal.PageBuffer.find("background-image: url(")+22;

    std::size_t EndPos = ImageToSteal.PageBuffer.find("&", StartPos);
    if(ImageToSteal){
        StartPos = ImageToSteal.PageBuffer.find(".", StartPos) + 1;
        Output = ImageToSteal.PageBuffer.substr(StartPos, EndPos-StartPos);
    } else {
        Output = BingLink + ImageToSteal.PageBuffer.substr(StartPos, EndPos-StartPos);
    }

    return Output;


}

void BasicCallBack::SaveStolenImage(StolenImage ImageToSteal){
    std::ofstream Contraband;

    if(strcmp(ImageToSteal.FileName.c_str() , "") == 0){
        Contraband.open(ImageToSteal.Url.c_str(), std::ios::out);
    } else {
        Contraband.open(ImageToSteal.FileName.c_str(), std::ios::out);
    }

    if(Contraband.is_open()){
        Contraband << ImageToSteal.PageBuffer + "\n";
        Contraband.close();
    } else {
        std::cout << "ERROR could not open FILE for writeing" << std::endl;

    }

}

void BasicCallBack::planForImageTheft()
{
    m_ImageToSteal.HasUrl = false;
    m_ImageToSteal.PageBuffer = BingGetter(m_ImageToSteal);

    m_ImageToSteal.Url = BingPageToWallPaper(m_ImageToSteal);

    m_ImageToSteal.HasUrl = true;
    m_ImageToSteal.FileName = BingPageToWallPaper(m_ImageToSteal);

    m_ImageToSteal.PageBuffer = BingGetter(m_ImageToSteal);
}

void BasicCallBack::exicutePlan()
{
    SaveStolenImage(m_ImageToSteal);
}

