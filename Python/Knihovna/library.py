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
            self.books=sorted(self.books,key=lambda x: x.id)

            # self.books=list(map(str.strip, file.readlines()))
            # print()
    # def __repr__(self):
    #     return '\n'.join(map(str,self.books))
    # def add_book(self,book):
    #     ids=[]
    #     # for x, stary in enumerate(self.books):
    #     #     ids+= stary[:stary.find(';')]
    #     for stary in self.books:
    #         if stary.id==3:
    #             print()
            # ids+= stary[:stary.find(';')]
        # if book.id not in ids:
        #     self.books.append(book)

