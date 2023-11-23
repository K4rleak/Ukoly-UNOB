#include <iostream>
using namespace std;


class Shape{
public:
Shape();
};

Shape::Shape(){
cout<<"Vykresluji obrazec"<<endl;
}

class Square:public Shape{
private:
int a;
public:
int Getstrana();
void Tisk();
Square();
Square(int a);
int obsah();
};

class Rectangle:public Square{
private:
int b;
public:
Rectangle();
Rectangle(int a, int b);
int obsah();
void Tisk();
};

class Cube:public Square{
public:
Cube();
Cube(int a);
double volume();
};






int main(){
Cube cb(5);
cout<<cb.volume()<<endl;

cb.Tisk();
return 0;
}

Square::Square():Shape(){
cout<<"Vytvarime ctverec"<<endl;
}

Square::Square(int a){
this->a=a;
cout<<"Vytvarime ctverec"<<endl;
}

Rectangle::Rectangle(){
cout<<"Vytvarime obdelnik"<<endl;
}

Rectangle::Rectangle(int a, int b):Square(a){
this->b=b;
cout<<"Vytvarime obdelnik"<<endl;
}

int Square::obsah(){
return a*a;
}

int Square::Getstrana(){
return a;
}

void Square::Tisk(){
cout<<"Ctverec ma stranu a:"<<a<<endl;
}

void Rectangle::Tisk(){
cout<<"Obdelnik ma stranu a:"<<Getstrana()<<" a stranu b:"<<b<<endl;
}

int Rectangle::obsah(){
return Getstrana()*b;
}

Cube::Cube(){cout<<"Vytvarime kostku"<<endl;}

Cube::Cube(int a):Square(a){
cout<<"Vytvarime kostku"<<endl;
}

double Cube::volume(){
return obsah()*Getstrana();
}