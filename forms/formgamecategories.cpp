#include "formgamecategories.h"
#include "ui_formgamecategories.h"
#include "customwidgets/pandatvgamecategorythumbnail.h"
#include "pandanetworkcontroller.h"
#include <QObject>
#include <QtCore/QtCore>

FormGameCategories::FormGameCategories(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormGameCategories)
{
    ui->setupUi(this);

    //handle click
    QObject::connect(ui->m_listWidgetGameCategories, SIGNAL(itemClicked(QListWidgetItem*)),this, SLOT (slot_handleClicked(QListWidgetItem*)));

    RequestGameCategories();
}

FormGameCategories::~FormGameCategories()
{
    delete ui;
}

void FormGameCategories::RequestGameCategories()
{
    m_replyGameCategories = PandaNetworkController::RequestGameCategories();
    connect(m_replyGameCategories, SIGNAL(finished()), this, SLOT(slot_finishedGameCategories()));
}

void FormGameCategories::slot_finishedGameCategories()
{
    QNetworkReply*reply = (QNetworkReply*)sender();

    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "Error in" << reply->url() << ":" << reply->errorString();
        reply->deleteLater();
        return;
    }

    QString strReply = (QString)reply->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(strReply.toUtf8());

    //Get the array of items
    QJsonObject json = doc.object();
    QJsonArray jitems = json["data"].toArray();


    for (int i = 0; i < jitems.size(); ++i)
    {
        QJsonObject jitem = jitems[i].toObject();
        //qDebug()<< jitem;
        pandatvGameCategoryThumbnail* tb = new pandatvGameCategoryThumbnail(ui->m_listWidgetGameCategories);
        m_listGameCategorythumbnail.append(tb);
        tb->loadJson(jitem);

        ui->m_listWidgetGameCategories->setIconSize(QSize(100,139));//(368,510));
        ui->m_listWidgetGameCategories->addItem(tb);

        //add it to our listwidget
        //ui->m_listChannels->addItem(channelWidget->m_thumbnailWidget);
    }
    reply->deleteLater();
}

void FormGameCategories::slot_handleClicked(QListWidgetItem *widget)
{
    pandatvGameCategoryThumbnail *pandaWidget = (pandatvGameCategoryThumbnail*)widget;

    emit categoryChanged(pandaWidget->getEname());
}


