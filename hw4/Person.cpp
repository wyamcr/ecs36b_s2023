#include "Person.h"

Person::Person(string name, string job, GPS location)
{
    this->name = name;
    this->job = job;
    this->location = location;
}

Person::Person()
{
    this->name = "";
    this->job = "";
    this->location = GPS {};
}

string Person::getName()
{
    return name;
}

void Person::setName(string name)
{
    this->name = name;
}

Json::Value Person::dumpToJson()
{
    Json::Value result;
    result["name"] = this->name;
    result["job"] = this->job;
    result["location"] = this->location.dumpToJson();
    return result;
}

bool
Person::JSON2Object(Json::Value jv)
{
    this->name = (jv["name"].asString());
    this->job = (jv["job"].asString());
    GPS location;
    location.JSON2Object(jv["location"]);
    this->location = location;
    return true;
}