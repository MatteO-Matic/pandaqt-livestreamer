#ifndef PANDATVCHANNEL_H
#define PANDATVCHANNEL_H
#include <QJsonObject>

class pandatvChannel
{
public:
    pandatvChannel() {}
    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;
    QString name;
};
#endif // PANDATVCHANNEL_H
