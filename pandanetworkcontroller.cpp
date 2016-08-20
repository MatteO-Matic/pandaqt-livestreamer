#include "pandanetworkcontroller.h"
#include <QtNetwork>


static QNetworkAccessManager m_networkAccessManager;

QString m_platform = "android";
QString m_version = "1.0.1.1303";

QUrl m_urlGameCategories(QString("http://api.m.panda.tv/ajax_get_all_subcate?__plat=%1&__version=%2").arg(m_platform, m_version));


QNetworkReply* PandaNetworkController::RequestGameCategories()
{
    return RequestUrl(m_urlGameCategories);
}

QNetworkReply* PandaNetworkController::RequestUrl(QUrl url)
{
   return m_networkAccessManager.get(QNetworkRequest(url));
}
