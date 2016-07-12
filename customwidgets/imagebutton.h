#ifndef IMAGEBUTTON_H
#define IMAGEBUTTON_H
#include <QWidget>
#include <QLabel>

class ImageButton : public QLabel
{
        Q_OBJECT
public:
    ImageButton(QWidget *parent = 0);

private:
    void mousePressEvent(QMouseEvent *event);
signals:
    void leftClicked(QPoint* pos);
};

#endif // IMAGEBUTTON_H
