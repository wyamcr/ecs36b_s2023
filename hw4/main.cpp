#include "main.h"

int main() {
    GPS EversonHall(38.53802829630099, -121.7499866883415);
    Person Felix("Felix Wu", "Instructor", EversonHall);
    Thing device("An android device", Felix);
    Person John("John", "student", EversonHall);
    Thing computer("John's computer", John);
    JvTime time1("6:00pm", "Wednesday, April 12 of 2023");

    vector<Person> people;
    people.push_back(Felix);
    people.push_back(John);

    vector<Thing> things;
    things.push_back(device);
    things.push_back(computer);

    // Record 1 here
    Record Record1(people, things, EversonHall, time1);
    Json::Value one;
    one = Record1.dumpToJson();

    GPS SiloStation(38.53918767948964, -121.75320086876525);
    Person Tiffany("Tiffany", "Bus Driver", SiloStation);
    Thing bus("Unitrans L Line", Tiffany);
    JvTime time2("6:10pm", "Wednesday, April 12 of 2023");

    // Record 2 here
    people.insert(people.begin(), Tiffany);
    things.insert(things.begin(), bus);

    Record Record2(people, things, SiloStation, time2);
    Json::Value two;
    two = Record2.dumpToJson();

    // Record 3 here
    people.pop_back();
    things.pop_back();
    GPS eighthAndJStreet(38.551910328208784, -121.73897915252932);
    JvTime time3("6:20pm", "Wednesday, April 12 of 2023");
    Record Record3(people, things, eighthAndJStreet, time3);
    Json::Value three;
    three = Record3.dumpToJson();

    // Record 4 here
    people.pop_back();
    things.pop_back();
    GPS MooreAndPollock(38.563502968200844, -121.7182795266138);
    JvTime time4("6:32pm", "Wednesday, April 12 of 2023");
    Record Record4(people, things, MooreAndPollock, time4);
    Json::Value four;
    four = Record4.dumpToJson();

    //convert the records to JSON styled string files
    myJSON2File("file1", &one);
    myJSON2File("file2", &two);
    myJSON2File("file3", &three);
    myJSON2File("file4", &four);

    //parse those files back to JSON values
    Json::Value oneV2, twoV2, threeV2, fourV2;
    myParseJSON(myFile2String("file1"), &oneV2);
    myParseJSON(myFile2String("file2"), &twoV2);
    myParseJSON(myFile2String("file3"), &threeV2);
    myParseJSON(myFile2String("file4"), &fourV2);

    //create new Record objects from the V2 values
    Record Record1V2, Record2V2, Record3V2, Record4V2;
    Record1V2.JSON2Object(oneV2);
    Record2V2.JSON2Object(twoV2);
    Record3V2.JSON2Object(threeV2);
    Record4V2.JSON2Object(fourV2);

    //second dumpToJSON to check
    Record1V2.dumpToJson();
    Record2V2.dumpToJson();
    Record3V2.dumpToJson();
    Record4V2.dumpToJson();



}
