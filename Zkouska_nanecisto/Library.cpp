#include"Library.h"
using namespace std;

Library::Library(string path_to_file){
    path=path_to_file;
        fstream myfile;
    string rad;
    myfile.open(path,ios::in);
    while(getline(myfile,rad)){
        //size_t found = rad.find();
        //if (rad.find(';') != string::npos)
        if(rad!="")
        {
        Book book(rad);
        books.push_back(book);
        }
    }
  myfile.close();
}

ostream& operator<< (ostream& out, const Library& obj){
for (Book i : obj.books){
        out<<i;
        out<<endl;
        }
        
        return out;
}

void Library::addBook(Book book){
    for(Book i : books)
    if(i.id==book.id){
    cout<<"Kniha nemá unikátní ID";
    return;
    }
    books.push_back(book);
}



long Library::getUniqueId()
{
    long last_id = 0;
    for (Book book: books){
        if (book.id>last_id)last_id=book.id;
    }
    return last_id+1;
}

void Library::showAvailableBooks(){
for (Book i : books){
        if(i.available)
        cout<<i<<endl;
        
        }

}

void Library::findBookAndBorrowIt(string name){
vector<Book> sedi;
for (Book i : books){
    if (i.name.find(name) != string::npos && i.available){
    cout<<i<<endl;
    sedi.push_back(i);
    }
}

if(sedi.size()==1){
cout<<"Chcete knihu vypujcit? (A/N)"<<endl;
char AN;
cin>>AN;
if(AN=='A'){
for(Book &i : books){
if(sedi[0].id==i.id)
i.available=false;
}

}
else{
    cout<<"Kniha nebyla vypujcena"<<endl;
}
}

if(sedi.size()>1){
    cout<<"Vyberte cislo knihy kterou chcete vypujcit"<<endl;
long cislo;
cin>>cislo;

for(Book &i : books){
if(cislo==i.id)
i.available=false;
}

}

if(sedi.size()==0)
cout<<"Nenalezena žádná dostupná kniha s tímto jménem.";
}

