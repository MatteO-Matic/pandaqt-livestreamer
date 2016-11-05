#ifndef FORMBOOKMARKS_H
#define FORMBOOKMARKS_H

#include <QWidget>
#include <customwidgets/pandalistwidget.h>
#include <customwidgets/pandatvchannelthumbnail.h>
#include <QTimer>
#include <forms/FormSettings.h>

namespace Ui {
class FormBookmarks;
}

class FormBookmarks : public QWidget
{
    Q_OBJECT

public:
     FormBookmarks(QWidget *parent = 0, FormSettings *formsettings = 0);
    ~FormBookmarks();

public slots:
     void slot_addBookmark(QString url);
private slots:
        void slot_on_buttonRefresh_Bookmarks_clicked(QPoint*);
        void slot_tickPollOfflineBookmarks();
        void slot_contextmenu_removeBookmark();
        void slot_onBookmarkContextMenu(const QPoint &pos);
        void slot_getChannelInfo_requestFinished();

private:
    Ui::FormBookmarks *ui;
    void loadBookmarksintoWidget();
    QTimer *m_timerPollOfflineBookmarks = new QTimer(this);
    FormSettings *frm_settings;
    QList<QNetworkReply*> m_replyChannelInfo;
    QList<QNetworkReply*> m_listReplyChannelInfoOffline;
    QList<pandatvChannelThumbnail*> m_listOfflineChannelthumbnails;

     pandatvChannelThumbnail* m_lastRightclickedChannelWidget;
};

#endif // FORMBOOKMARKS_H
