import requests
import re
import os
from os.path import join, realpath, dirname

file_path = join(dirname(realpath(__file__)), "othello.txt")

resp=requests.get('https://paste.gg/p/anonymous/ef4e35f34f854aecbb67c5229dd5c459/files/2de9f941434b4603aa0dc686faf81a23/raw')

if not os.path.exists(file_path):
        with open(file_path, "x", encoding=resp.apparent_encoding) as file:
                file.write(resp.text)


# with open(join(dirname(realpath(__file__)), "othello.txt"), "r", encoding="utf-8") as file:
#         text=file.read()
#         list=text.split()
#         pocet=len(list)
#         print(pocet)
#         #vety=text.findall()