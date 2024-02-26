# import sys, pygame
# pygame.init()

# size = width, height = 1280 , 720
# speed = [2, 2]
# black = 128,0,128

# screen = pygame.display.set_mode(size)

# ball = pygame.image.load("ostrov.png")
# ballrect = ball.get_rect()

# while True:
#     for event in pygame.event.get():
#         if event.type == pygame.QUIT: sys.exit()

#     ballrect = ballrect.move(speed)
#     if ballrect.left < 0 or ballrect.right > width:
#         speed[0] = -speed[0]
#     if ballrect.top < 0 or ballrect.bottom > height:
#         speed[1] = -speed[1]

#     screen.fill(black)
#     screen.blit(ball, ballrect)
#     pygame.display.flip()


# import sys, pygame
# pygame.init()

# class Ostrov_long:
#   def __init__(self, image):
#       self.image=pygame.image.load(image)
#       self.position=self.image.get_rect()

# black = 128,0,128
# size = width, height = 1800,540
# Ostrov1=Ostrov_long("long.png")
# screen = pygame.display.set_mode(size)
# clock = pygame.time.Clock()            #get a pygame clock object
# player = pygame.image.load("long.png")
# background = pygame.image.load("ledovy.jpg")
# screen.blit(background, (0, 0))        #draw the background
# position = player.get_rect()
# position2 = player.get_rect()
# tick_counter=0
# ostrovy=[]
# # Step 2: Set the bottom-left corner of the player's rect
# position.bottomleft = (screen.get_width()-position.width, screen.get_height())
# position2.bottomleft = (screen.get_width()-position.width, screen.get_height())
# # Step 3: Blit (draw) the player onto the screen at the specified position
# screen.blit(player, position)         #draw the player
# pygame.display.update()                #and show it all
# while True:
# #for x in range(100):                   #animate 100 frames
#     for event in pygame.event.get():
#          if event.type == pygame.QUIT: sys.exit()
    
#     screen.blit(background, (0, 0)) #erase
    
#     position = position.move(-2, 0)     #move player
#     screen.blit(player, position)      #draw new player
    
#     tick_counter+=1
#     if tick_counter>=255:
#          screen.blit(player, position2)
#          pygame.display.update()
#          pygame.time.delay(3000)

    
#     pygame.display.update()            #and show it all
#     clock.tick(60)      




import sys, pygame
import random
pygame.init()

size = width, height = 1800,540
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



