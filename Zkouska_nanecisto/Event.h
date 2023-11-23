#pragma once

#include<iostream>
#include<list>
#include "Time.h"
#include<sstream>

using namespace std;

class Event 

{ 

private: 
string name;
Time end_time;
Time start_time; 
string place; 
string description; 

 

public: 

Event(string event); 
Event(string name, string start_time, string end_time, string place, string description); 

bool operator < (const Event& obj); 
bool operator > (const Event& obj); 
bool operator == (const Event& obj); 
bool operator != (const Event& obj); 

 
friend ostream& operator << (ostream& out, const Event& obj); 
friend class Calendar;
}; 


