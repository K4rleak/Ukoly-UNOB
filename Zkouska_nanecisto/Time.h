#pragma once

#include<iostream>
#include<list>
#include<sstream>

using namespace std;

struct Time { 
int minute; 
int hour; 
int day; 
int month; 
int year; 

Time(); 

Time(string time); 

bool operator < (const Time& obj); 
bool operator > (const Time& obj); 
bool operator == (const Time& obj); 
bool operator != (const Time& obj); 

 

friend ostream& operator << (ostream& out, const Time& obj); 
}; 