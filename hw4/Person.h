#ifndef PERSON_H
#define PERSON_H

#include "ecs36b_Common.h"
#include "GPS.h"

class Person
{
    private:
    string name;
    string job;
    GPS location;

    public:
    Person(string, string, GPS);
    Person();
    string getName();
    void setName(string);
    Json::Value dumpToJson();
    virtual bool JSON2Object(Json::Value);

};

#endif