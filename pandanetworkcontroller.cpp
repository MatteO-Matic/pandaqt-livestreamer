#include "pandanetworkcontroller.h"
#include <QtNetwork>


static QNetworkAccessManager m_networkAccessManager;

QString m_platform = "android";
QString m_version = "1.0.1.1303";

QUrl m_urlGameCategories(QString("http://api.m.panda.tv/ajax_get_all_subcate?__plat=%1&__version=%2").arg(m_platform, m_version));

//version=1.0.1.1303&__plat=android_hd"
//QUrl m_urlGetLiveList(QString("http://api.m.panda.tv/ajax_get_live_list_by_cate?cate=%1&pageno=1&pagenum=20&__version=%1&__plat=%2").arg(m_version, m_platform));
QString m_urlGetLiveList("http://api.m.panda.tv/ajax_get_live_list_by_cate?");

QNetworkReply* PandaNetworkController::GetLiveListByCategory(QString category, int pageno, int pagenum)
{
    //?cate=%1&pageno=1&pagenum=20&__version=%1&__plat=%2").arg(m_version, m_platform));
    return RequestUrl(QUrl(m_urlGetLiveList+QString("cate=%1&pageno=%2&pagenum=%3&__version=%4&__plat=%5").arg(category, QString::number(pageno), QString::number(pagenum), m_version, m_platform)));
}

QNetworkReply* PandaNetworkController::RequestGameCategories()
{
    return RequestUrl(m_urlGameCategories);
}

QNetworkReply* PandaNetworkController::RequestUrl(QUrl url)
{
   return m_networkAccessManager.get(QNetworkRequest(url));
}
