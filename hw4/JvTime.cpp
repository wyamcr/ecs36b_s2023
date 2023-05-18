#include "JvTime.h"
#include "string.h"

JvTime::JvTime(string time, string date)
{
    this->time = time;
    this->date = date;
}

JvTime::JvTime()
{
    this->time = "";
    this->date = "";
}

Json::Value JvTime::dumpToJson()
{
    Json::Value result;
    result["time"] = this->time;
    result["date"] = this->date;
    return result;
}

bool
JvTime::JSON2Object(Json::Value jv)
{
    this->time = (jv["time"].asString());
    this->date = (jv["date"].asString());
    return true;
}