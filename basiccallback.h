#ifndef BASICCALLBACK_H
#define BASICCALLBACK_H

#include <QObject>
#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>
#include <QDesktopServices>

#include <QImage>

class BasicCallBack : public QObject
{
    Q_OBJECT
public:
    struct StolenImage{
        bool HasUrl = false;
        std::string PageBuffer = "";
        std::string Url = "";
        std::string FileName = "";
        QImage QTCompliance;
        QByteArray Bytes;

        operator bool(){return HasUrl;}
    };

    StolenImage m_ImageToSteal;

    const char *BingLink = "https://www.bing.com/";



    explicit BasicCallBack(QObject *parent = nullptr);

    Q_INVOKABLE void test();

signals:

public slots:

    std::string BingGetter(StolenImage ImageToSteal);

    std::string BingPageToWallPaper(StolenImage ImageToSteal);

    void SaveStolenImage(StolenImage ImageToSteal);

    inline QString getImageName(){return m_ImageToSteal.FileName.c_str();}

    inline QString getImageLink(){return m_ImageToSteal.Url.c_str();} // warning can just return bing home page

    inline void openSource(){QDesktopServices::openUrl(QUrl("https://github.com/steel99xl/QT-BingPhotoOfTheDayStealer"));}

    void planForImageTheft();

    void exicutePlan(QString String);

private:
    QNetworkAccessManager *manager;

    QNetworkReply *reply;

};

#endif // BASICCALLBACK_H
