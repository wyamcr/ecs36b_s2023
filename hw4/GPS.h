#ifndef GPS_H
#define GPS_H

#include "ecs36b_Common.h"

class GPS
{
    private:
    double latitude;
    double longitude;

    public:
    GPS();
    GPS(double, double);
    Json::Value dumpToJson();
    virtual bool JSON2Object(Json::Value);

};

#endif