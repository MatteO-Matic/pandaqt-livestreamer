#include "FormSettings.h"
#include "ui_FormSettings.h"
#include <QSettings>
#include <QDebug>

#define _minimizeToTray "minimizeToTray"
#define _bookmarksList "bookmarkList"
#define _fullCommand "fullcommand"

FormSettings::FormSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormSettings)
{
    ui->setupUi(this);

    connect(ui->m_checkboxMinimizeToTray, SIGNAL(toggled(bool)), this, SLOT(slot_checkboxMinimizeToTray_toggled(bool)));

    qRegisterMetaTypeStreamOperators<QList<QString> >("QList<QString>");
    loadSettings();
}

FormSettings::~FormSettings()
{
    delete ui;
}

QSettings m_settingsApplication("matteomatic", "pandaqt");

void FormSettings::loadSettings()
{
    m_bMinimizeToTray = m_settingsApplication.value(_minimizeToTray).toBool();
    m_listBookmarks = m_settingsApplication.value(_bookmarksList).value<QList<QString>>();
    m_fullcommand = m_settingsApplication.value(_fullCommand).toString();

    if(m_fullcommand=="")
    {
        m_fullcommand = "best --no-version-check --player-passthrough=hls --player-continuous-http --hls-live-edge=3 --hls-segment-threads=3";
        m_settingsApplication.setValue(_fullCommand, m_fullcommand);
    }

    ui->m_checkboxMinimizeToTray->setChecked(m_bMinimizeToTray);
    ui->m_textboxFullLivestreamerCommand->setText(m_fullcommand);
}

void FormSettings::addBookmark(QString bookmarkUrl)
{
    if(m_listBookmarks.contains(bookmarkUrl)){
        qDebug() << bookmarkUrl << "already in the list";
        return;
    }

    if(!bookmarkUrl.startsWith("http://api.m.panda.tv/"))
    {
        qDebug() << bookmarkUrl << "Incorrect link format";
        return;
    }
    m_listBookmarks.append(bookmarkUrl);
    m_settingsApplication.setValue(_bookmarksList, QVariant::fromValue(m_listBookmarks));
}

void FormSettings::removeBookmark(QString bookmarkUrl)
{
    if(!m_listBookmarks.removeOne(bookmarkUrl))
    {
        qDebug() << bookmarkUrl << "not found in the bookmarklist";
        return;
    }
    m_settingsApplication.setValue(_bookmarksList, QVariant::fromValue(m_listBookmarks));
}

QString FormSettings::getFullCommand()
{
    //I'll save the full command here..
    m_settingsApplication.setValue(_fullCommand, m_fullcommand);
    return m_fullcommand;
}

QList<QString> FormSettings::getBookmarkList()
{
    return m_listBookmarks;
}

void FormSettings::slot_checkboxMinimizeToTray_toggled(bool checked)
{
    m_bMinimizeToTray= checked;
    m_settingsApplication.setValue(_minimizeToTray, m_bMinimizeToTray);
}

bool FormSettings::isMinimizeToTray()
{
    return m_bMinimizeToTray;
}

void FormSettings::on_m_textboxFullLivestreamerCommand_textChanged()
{
    m_fullcommand = ui->m_textboxFullLivestreamerCommand->toPlainText();
}

void FormSettings::on_m_buttonAddBookmark_clicked()
{
    QString txtStr = ui->m_textboxAddBookmark->toPlainText();
    txtStr = txtStr.split("panda.tv/")[1];

    QString str = QString("http://api.m.panda.tv/ajax_get_liveroom_baseinfo?roomid=%1&slaveflag=1&type=json&__version=1.0.1.1303&__plat=android").arg(txtStr);

    this->addBookmark(str);
    ui->m_textboxAddBookmark->clear();
}
