#ifndef FORMCHANNELS_H
#define FORMCHANNELS_H

#include <QWidget>
#include <QListWidgetItem>
#include <QNetworkReply>

namespace Ui {
class FormChannels;
}

class FormChannels : public QWidget
{
    Q_OBJECT

public:
    explicit FormChannels(QWidget *parent = 0);
    ~FormChannels();
    void requestChannelList(QString category);

private:
    Ui::FormChannels *ui;
    void readOutput();
    int m_pagesRequested = 1; //1 is the first page
    QString m_currentCategory;
    QNetworkReply* m_replyChannelList;
    void clearChannelList();
    bool m_bRefreshingChannels;

private slots:
    void slot_getChannelList_requestFinished();
    void slot_getChannelInfo_requestFinished();
    void slot_contextmenu_addBookmark();
    void slot_onCustomContextMenu(const QPoint &pos);
    void slot_handleClicked(QListWidgetItem* item);

};

#endif // FORMCHANNELS_H
