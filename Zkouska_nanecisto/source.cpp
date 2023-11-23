#include<iostream>
#include<list>
#include"Time.h"
#include"Event.h"
#include"Calendar.h"


using namespace std;

int main() 

{ 

    Time t = Time("2023 1 10 20 53"); 
    cout<< t << endl; 
 

   Event e = Event("Presentation","2023 2 2 14 00","2023 2 2 16 15","S9A/67","Information technology presentation.Complete projects and tasks"); 
   Calendar c = Calendar("TEST", "events.txt"); 
   cout << c << endl; 

    c.addEvent(e); 

    Event e1 = Event("Launch", "2023 3 2 12 00", "2023 3 2 13 00", "Canteen", " Enjoy your meal."); 

    c.addEvent(e1); 
    cout << c << endl; 

    cout << c.findEvent("Exam") << endl; 

    cout << c.findEventsAfter(Time("2023 3 2 15 40")) << endl; 
    
    cout << c.findEventsBefore(Time("2023 3 2 8 00")) << endl; 

}