#include"Calendar.h"

using namespace std;

Calendar::Calendar(string name){
    this->name=name;
}
Calendar::Calendar(string name, string path){
    this->name=name;
    this->path=path;

    fstream myfile;
    string rad;
    myfile.open(path,ios::in);
    while(getline(myfile,rad)){
        Event e = Event(rad);
        getline(myfile,rad);
        getline(myfile,rad);
        e.start_time=rad;
        getline(myfile,rad);
        getline(myfile,rad);
        e.end_time=rad;
        getline(myfile,rad);
        getline(myfile,rad);
        e.place=rad;
        getline(myfile,rad);
        getline(myfile,rad);
        e.description=rad;
        getline(myfile,rad);
        getline(myfile,rad);
        getline(myfile,rad);
        events.push_back(e);
    }
  myfile.close();
}

void Calendar::addEvent(Event event){
    events.push_back(event);
}

ostream& operator << (ostream& out, const Calendar& obj){
        if(obj.events.empty())
        out<<"No events";
        else{
        for (Event i : obj.events)
        out<<i;
        }
        return out;
}

Calendar Calendar::findEvent(string name){
    Calendar N=Calendar("E:"+name);
    for (Event i : events)
    if(i.name==name)
    N.addEvent(i);
    return N;

}

Calendar Calendar::findEventsAfter(Time time){
    Calendar N=Calendar("After");
    for (Event i : events)
    if (i.start_time>time)
    N.addEvent(i);
    return N;
    
}

Calendar Calendar::findEventsBefore(Time time){
    Calendar N=Calendar("After");
    for (Event i : events)
    if (i.end_time<time)
    N.addEvent(i);
    return N;
    
}