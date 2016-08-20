#ifndef FORMBOOKMARKS_H
#define FORMBOOKMARKS_H

#include <QWidget>

namespace Ui {
class FormBookmarks;
}

class FormBookmarks : public QWidget
{
    Q_OBJECT

public:
    explicit FormBookmarks(QWidget *parent = 0);
    ~FormBookmarks();

private:
    Ui::FormBookmarks *ui;
};

#endif // FORMBOOKMARKS_H
