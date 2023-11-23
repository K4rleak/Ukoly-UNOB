#include <iostream>
#include "Book.h"
#include "Library.h"
using namespace std;

int main(){
    Book book("9;Animal Farm;Orwell George;Available");
    cout<<book<<endl<<endl;

    Library library("data.txt");
    cout<<library<<endl<<endl; 

    library.addBook(book);
    cout<<endl;

    book.setID(library.getUniqueId());
    library.addBook(book);
    cout<<endl;

    cout<<"Dostupné knihy:"<<endl;
    library.showAvailableBooks();
    cout<<"Pujceni knihy:"<<endl;
    library.findBookAndBorrowIt("Kill"); 
    cout<<endl;
    library.findBookAndBorrowIt("a");
    cout<<endl;
    library.findBookAndBorrowIt("Great");
    cout<<endl;
    cout<<"Dostupné knihy:"<<endl;
    library.showAvailableBooks();
    cout<<endl;
}