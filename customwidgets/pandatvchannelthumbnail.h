#ifndef PANDATVCHANNELTHUMBNAIL_H
#define PANDATVCHANNELTHUMBNAIL_H

#include <QtNetwork/QtNetwork>
#include <QListWidgetItem>
#include <QObject>

class pandatvChannelThumbnail: public QObject, public QListWidgetItem {
    Q_OBJECT
public:
    pandatvChannelThumbnail(QListWidget *parent = Q_NULLPTR);
    virtual ~pandatvChannelThumbnail();
    void downloadImageUrl(const QUrl&);
    void loadJson(QJsonObject);
    QString getUrl();
    QString getStatus();
    QString getName();
    QString getRoomName();
    QString getId();

public slots:
    void slot_downloadFinished();

private:
    QString m_status;

    QNetworkReply* m_networkReply = NULL;
    QString m_id;
    QObject* m_parent;
    QProcess *myProcess;
    QString m_name;
    QString m_roomName;

};

#endif // PANDATVCHANNELTHUMBNAIL_H
