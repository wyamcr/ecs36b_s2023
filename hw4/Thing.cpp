#include "Thing.h"

Thing::Thing(string description, Person owner)
{
    this->description = description;
    this->owner = owner;
}

Thing::Thing()
{
    this->description = "";
    this->owner = Person {};
}

Json::Value Thing::dumpToJson()
{
    Json::Value result;
    result["description"] = this->description;
    result["owner"] = this->owner.getName();
    return result;
}

bool
Thing::JSON2Object(Json::Value jv)
{
    this->description = (jv["description"].asString());
    Person owner;
    owner.setName(jv["owner"].asString());
    this->owner = owner;

    return true;
}