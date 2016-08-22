#ifndef FORMBOOKMARKS_H
#define FORMBOOKMARKS_H

#include <QWidget>
#include <customwidgets/pandalistwidget.h>

namespace Ui {
class FormBookmarks;
}

class FormBookmarks : public QWidget
{
    Q_OBJECT

public:
    explicit FormBookmarks(QWidget *parent = 0);
    ~FormBookmarks();

private slots:
        void slot_on_buttonRefresh_Bookmarks_clicked(QPoint*);
        void slot_tickPollOfflineBookmarks();
        void slot_contextmenu_removeBookmark();
        void slot_onBookmarkContextMenu(const QPoint &pos);

private:
    Ui::FormBookmarks *ui;
    void loadBookmarksintoWidget();
    QTimer *m_timerPollOfflineBookmarks = new QTimer(this);

    PandaListWidget *m_lastRightclickedChannelWidget;
};

#endif // FORMBOOKMARKS_H
