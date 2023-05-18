#ifndef JVTIME_H
#define JVTIME_H

#include "ecs36b_Common.h"
#include "GPS.h"
#include "Thing.h"

class JvTime
{
    private:
    string time;
    string date;

    public:
    JvTime(string, string);
    JvTime();
    Json::Value dumpToJson();
    virtual bool JSON2Object(Json::Value);

};

#endif