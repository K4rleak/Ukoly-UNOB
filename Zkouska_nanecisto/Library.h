#pragma once

#include<iostream>
#include<list>
#include <vector>
#include <fstream>
#include "Book.h"

using namespace std;

class Library{
private:

string path;
list <Book> books;
list <Book> getavailableBooks();

public:
Library(string path_to_file);
void addBook(Book book);
long getUniqueId();
void showAvailableBooks();
void findBookAndBorrowIt(string name);  
/*void showAvailableBooks();
void findBookAndBorrowIt(string name);
~Library();*/

friend ostream& operator<< (ostream& out, const Library& obj);
};