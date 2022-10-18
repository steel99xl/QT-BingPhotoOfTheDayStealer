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


    ImageToSteal.Url = BingPageToWallPaper(ImageToSteal);
    std::cout << "Getting Photo" << std::endl;

    ImageToSteal.HasUrl = true;
    ImageToSteal.FileName = BingPageToWallPaper(ImageToSteal);

    ImageToSteal.PageBuffer = BingGetter(ImageToSteal);



    SaveStolenImage(ImageToSteal);
    std::cout << "Thing Done" << std::endl;
    std::cout << ImageToSteal.PageBuffer.length() << std::endl;
    //std::cout << BaseData.toStdString() << std::endl;

    //return ImageToSteal.FileName.c_str();

}




// Yes it just gets the bing homepage...
std::string BasicCallBack::BingGetter(StolenImage ImageToSteal){
    std::string data;

    manager = new QNetworkAccessManager(this);

    manager->setAutoDeleteReplies(true);


    QEventLoop loop;
    if(ImageToSteal){
        reply = manager->get(QNetworkRequest(QUrl((QString)ImageToSteal.Url.c_str())));
        connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
        loop.exec();
        this->m_ImageToSteal.QTCompliance.loadFromData(reply->readAll());
        data = (std::string)reply->readAll().toStdString();

    } else {
        reply = manager->get(QNetworkRequest(QUrl((QString)BingLink)));
        connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
        loop.exec();
        data = (std::string)reply->readAll().toStdString();
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
    //std::ofstream Contraband;

    //ImageToSteal.QTCompliance.loadFromData(ImageToSteal.Bytes);
    ImageToSteal.QTCompliance.save(ImageToSteal.FileName.c_str());
    /*
    QFile file(ImageToSteal.FileName.c_str());

    if(!file.open(QIODevice::WriteOnly)){
        return;
    }
    QDataStream out(&file);

    out.writeRawData(ImageToSteal.PageBuffer.c_str(), ImageToSteal.PageBuffer.length());

    file.close();
    */


    /*
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
    */

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

void BasicCallBack::exicutePlan(QString String)
{
    std::cout << String.toStdString() << std::endl;
    String = String.mid(7);
    m_ImageToSteal.FileName = String.toStdString()+"/"+ m_ImageToSteal.FileName;
    std::cout << m_ImageToSteal.FileName << std::endl;
    SaveStolenImage(m_ImageToSteal);
}

