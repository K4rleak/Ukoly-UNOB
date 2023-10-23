#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

struct Otazka{
string otazka;
string a,b,c;
char spravna;
};

int main ()
{
    fstream myfile;
    string line,path;
    vector<Otazka> radky;
    int skore;
    //cout<<"Zadej cestu:"; cin >> path;
     myfile.open("questions.txt",ios::in);
    if (myfile.is_open()) {
    string radek;
    while(getline(myfile,radek)){
        Otazka otazka;
        stringstream ss(radek); 
            getline(ss, otazka.otazka, ';');
            getline(ss, otazka.a, ';');
            getline(ss, otazka.b, ';');
            getline(ss, otazka.c, ';');
            ss>>otazka.spravna;
            radky.push_back(otazka);
    }
        myfile.close(); 
 }
for(int i = 0; i<radky.size();i++)
{
   char spr;
   cout<<radky[i].otazka<<endl;
   cout<<"a) "<<radky[i].a<<endl<<"b) "<<radky[i].b<<endl<<"c) "<<radky[i].c<<endl;
   cin>>spr;
   if(spr==radky[i].spravna){
    cout<<"spravne\n";
    skore+=1;
   }
    else 
    cout<<"spatne\n";
}
cout<<"skore: "<<skore;
}
