#ifndef FRM_SETTINGS_H
#define FRM_SETTINGS_H

#include <QWidget>

namespace Ui {
class FormSettings;
}

class FormSettings : public QWidget
{
    Q_OBJECT

public:
    explicit FormSettings(QWidget *parent = 0);
    ~FormSettings();
    bool isMinimizeToTray();
    QList<QString> getBookmarkList();
    void addBookmark(QString bookmarkUrl);
    void removeBookmark(QString bookmarkUrl);
    QString getFullCommand();
private:
    QList<QString> m_listBookmarks;
    Ui::FormSettings *ui;
    bool m_bMinimizeToTray;
    QString m_fullcommand;
    void loadSettings();

   private slots:
    void slot_checkboxMinimizeToTray_toggled(bool);
    void on_m_textboxFullLivestreamerCommand_textChanged();
    void on_m_buttonAddBookmark_clicked();
};

#endif // FRM_SETTINGS_H
