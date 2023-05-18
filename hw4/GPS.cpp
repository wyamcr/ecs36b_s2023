#include "GPS.h"

GPS::GPS()
{
    this->latitude = 0.0;
    this->longitude = 0.0;
}

GPS::GPS(double latitude, double longitude)
{
    this->latitude = latitude;
    this->longitude = longitude;
}

Json::Value GPS::dumpToJson()
{
    Json::Value result;
    result["latitude"] = this->latitude;
    result["longitude"] = this->longitude;
    return result;
}

bool
GPS::JSON2Object(Json::Value jv)
{
    this->latitude = (jv["latitude"].asDouble());
    this->longitude = (jv["longitude"].asDouble());
    return true;
}