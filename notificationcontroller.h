#ifndef NOTIFICATIONCONTROLLER_H
#define NOTIFICATIONCONTROLLER_H

#include <QObject>


class NotificationController : public QObject
{
    Q_OBJECT
public:
    explicit NotificationController(QObject *parent = 0);

signals:

public slots:
    void showNotification(const QString & title, const QString & text);

private:


    // Notfications
//    Snore::SnoreCore &core;
//    Snore::Icon icon;
//    Snore::Application snoreApplication;
//    Snore::Alert alert;
};

#endif // NOTIFICATIONCONTROLLER_H
