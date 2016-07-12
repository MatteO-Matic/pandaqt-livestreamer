#include "imagebutton.h"
#include <QMouseEvent>

ImageButton::ImageButton(QWidget *parent) :
    QLabel(parent)
{

}

void ImageButton::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        QPoint* p = new QPoint(event->pos());
        emit leftClicked(p);
    } else {
        QLabel::mousePressEvent(event);
    }
}
