#ifndef RECORD_H
#define RECORD_H

#include <vector>

#include "ecs36b_Common.h"
#include "main.h"


class Record
{
    private:
    vector<Person> who2;
    Person* who;
    vector<Thing> what2;
    Thing* what;
    GPS where;
    JvTime when;
    public:
    Record();
    Record(vector<Person>, vector<Thing>, GPS, JvTime);
    Record(Person*, Thing*, GPS, JvTime);

    Json::Value dumpToJson();
    virtual bool JSON2Object(Json::Value);

};

#endif