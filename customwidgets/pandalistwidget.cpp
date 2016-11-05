#include "pandalistwidget.h"
#include <QMouseEvent>
#include <QDebug>
#include <QScrollBar>

PandaListWidget::PandaListWidget(QWidget *parent) :
    QListWidget(parent)
{
    connect(verticalScrollBar(), SIGNAL(actionTriggered(int)), this, SLOT(slot_actionTriggerThreshold(int)));
    //hintMessage = new QLabel("Keep scrolling for update", this);

}

PandaListWidget::~PandaListWidget()
{

}

pandatvChannelThumbnail *PandaListWidget::itemAt(const QPoint &p) const
{
    return (pandatvChannelThumbnail*)QListWidget::itemAt(p);
}

//This should later have a threshold by checking the actiontrigger if user keeps scrolling over max
void PandaListWidget::verticalScrollbarValueChanged(int value)
{
    QListWidget::verticalScrollbarValueChanged(value);

    if(verticalScrollBar()->maximum()==value)
    {
      //  hintMessage->show();
        emit scrollPulled();
    }
}

void PandaListWidget::slot_actionTriggerThreshold(int)
{
    //qDebug() << i;
}

