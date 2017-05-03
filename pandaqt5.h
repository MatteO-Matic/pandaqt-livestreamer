#ifndef PANDAQT5_H
#define PANDAQT5_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QSystemTrayIcon>
#include <forms/FormSettings.h>
#include <forms/formgamecategories.h>
#include <forms/formbookmarks.h>
#include <forms/formchannels.h>


namespace Ui {
class Pandaqt5;
}

class Pandaqt5 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Pandaqt5(QWidget *parent = 0);
    ~Pandaqt5();
private slots:
    //sidebar buttons
    void on_m_buttonBookmarks_clicked();
    void on_m_buttonSettings_clicked();
    void on_m_buttonChannels_clicked();
    void on_m_buttonGameCategories_clicked();

    void slot_categoryChanged(QString category);
    void slot_handleActivateTray(QSystemTrayIcon::ActivationReason);

private:
    Ui::Pandaqt5 *ui;
    //forms
    FormSettings* frm_settings;
    FormGameCategories* frm_gameCategories;
    FormBookmarks* frm_bookmarks;
    FormChannels * frm_channels;

    QSystemTrayIcon *m_trayIcon;
protected:
    void changeEvent(QEvent *);
};

#endif // PANDAQT5_H
