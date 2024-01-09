import os
from os.path import join, realpath, dirname

#text=input("Zadej text: ")
text="ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789"

klic={}
with open(join(dirname(realpath(__file__)), "zadani.txt"), "r", encoding="utf-8") as file:
    while True: 
        radek=file.readline()
        if not radek:
            break
        radek = radek[:-1]
        klic[radek[0]] = radek[2:]

prelozeno=""
for char in text.upper():
    print(klic[char]+" ", end='')
    #prelozeno+=klic[char]
#print("Překlad: " + prelozeno)


        
