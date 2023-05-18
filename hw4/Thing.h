#ifndef THING_H
#define THING_H

#include "ecs36b_Common.h"
#include "Person.h"

class Thing
{
    private:
    string description;
    Person owner;

    public:
    Thing();
    Thing(string, Person);
    Json::Value dumpToJson();
    virtual bool JSON2Object(Json::Value);

};

#endif