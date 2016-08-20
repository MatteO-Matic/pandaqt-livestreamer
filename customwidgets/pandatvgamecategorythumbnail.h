#ifndef PANDATVGAMECATEGORYTHUMBNAIL_H
#define PANDATVGAMECATEGORYTHUMBNAIL_H

#include <QListWidgetItem>
#include <QNetworkReply>
#include <QObject>

class pandatvGameCategoryThumbnail: public QObject, public QListWidgetItem {
    Q_OBJECT
public:
    pandatvGameCategoryThumbnail(QListWidget *parent = Q_NULLPTR);
    void loadJson(QJsonObject jitem);
    void downloadImageUrl(const QUrl&);

public slots:
    void slot_downloadFinished();
    QString getEname();

private:
    QObject* m_parent;
    QString m_ename;
    bool m_isJsonLoaded = false;
    QNetworkReply* m_replyGameCategories;
};

#endif // PANDATVGAMECATEGORYTHUMBNAIL_H
