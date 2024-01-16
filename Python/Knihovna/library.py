import os
from book import Book 
from os.path import join, realpath, dirname
class Library:
    def __init__(self, path_to_file):
        with open(join(dirname(realpath(__file__)), path_to_file), "r", encoding="utf-8") as file:
            self.books=[]
            for line in file.readlines():
                book=Book(line.rstrip().lstrip())
                self.books.append(book)
            self.books=sorted(self.books,key=lambda x: x.author)
    def __repr__(self):
        return '\n'.join(map(str, self.books))
    def add_book(self,book):
        if book.id not in list(map(lambda x: x.id, self.books)):
            self.books.append(book)
            self.books=sorted(self.books,key=lambda x: x.author)
        else:
            print("Id už je použito")
    def get_unique_id(self):
        i = 1  
        while str(i) in list(map(lambda x: x.id, self.books)):
            i += 1
        return i
    def show_available_books(self):
        for av in self.books:
            if av.available=="Available":
                print(av)
    def find_book_and_borrow_it(self,name):
        vysledky=[]
        for index,book in enumerate(self.books):
            if name in book.name and book.available=="Available":
                print(book)
                vysledky.append(index)
        if len(vysledky)==1:
            agree=input("Chcete si knihu pujcit (A/N): ")
            if agree=="A" or agree=="a":
                print("Kniha byla vypujcena!")
                self.books[vysledky[0]].available="Unavailable"
            else:
                print("Nic nebylo zmeneno!")
        elif len(vysledky)==0:
            print("Nebyla nalezena zadna dostupna kniha!")
                

                    

            
