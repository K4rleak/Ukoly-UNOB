#include"Book.h"
using namespace std;

Book::Book(string book){

    istringstream ss(book);
    string token1, token2, token3, token4;
    std::getline(ss, token1, ';');
    std::getline(ss, token2, ';');
    std::getline(ss, token3, ';');
    std::getline(ss, token4, ';');
    id=stol(token1);
    name=token2;
    author=token3;
    if (token4.find("Available") != string::npos)
    available=true;
    else
    available=false;
}

ostream& operator<<(std::ostream& out, const Book& obj){
        if(obj.available==true)
        out<<obj.id<<";"<<obj.name<<";"<<obj.author<<";"<<"Available";
        else
        out<<obj.id<<";"<<obj.name<<";"<<obj.author<<";"<<"Unavailable";
        return out;
}

void Book::setID(long nid){
    id=nid;
}
     
     
