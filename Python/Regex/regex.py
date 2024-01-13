import re
import os
from os.path import join, realpath, dirname

vety=[]
with open(join(dirname(realpath(__file__)), "othello.txt"), "r", encoding="utf-8") as file:
    string=file.read().replace("\n","")
    vety=re.findall("[A-Z]+[^.!?]*[.!?]",string)