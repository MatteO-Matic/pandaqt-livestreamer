#include "pandatvgamecategorythumbnail.h"
#include <QObject>
#include <QtCore/QtCore>
#include <pandaqt5.h>
#include "pandanetworkcontroller.h"

pandatvGameCategoryThumbnail::pandatvGameCategoryThumbnail(QListWidget *parent) : QObject(parent), QListWidgetItem(parent)
{
    m_parent = parent;
    this->setIcon(QIcon(":/tempthumb2"));
    this->setText("...");
}

void pandatvGameCategoryThumbnail::loadJson(QJsonObject jitem)
{
    QJsonValue jname = jitem["ename"];
    m_ename = jname.toString();

    this->setText(jname.toString());

    //start downloding the thumbnail image
    QJsonValue imgSrc = jitem["img"];
    QUrl imgurl(imgSrc.toString());
    downloadImageUrl(imgurl);
    m_isJsonLoaded = true;
}

void pandatvGameCategoryThumbnail::downloadImageUrl(const QUrl &url)
{
    m_replyGameCategories = PandaNetworkController::RequestUrl(url);
    connect(m_replyGameCategories, SIGNAL(finished()), SLOT(slot_downloadFinished()));
}

void pandatvGameCategoryThumbnail::slot_downloadFinished()
{
    QNetworkReply*reply = (QNetworkReply*)sender();
    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "e:" << reply->url() << ":" << reply->errorString();
        reply->deleteLater();
        return;
    }

    QByteArray jpegData = reply->readAll();
    QPixmap pixmap;
    pixmap.loadFromData(jpegData);
    this->setIcon(QIcon(pixmap));

    reply->deleteLater();
}


QString pandatvGameCategoryThumbnail::getEname()
{
    if(!m_isJsonLoaded){
        qDebug() << "Can't get ename, json not loaded!";
        return "";
    }

    return m_ename;
}
