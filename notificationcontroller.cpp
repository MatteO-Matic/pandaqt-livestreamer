#include "notificationcontroller.h"

// QT
#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>

//#include "libsnore/snore.h"
//#include "libsnore/notification/notification.h"

NotificationController::NotificationController(QObject *parent) : QObject(parent)
//  ,core(Snore::SnoreCore::instance()),
//    icon(QString(":/pandatray")),
//    snoreApplication(Snore::Application(qApp->applicationName(), icon)),
//    alert(Snore::Alert(QString("Default"), icon))
{
//    //Get the core
//    Snore::SnoreCore::instance().loadPlugins(
//                Snore::SnorePlugin::Backend | Snore::SnorePlugin::SecondaryBackend);

//    //All notifications have to have icon, so prebuild one
//    core.registerApplication(snoreApplication);

//    //Also alert is mandatory, just choose the default one
//    snoreApplication.addAlert(alert);

}

void NotificationController::showNotification(const QString &title, const QString &text)
{

}
