#include "pandatvchannel.h"

void pandatvChannel::read(const QJsonObject &json)
{
    name = json["name"].toString();

    //mLevel = json["level"].toDouble();
    //mClassType = ClassType(qRound(json["classType"].toDouble()));
}

void pandatvChannel::write(QJsonObject &json) const
{
    json["name"] = name;
//    json["level"] = mLevel;
//    json["classType"] = mClassType;




}
