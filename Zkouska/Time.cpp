#include"Time.h"
#include <iostream>


using namespace std;


ostream& operator << (ostream& out, const Time& obj){
out<<obj.year<<" "<<obj.month<<" "<<obj.day<<" "<<obj.hour<<" "<<obj.minute;
return out;
}

Time::Time(){}

Time::Time(string time){
     istringstream iss(time);
     iss >> year >> month >> day >> hour >> minute;
}

bool Time::operator < (const Time& obj){
     if (year<obj.year) return true;
     if (month<obj.month) return true;
     if (day<obj.day) return true;
     if (hour<obj.hour) return true;
     if (minute<obj.minute) return true;
     else 
     return false;
}

bool Time::operator > (const Time& obj){
     if (year>obj.year) return true;
     if (month>obj.month) return true;
     if (day>obj.day) return true;
     if (hour>obj.hour) return true;
     if (minute>obj.minute) return true;
     else 
     return false;
}

bool Time::operator == (const Time& obj){
if (year == obj.year && month==obj.month && day == obj.day && hour == obj.hour && minute == obj.minute ) return true;
else return false;
}

bool Time::operator != (const Time& obj){
if (year == obj.year && month==obj.month && day == obj.day && hour == obj.hour && minute == obj.minute ) return false;
else return true;
}