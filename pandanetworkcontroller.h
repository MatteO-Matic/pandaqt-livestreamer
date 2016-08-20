#ifndef PANDANETWORKCONTROLLER_H
#define PANDANETWORKCONTROLLER_H
#include <QNetworkAccessManager>
#include <QNetworkReply>

class PandaNetworkController
{
public:

    static QNetworkReply* RequestGameCategories();
    static QNetworkReply *RequestUrl(QUrl url);

private:

};

#endif // PANDANETWORKCONTROLLER_H
