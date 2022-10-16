#ifndef BASICCALLBACK_H
#define BASICCALLBACK_H

#include <QObject>
#include <iostream>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

class BasicCallBack : public QObject
{
    Q_OBJECT
public:
    explicit BasicCallBack(QObject *parent = nullptr);

    Q_INVOKABLE void test();

signals:

public slots:
    void replyFinished (QNetworkReply *reply);

private:
    QNetworkAccessManager *manager;

};

#endif // BASICCALLBACK_H
