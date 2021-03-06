#include "pandaqt5.h"
#include "ui_pandaqt5.h"

#include <QtWidgets>
#include <QtNetwork/QNetworkAccessManager>
#include <QUrl>

#include "customwidgets/pandatvchannelthumbnail.h"

#include "forms/FormSettings.h"
#include "forms/formgamecategories.h"
#include "forms/formbookmarks.h"
#include "forms/formchannels.h"


Pandaqt5::Pandaqt5(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Pandaqt5)
{
    ui->setupUi(this);
    qDebug() << "Adding forms";

    //Adding forms
    frm_settings = new FormSettings(ui->tabWidget);
    ui->tabWidget->addTab(frm_settings, "Settings");

    frm_channels = new FormChannels(ui->tabWidget, frm_settings);
    ui->tabWidget->addTab(frm_channels, "Channels");

    frm_bookmarks = new FormBookmarks(ui->tabWidget, frm_settings);
    ui->tabWidget->addTab(frm_bookmarks, "Bookmarks");

    frm_gameCategories = new FormGameCategories(ui->tabWidget);
    ui->tabWidget->addTab(frm_gameCategories, "GameCategories");

    connect(frm_gameCategories, SIGNAL(categoryChanged(QString)), this, SLOT(slot_categoryChanged(QString)));
    connect(frm_gameCategories, SIGNAL(categoryChanged(QString)), frm_channels, SLOT(slot_categoryChanged(QString)));

    connect(frm_channels, SIGNAL(addedBookmark(QString)), frm_bookmarks, SLOT(slot_addBookmark(QString)));

    ui->tabWidget->tabBar()->hide();
    //end add forms

    //Startup with game categories
    ui->tabWidget->setCurrentWidget(frm_gameCategories);


    /* Tray Icon
    */
    m_trayIcon = new QSystemTrayIcon(QIcon(":/pandatray"));
    m_trayIcon->show();
    connect(m_trayIcon, &QSystemTrayIcon::activated, this, &Pandaqt5::slot_handleActivateTray);
}

Pandaqt5::~Pandaqt5()
{
    delete m_trayIcon;
    delete ui;
}

void Pandaqt5::changeEvent(QEvent *event)
{
    QMainWindow::changeEvent(event);

    if(event->type() == QEvent::WindowStateChange)
        if(isMinimized()&&frm_settings->isMinimizeToTray())
            this->hide();
}

void Pandaqt5::slot_categoryChanged(QString)
{
    ui->tabWidget->setCurrentWidget(frm_channels);
}

void Pandaqt5::slot_handleActivateTray(QSystemTrayIcon::ActivationReason)
{
    if(isHidden()){
        this->show();
    }else{
        if(frm_settings->isMinimizeToTray())
        {
            this->hide();
        }
    }
}

void Pandaqt5::on_m_buttonBookmarks_clicked()
{
    ui->tabWidget->setCurrentWidget(frm_bookmarks);
}

void Pandaqt5::on_m_buttonSettings_clicked()
{
    ui->tabWidget->setCurrentWidget(frm_settings);
}

void Pandaqt5::on_m_buttonChannels_clicked()
{
    ui->tabWidget->setCurrentWidget(frm_channels);
}

void Pandaqt5::on_m_buttonGameCategories_clicked()
{
    ui->tabWidget->setCurrentWidget(frm_gameCategories);
}
