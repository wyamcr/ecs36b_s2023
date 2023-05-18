#include "Record.h"

Record::Record()
{

}

Record::Record(Person* people, Thing* things, GPS where, JvTime when)
{
    this->who = people;
    this->what = things;
    this->where = where;
    this->when = when;
}

Record::Record(vector<Person> people, vector<Thing> things, GPS where, JvTime when)
{
    this->who2 = people;
    this->what2 = things;
    this->where = where;
    this->when = when;
}

Json::Value
Record::dumpToJson()
{
    Json::Value result;
    result["where"] = (this->where).dumpToJson();
    result["when"] = (this->when).dumpToJson();

    for(auto i : who2) {
        result["who"].append(i.dumpToJson());
    }
    for(auto i : what2) {
        result["what"].append(i.dumpToJson());
    }
    std::cout << result.toStyledString() << std::endl;
    return result;

}

bool
Record::JSON2Object(Json::Value jv)
{
    Person person;
    vector<Person> people;
    for(int i = 0; jv["who"].isValidIndex(i); i++)
    {
        person.JSON2Object(jv["who"][i]);
        people.push_back(person);
    }

    this->who2 = people;
    
    Thing thing;
    vector<Thing> things;
    for(int i = 0; jv["what"].isValidIndex(i); i++)
    {
        thing.JSON2Object(jv["what"][i]);
        things.push_back(thing);
    }

    this->what2 = things;
    
    GPS where;
    where.JSON2Object(jv["where"]);
    this->where = where;

    JvTime when;
    when.JSON2Object(jv["when"]);
    this->when = when;

    return true;

}