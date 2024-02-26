import sys, pygame
import random
pygame.init()

size = width, height = 1200,540
screen = pygame.display.set_mode(size)

class Ostrov_long:
  def __init__(self, image):
      self.image=pygame.image.load(image)
      self.position=self.image.get_rect()
      self.position.bottomleft=(screen.get_width(), screen.get_height())

class Ostrov_short:
  def __init__(self, image):
      self.full=pygame.image.load(image)
      random_width = random.randint(50, 100)
      self.image=self.full.subsurface(pygame.Rect(self.full.get_width() - random_width, 0, random_width, self.full.get_height()))
      self.position=self.image.get_rect()
      self.position.bottomleft=(screen.get_width(), screen.get_height())



Ostrov1=Ostrov_long("stone.png")
Ostrov2=Ostrov_long("stone.png")
Ostrov2.position.bottomleft=(0, screen.get_height())
Ostrov3=Ostrov_long("stone.png")
Ostrov3.position.bottomleft=(Ostrov2.position.width, screen.get_height())
Ostrov4=Ostrov_long("stone.png")
Ostrov4.position.bottomleft=(Ostrov3.position.width+Ostrov3.position.width, screen.get_height())
Ostrov5=Ostrov_long("stone.png")
Ostrov5.position.bottomleft=(Ostrov3.position.width+Ostrov3.position.width+Ostrov3.position.width, screen.get_height())



clock = pygame.time.Clock()            #get a pygame clock object
player = pygame.image.load("long.png")
background = pygame.image.load("ledovy.jpg")
screen.blit(background, (0, 0))        #draw the background
tick_counter=0
dira=False
Mosty=[]
Ostrovy=[]
Ostrovy.append(Ostrov1)
Ostrovy.append(Ostrov2)
Ostrovy.append(Ostrov3)
Ostrovy.append(Ostrov4)
Ostrovy.append(Ostrov5)



screen.blit(Ostrov1.image, Ostrov1.position)        
pygame.display.update()                
while True:                
    for event in pygame.event.get():
         if event.type == pygame.QUIT: sys.exit()
    
    screen.blit(background, (0, 0))
    for Ostrov in Ostrovy:
            Ostrov.position = Ostrov.position.move(-2, 0)     
            screen.blit(Ostrov.image, Ostrov.position)
        
    Ostrovy = [Ostrov for Ostrov in Ostrovy if Ostrov.position.right > 0]

    for Most in Mosty:
            Most.position = Most.position.move(-2, 0)     
            screen.blit(Most.image, Most.position,)
        
    Mosty = [Most for Most in Mosty if Most.position.right > 0]
    
    tick_counter+=1
    if tick_counter==Ostrov1.position.width/2:
        if random.randint(1, 3) == 1 and dira==False:
            new_short=Ostrov_short("stone.png")
            new_short.position.x += Ostrov1.position.width -new_short.position.width -10
            Mosty.append(new_short)
            tick_counter=0
            dira=True
        else:
            new_ostrov=Ostrov_long("green.png")
            Ostrovy.append(new_ostrov)
            tick_counter=0
            dira=False
         

    
    pygame.display.update()
    clock.tick(200)      



