#include"Event.h"
using namespace std;


Event::Event(string name, string start_time, string end_time, string place, string description){
     this->name=name;
     this->start_time=Time(start_time);
     this->end_time=Time(end_time);
     this->place=place;
     this->description=description;
}

Event::Event(string event){
     this->name=event;
}

ostream& operator << (ostream& out, const Event& obj){
     out<<obj.name<<endl<<obj.start_time<<endl<<obj.end_time<<endl<<obj.place<<endl<<obj.description<<endl;
     return out;
}