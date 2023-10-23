#include <iostream>
#include <string>
#include <fstream>
#include <vector>


using namespace std;

int main ()
{
    fstream myfile;
    myfile.open("aoc.txt",ios::in);
    if (myfile.is_open()) {
    string cislo;
    vector<int> seznam;
    while(getline(myfile,cislo))
        seznam.push_back(stoi(cislo));
    myfile.close();
    for(int i=0; i<seznam.size(); i++){   
    for(int o=i+1;o<seznam.size();o++){
        for (int p=i+2;p<seznam.size();p++)
        if(seznam[i]+seznam[o]+seznam[p]==2020){
        cout<<seznam[i]*seznam[o]*seznam[p]<<endl;
        return 0;}
    }
    }
    }
    else
    cout<<"Couldn't open file";    
}