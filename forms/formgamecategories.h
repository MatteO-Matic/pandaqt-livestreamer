#ifndef FORMGAMECATEGORIES_H
#define FORMGAMECATEGORIES_H

#include <QWidget>
#include <QNetworkAccessManager>
#include "customwidgets/pandatvgamecategorythumbnail.h"

namespace Ui {
class FormGameCategories;
}

class FormGameCategories : public QWidget
{
    Q_OBJECT

public:
    explicit FormGameCategories(QWidget *parent = 0);
    ~FormGameCategories();

    void RequestGameCategories();
private slots:
    void slot_finishedGameCategories();
    void slot_handleClicked(QListWidgetItem *widget);
private:

    QList<pandatvGameCategoryThumbnail*> m_listGameCategorythumbnail;
    Ui::FormGameCategories *ui;
    QNetworkReply *m_replyGameCategories;

signals:
     void categoryChanged(QString category);
};

#endif // FORMGAMECATEGORIES_H
