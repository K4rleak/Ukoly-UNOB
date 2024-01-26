import sys, pygame
import random
pygame.init()

size = width, height = 720,540
screen = pygame.display.set_mode(size)
clock = pygame.time.Clock()            #get a pygame clock object
black=0,0,0
red=255,0,0
jedeme=False

class Sloup:
  def __init__(self):
      self.surface=pygame.Surface((random.randint(50,170), 150))
      self.surface.fill(black)
      fill_rect = pygame.Rect(self.surface.get_width()/2-10, 0, 10, 10)
      self.surface.fill(red,fill_rect)
      self.position=self.surface.get_rect(topleft=(screen.get_width(),screen.get_height() - self.surface.get_height()))

background = pygame.image.load("ledovy.jpg")

Sloup1=Sloup()
Sloup2=Sloup()
player=pygame.image.load("sprite_0.png")
Sloup1.position.topleft=(0,screen.get_height()-Sloup1.surface.get_height())
Sloup2.position.topleft=()
screen.blit(background, (0, 0))
screen.blit(player, (0, screen.get_height()-150-player.get_height()))
screen.blit(Sloup1.surface, Sloup1.position)
screen.blit(Sloup2,)

tick_counter=0



#screen.blit(Ostrov1.image, Ostrov1.position)        
pygame.display.update()                
while True:                
    for event in pygame.event.get():
         if event.type == pygame.QUIT: sys.exit()
         if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_LEFT:
                jedeme=True
    
    if jedeme==True:
        screen.blit(background, Sloup1.position.topleft,
                    Sloup1.position)
        Sloup1.position.x-=10
        screen.blit(Sloup1.surface,Sloup1.position)
        jedeme=False

        if Sloup1.position.x <= -Sloup1.surface.get_width():
            Sloup1 = Sloup()

    pygame.display.update()
    clock.tick(200)      



