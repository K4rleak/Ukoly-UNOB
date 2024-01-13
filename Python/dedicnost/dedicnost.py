import math
class Shape:
  def __init__(self):
    print("Vykresluji obrazec")

class Circle(Shape):
  def __init__(self,polomer):
    Shape.__init__(self)
    self.r=polomer
  def Obsah(self):
    return self.r**2*math.pi
  def Obvod(self):
    return self.r*2*math.pi
  
class Sphere(Circle):
  def __init__(self,polomer):
    Circle.__init__(self,polomer)
  def Objem(self):
    return 3/4*math.pi*self.r**3
  def Obvod(self):
    return self.r*2*math.pi
  
class Cylinder(Circle):
  def __init__(self,polomer,vyska):
    Circle.__init__(self,polomer)
    self.t=vyska
  def Objem(self):
    return self.r**2*math.pi*self.t
  def Obvod(self):
    return self.r*2*math.pi

class Square(Shape):
  def __init__(self,strana):
    Shape.__init__(self)
    self.a=strana
  def Getstrana(self):
    print(self.a)
  def Obsah(self):
    return self.a*self.a
  def Obvod(self):
    return self.a*4
  
class Rectangle(Square):
  def __init__(self, strana , strana_b):
    super().__init__(strana)
    self.b=strana_b
  def Obsah(self):
    return self.a*self.b
  def Obvod(self):
    return 2*(self.a+self.b)
    
class Cube(Square):
  def __init__(self,strana):
    Square.__init__(self,strana)
  def Objem(self):
    return self.a**3
  def Obvod(self):
    return self.a*12
  
class Cuboid(Rectangle):
  def __init__(self,strana, strana_b,strana_c):
     Rectangle.__init__(self,strana,strana_b)
     self.c=strana_c
  def Objem(self):
    return self.a*self.b*self.c
  def Obvod(self):
    return 4*(self.a+self.b+self.c)
  


Kruh = Circle(2)
Koule = Sphere(3)
Valec = Cylinder(3, 5)
Ctverec = Square(4)
Obdelnik = Rectangle(3, 4)
Krychle = Cube(2)
Kvadr = Cuboid(2, 3, 5)

print("Obsah kruhu je: " + str(Kruh.Obsah()))
print("Obvod kruhu je: " + str(Kruh.Obvod()))

print("Objem koule je: " + str(Koule.Objem()))
print("Obvod koule je: " + str(Koule.Obvod()))

print("Objem válce je: " + str(Valec.Objem()))
print("Obvod válce je: " + str(Valec.Obvod()))

print("Obsah čtverce je: " + str(Ctverec.Obsah()))
print("Obvod čtverce je: " + str(Ctverec.Obvod()))

print("Obsah obdélníku je: " + str(Obdelnik.Obsah()))
print("Obvod obdélníku je: " + str(Obdelnik.Obvod()))

print("Objem krychle je: " + str(Krychle.Objem()))
print("Obvod krychle je: " + str(Krychle.Obvod()))

print("Objem kvádru je: " + str(Kvadr.Objem()))
print("Obvod kvádru je: " + str(Kvadr.Obvod()))

