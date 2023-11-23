#pragma once

#include<iostream>
#include<list>
#include<sstream>
#include <fstream>
#include"Event.h"

using namespace std;

class Calendar 

{ 

private: 

string name; 
string path; 

list<Event> events; 

 

public: 

Calendar(string name); 
Calendar(string name, string path); 
void addEvent(Event event); 
Calendar findEvent(string name); 
Calendar findEventsAfter(Time time); 
Calendar findEventsBefore(Time time); 

friend ostream& operator << (ostream& out, const Calendar& obj); 
};