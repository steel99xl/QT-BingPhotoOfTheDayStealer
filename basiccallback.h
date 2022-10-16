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


class BasicCallBack : public QObject
{
    Q_OBJECT
public:
    struct StolenImage{
        bool HasUrl = false;
        std::string PageBuffer = "";
        std::string Url = "";
        std::string FileName = "";

        operator bool(){return HasUrl;}
    };

    const char *BingLink = "https://www.bing.com/";

    QString BaseData;


    explicit BasicCallBack(QObject *parent = nullptr);

    Q_INVOKABLE void test();

signals:

public slots:
    void replyFinished (QNetworkReply *reply);

    std::string BingGetter(StolenImage ImageToSteal);

    std::string BingPageToWallPaper(StolenImage ImageToSteal);

    void SaveStolenImage(StolenImage ImageToSteal);

private:
    QNetworkAccessManager *manager;

};

#endif // BASICCALLBACK_H
