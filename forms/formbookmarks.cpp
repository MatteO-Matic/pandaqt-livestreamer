#include "formbookmarks.h"
#include "ui_formbookmarks.h"
#include <QWidget>
#include <QMenu>
#include <forms/FormSettings.h>
#include <pandanetworkcontroller.h>

FormBookmarks::FormBookmarks(QWidget *parent, FormSettings *formsettings) :
    QWidget(parent),
    ui(new Ui::FormBookmarks)
{
    ui->setupUi(this);
    frm_settings = formsettings;

    //Poll bookmarks
    connect(m_timerPollOfflineBookmarks, SIGNAL(timeout()), this, SLOT(slot_tickPollOfflineBookmarks()));
    m_timerPollOfflineBookmarks->start(120000);

    //Refresh button
    connect(ui->m_buttonRefresh_Bookmarks, SIGNAL(leftClicked(QPoint*)), this, SLOT(slot_on_buttonRefresh_Bookmarks_clicked(QPoint*)));

    /* Bookmarklist
    */
    ui->m_listBookmarksWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->m_listBookmarksWidget, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(slot_onBookmarkContextMenu(const QPoint &)));
    connect(ui->m_listBookmarksWidget, SIGNAL (itemClicked(QListWidgetItem*)),this, SLOT (slot_handleClicked(QListWidgetItem*)));

    loadBookmarksintoWidget();
}

FormBookmarks::~FormBookmarks()
{
    delete ui;
}

void FormBookmarks::slot_onBookmarkContextMenu(const QPoint &pos)
{
    // Handle global position
    QPoint globalPos = ui->m_listBookmarksWidget->mapToGlobal(pos);

    // Create menu and insert some actions
    QMenu myMenu;

    QAction actionBookmark("Remove bookmark", this);
    connect(&actionBookmark, SIGNAL(triggered()), this, SLOT(slot_contextmenu_removeBookmark()));
    myMenu.addAction(&actionBookmark);


    m_lastRightclickedChannelWidget = ui->m_listBookmarksWidget->itemAt(pos);
    // Show context menu at handling position
    if(m_lastRightclickedChannelWidget)
        myMenu.exec(globalPos);
}

void FormBookmarks::slot_contextmenu_removeBookmark()
{

    frm_settings->removeBookmark(m_lastRightclickedChannelWidget->getUrl());

    delete m_lastRightclickedChannelWidget;
}

void FormBookmarks::slot_addBookmark(QString url)
{
    m_replyChannelInfo.append(PandaNetworkController::RequestUrl(url));
    connect(m_replyChannelInfo.last(), SIGNAL(finished()), this, SLOT(slot_getChannelInfo_requestFinished()));
}

void FormBookmarks::slot_getChannelInfo_requestFinished()
{
    QNetworkReply* reply = (QNetworkReply*)sender();
    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "Error in" << reply->url() << ":" << reply->errorString();
        m_replyChannelInfo.removeAll(reply);
        reply->deleteLater();
        return;
    }

    QString strReply = (QString)reply->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(strReply.toUtf8());
    QJsonObject json = doc.object();
    QJsonObject jdata = json["data"].toObject();

    ui->m_listBookmarksWidget->setIconSize(QSize(220,124));//338 × 190

    pandatvChannelThumbnail* channelWidget = new pandatvChannelThumbnail();
    channelWidget->loadJson(jdata);

    if(channelWidget->getStatus()=="2") //if online
    {
        //was in the offline list, then notify
        for(QList<pandatvChannelThumbnail*>::iterator i = m_listOfflineChannelthumbnails.begin();
            m_listOfflineChannelthumbnails.end()!=i; ++i)
        {
            if((*i)->getUrl() == channelWidget->getUrl())
            {
                //Nofify just changed from offline to online
               qDebug()<< "TodoTrayMessage"<< "Panda.tv ~ ", channelWidget->getName()+" is streaming\n"+channelWidget->getRoomName();
                // m_trayIcon->showMessage("Panda.tv ~ ", channelWidget->getName()+" is streaming\n"+channelWidget->getRoomName());
                m_listOfflineChannelthumbnails.removeAll(*i);
                break;
            }
        }

        //add channel
        ui->m_listBookmarksWidget->addItem(channelWidget);
    }
    else //If offline
    {
        //offline list
        //Check if it already is in the offlinelist
        bool bShouldAdd = true;
        for(QList<pandatvChannelThumbnail*>::iterator i = m_listOfflineChannelthumbnails.begin();
            m_listOfflineChannelthumbnails.end()!=i; ++i)
        {
            if((*i)->getUrl() == channelWidget->getUrl())
            {
                //already in the list
                bShouldAdd = false;
                delete channelWidget;
                break;
            }
        }

        if(bShouldAdd)
            m_listOfflineChannelthumbnails.append(channelWidget);
    }
    m_replyChannelInfo.removeAll(reply);
    reply->deleteLater();
}

void FormBookmarks::loadBookmarksintoWidget()
{
    //Create widgets of everything and load
    ui->m_listBookmarksWidget->clear();

    //Load stored bookmarks
    QList<QString> bookmarks = frm_settings->getBookmarkList();

    for(int i =0; i< bookmarks.length();++i)
    {
        QUrl url(bookmarks.at(i));

        m_replyChannelInfo.append(PandaNetworkController::RequestUrl(url));

        connect(m_replyChannelInfo.last(), SIGNAL(finished()), this, SLOT(slot_getChannelInfo_requestFinished()));
    }
}

void FormBookmarks::slot_on_buttonRefresh_Bookmarks_clicked(QPoint *)
{
    for(QList<QNetworkReply*>::iterator i = m_replyChannelInfo.begin();
        i!=m_replyChannelInfo.end();++i)
    {
        if((*i) && !(*i)->isFinished())
        {
            return;
        }
    }
    loadBookmarksintoWidget();
}

void FormBookmarks::slot_tickPollOfflineBookmarks()
{
    for(QList<pandatvChannelThumbnail*>::iterator i = m_listOfflineChannelthumbnails.begin();
        i != m_listOfflineChannelthumbnails.end(); ++i)
    {
        m_listReplyChannelInfoOffline.append(PandaNetworkController::RequestUrl((*i)->getUrl()));
        connect(m_listReplyChannelInfoOffline.last(), SIGNAL(finished()), this, SLOT(slot_getChannelInfo_requestFinished()));
    }
}
