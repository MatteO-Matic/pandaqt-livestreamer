#ifndef FORMCHANNELS_H
#define FORMCHANNELS_H

#include <QWidget>
#include <QListWidgetItem>
#include <QNetworkReply>
#include <forms/FormSettings.h>
#include <customwidgets/pandatvchannelthumbnail.h>

namespace Ui {
class FormChannels;
}

class FormChannels : public QWidget
{
    Q_OBJECT

public:
    FormChannels(QWidget *parent = 0, FormSettings *formsettings =0);
    ~FormChannels();

private:
    Ui::FormChannels *ui;
    FormSettings*frm_settings;
    int m_pagesRequested = 1; //1 is the first page
    QString m_currentCategory;
    QNetworkReply* m_replyChannelList;
    QList<QNetworkReply*> m_replyChannelInfo;
    void clearChannelList();
    bool m_bRefreshingChannels;
    pandatvChannelThumbnail *m_lastRightclickedChannelWidget;
    void requestChannelList(QString category);

public slots:
    void slot_categoryChanged(QString category);

private slots:
    void readOutput();
    void slot_getChannelList_requestFinished();
    void slot_contextmenu_addBookmark();
    void slot_onCustomContextMenu(const QPoint &pos);
    void slot_handleClicked(QListWidgetItem* item);
    void slot_onScrollPulled();
    void slot_on_buttonRefresh_clicked(QPoint *);

    signals:
     void addedBookmark(QString url);

};

#endif // FORMCHANNELS_H
