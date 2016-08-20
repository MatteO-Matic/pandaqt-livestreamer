#include "pandatvchannelthumbnail.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QObject>
#include "pandanetworkcontroller.h"

pandatvChannelThumbnail::pandatvChannelThumbnail(QListWidget *parent) : QObject(parent), QListWidgetItem(parent)
{
    m_parent = parent;
    setIcon(QIcon(":/tempthumb"));
    setText("...");
}


pandatvChannelThumbnail::~pandatvChannelThumbnail()
{

}

void pandatvChannelThumbnail::downloadImageUrl(const QUrl &url)
{
    m_networkReply = PandaNetworkController::RequestUrl(url);
    connect(m_networkReply, SIGNAL(finished()), SLOT(slot_downloadFinished()));
}

void pandatvChannelThumbnail::loadJson(QJsonObject jitem)
{
    //some data is different
    if(jitem.begin().key() == "info")
    {
        //http://room.api.m.panda.tv/index.php?method=room.getinfo&roomid=3331&__plat=android_hd&&__version=1.0.1.1303
        //get name
        jitem = jitem["info"].toObject();
        //Host info
        QJsonObject jhostinfo = jitem["hostinfo"].toObject();
        m_name = jhostinfo["name"].toString();

        //Video info
        QJsonObject jvideoinfo = jitem["videoinfo"].toObject();
        m_status = jvideoinfo["status"].toString();

        //Room info same(kinda) as [items]
        jitem = jitem["roominfo"].toObject();
    }
    else
    {
        //https://github.com/MatteO-Matic/pandatvAPI/blob/master/jsonsample/catelist_.json
        //get name
        QJsonObject juserinfo = jitem["userinfo"].toObject();
        m_name = juserinfo["nickName"].toString();

    }

    setText(m_name);

    m_roomName = jitem["name"].toString();
    m_id = jitem["id"].toString();



    //start downloding the thumbnail image
    QJsonObject jpictures = jitem["pictures"].toObject();
    QJsonValue imgSrc = jpictures["img"];
    QUrl imgurl(imgSrc.toString());

    downloadImageUrl(imgurl);
}

QString pandatvChannelThumbnail::getUrl()
{
    return QString("http://api.m.panda.tv/ajax_get_liveroom_baseinfo?roomid="+m_id+"&slaveflag=1&type=json&__version=1.0.1.1303&__plat=android");
}

QString pandatvChannelThumbnail::getStatus()
{
    return m_status;
}

QString pandatvChannelThumbnail::getName()
{
    return m_name;
}

QString pandatvChannelThumbnail::getRoomName()
{
    return m_roomName;
}

QString pandatvChannelThumbnail::getId()
{
    return m_id;
}

void pandatvChannelThumbnail::slot_downloadFinished()
{
    QNetworkReply* reply = (QNetworkReply*)sender();
    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "e:" << reply->url() << ":" << reply->errorString();
        reply->deleteLater();
        return;
    }

    QByteArray jpegData = reply->readAll();
    QPixmap pixmap;
    pixmap.loadFromData(jpegData);

    if(pixmap.isNull()){
        qDebug()<< "pixmap null";
    }
    else{
        QIcon icon(pixmap);
        setIcon(icon);
    }
    reply->deleteLater();
}
