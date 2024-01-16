class Book:
    def __init__(self,book):
        self.info = book.split(';')
        self.id=self.info[0]
        self.name=self.info[1]
        self.author=self.info[2]
        self.available=self.info[3]
    def __repr__(self): 
        return f"{self.id};{self.name};{self.author};{self.available}"
