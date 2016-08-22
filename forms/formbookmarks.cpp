#include "formbookmarks.h"
#include "ui_formbookmarks.h"
#include <QWidget>

FormBookmarks::FormBookmarks(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormBookmarks)
{
    ui->setupUi(this);

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
    for(int i=0;i<m_listBookmarkthumbnails.length();++i)
    {
        if(m_listBookmarkthumbnails.at(i) == m_lastRightclickedChannelWidget)
        {
            frm_settings->removeBookmark(m_listBookmarkthumbnails.at(i)->getUrl());

            m_listBookmarkthumbnails.removeAt(i);

            delete m_lastRightclickedChannelWidget;
            return;
        }
    }
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
        m_replyChannelInfo.append(m_networkAccessManager->get(QNetworkRequest(url)));
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
        m_listReplyChannelInfoOffline.append(m_networkAccessManager->get(QNetworkRequest((*i)->getUrl())));
        connect(m_listReplyChannelInfoOffline.last(), SIGNAL(finished()), this, SLOT(slot_getChannelInfo_requestFinished()));
    }
}
