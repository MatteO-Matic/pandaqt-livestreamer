#ifndef MOUSEEVENTLISTWIDGET_H
#define MOUSEEVENTLISTWIDGET_H
#include <QListWidget>
#include <QLabel>


class PandaListWidget : public QListWidget
{
    Q_OBJECT
public:
    PandaListWidget(QWidget *parent = 0);
    ~PandaListWidget();
protected:
    void verticalScrollbarValueChanged(int value) override;

private slots:
        void slot_actionTriggerThreshold(int);
private:
        QLabel* hintMessage;

signals:
     void scrollPulled();

};

#endif // MOUSEEVENTLISTWIDGET_H
