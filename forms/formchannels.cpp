#include "formchannels.h"
#include "ui_formchannels.h"
#include <QProcess>
#include <pandanetworkcontroller.h>
#include "customwidgets/pandatvchannelthumbnail.h"

FormChannels::FormChannels(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormChannels)
{
    ui->setupUi(this);

    /*  Toolbar
     * */
    //Refresh button
    connect(ui->m_buttonRefresh, SIGNAL(leftClicked(QPoint*)), this, SLOT(slot_on_buttonRefresh_clicked(QPoint*)));

    /* Channelthumbnail
    */
    ui->m_listChannels->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->m_listChannels, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(slot_onCustomContextMenu(const QPoint &)));

    connect(ui->m_listChannels, SIGNAL (itemClicked(QListWidgetItem*)),this, SLOT (slot_handleClicked(QListWidgetItem*)));
    connect(ui->m_listChannels, SIGNAL(scrollPulled()), this, SLOT(slot_onScrollPulled()));
}

FormChannels::~FormChannels()
{
    delete ui;
}


void FormChannels::slot_onScrollPulled()
{
    qDebug() << "Scroll pulled";
    //Check total, if we have less then total showing add/request next batch of items
    if( m_currentCategory == ""){
        return;
    }

    m_pagesRequested++; //We want to request the next page

    qDebug() << url;
    m_replyChannelList = PandaNetworkController::GetLiveListByCategory(m_currentCategory, m_pagesRequested, 20);
    connect(m_replyChannelList, SIGNAL(finished()), this, SLOT(slot_getChannelList_requestFinished()));
}

void FormChannels::slot_on_buttonRefresh_clicked(QPoint *)
{
    if(!m_bRefreshingChannels)
    {
        m_bRefreshingChannels = true;
        clearChannelList();
        requestChannelList(m_currentCategory);
    }
}

void FormChannels::clearChannelList()
{
    m_pagesRequested =1;
    ui->m_listChannels->clear();
}

void FormChannels::readOutput()
{
    QByteArray outData = ((QProcess*)sender())->readAllStandardOutput();
    qDebug().noquote()<<"livestreamer: "<< QString(outData);
}

void FormChannels::slot_handleClicked(QListWidgetItem* item)
{
    QString program = "livestreamer";
    QStringList arguments;


    arguments <<"http://www.panda.tv/" + ((pandatvChannelThumbnail*)item)->getId();
    arguments = arguments + frm_settings->getFullCommand().split(QRegExp("\\s"));

    QProcess* myProcess = new QProcess(qApp);
    myProcess->start(program, arguments);

    connect(myProcess, SIGNAL(readyReadStandardOutput()), this, SLOT(readOutput()));
}

void FormChannels::requestChannelList(QString category)
{
    if( category == ""){
        qDebug() << "category can't be empty!";
        return;
    }
    m_currentCategory = category;
    qDebug() << "Requesting channels" << category;

    clearChannelList();
    m_replyChannelList = PandaNetworkController::GetLiveListByCategory(category, 1, 20);
    connect(m_replyChannelList, SIGNAL(finished()), this, SLOT(slot_getChannelList_requestFinished()));
}


void FormChannels::slot_onCustomContextMenu(const QPoint &pos)
{
    // Handle global position
    QPoint globalPos = ui->m_listChannels->mapToGlobal(pos);

    // Create menu and insert some actions
    QMenu myMenu;

    QAction actionBookmark("Bookmark", this);
    connect(&actionBookmark, SIGNAL(triggered()), this, SLOT(slot_contextmenu_addBookmark()));
    myMenu.addAction(&actionBookmark);

    m_lastRightclickedChannelWidget = ui->m_listChannels->itemAt(pos);
    // Show context menu at handling position
    if(m_lastRightclickedChannelWidget)
        myMenu.exec(globalPos);
}

void FormChannels::slot_getChannelList_requestFinished()
{
    QNetworkReply*reply = (QNetworkReply*)sender();
    if(!m_replyChannelList)
    {
        qDebug() << "replychannel is null!";
        m_bRefreshingChannels = false;
        return;
    }

    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "Error in" << reply->url() << ":" << reply->errorString();
        reply->deleteLater();
        m_bRefreshingChannels = false;
        return;
    }

    QString strReply = (QString)((QNetworkReply*)sender())->readAll();
    // qDebug() << strReply;
    QJsonDocument doc = QJsonDocument::fromJson(strReply.toUtf8());
    //  qDebug() << jsonResponse<<endl;

    //Get the array of items
    QJsonObject json = doc.object();
    QJsonObject jdata = json["data"].toObject();
    QJsonArray jitems = jdata["items"].toArray();

    ui->m_listChannels->setIconSize(QSize(220,124));//338 × 190

    for (int i = 0; i < jitems.size(); ++i)
    {
        QJsonObject jitem = jitems[i].toObject();

        pandatvChannelThumbnail* channelWidget = new pandatvChannelThumbnail();
        channelWidget->loadJson(jitem);

        //add it to our listwidget
        ui->m_listChannels->addItem(channelWidget);
    }
    reply->deleteLater();
    m_bRefreshingChannels = false;
}


void FormChannels::slot_contextmenu_addBookmark()
{
    for(int i=0;i<m_listChannelthumbnails.length();++i)
    {
        if(m_listChannelthumbnails.at(i) == m_lastRightclickedChannelWidget)
        {
            //Save channel url or something to qsettings
            frm_settings->addBookmark(m_listChannelthumbnails.at(i)->getUrl());

            QUrl url(m_listChannelthumbnails.at(i)->getUrl());

            m_replyChannelInfo.append(m_networkAccessManager->get(QNetworkRequest(url)));
            connect(m_replyChannelInfo.last(), SIGNAL(finished()), this, SLOT(slot_getChannelInfo_requestFinished()));
            return;
        }
    }
}

//Used when loading all bookmarks, polling the offlinelist and new bookmark added
void FormChannels::slot_getChannelInfo_requestFinished()
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
                m_trayIcon->showMessage("Panda.tv ~ ", channelWidget->getName()+" is streaming\n"+channelWidget->getRoomName());
                m_listOfflineChannelthumbnails.removeAll(*i);
                break;
            }
        }

        //add channel
        m_listBookmarkthumbnails.append(channelWidget);
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
