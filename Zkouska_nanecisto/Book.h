#pragma once

#include<iostream>
#include<sstream>

using namespace std;

class Book{
private:

long id;
string name;
string author;
bool available;

public:

Book(string book);
void setID(long nid);
void pujceno();

bool operator < (const Book& obj);
bool operator ==(const Book& obj);

friend ostream& operator<<(std::ostream& out, const Book& obj);
friend class Library;
};