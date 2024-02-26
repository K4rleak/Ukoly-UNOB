import sys, pygame
import random
import math
pygame.init()

size = width, height = 720,540
screen = pygame.display.set_mode(size)
clock = pygame.time.Clock()            #get a pygame clock object
black=0,0,0
red=255,0,0
brown=139,69,19
jedeme=False
rotating=False
posun=False
speed=15
namiste1=False
namiste2=False
kresleni = False
y=0
angle=4.712
delay=0
delka_cary=0

class Sloup:
  def __init__(self):
      self.surface=pygame.Surface((random.randint(50,90), 150))
      self.surface.fill(black)
      fill_rect = pygame.Rect(self.surface.get_width()/2-5, 0, 10, 10)
      self.surface.fill(red,fill_rect)
      self.position=self.surface.get_rect(topleft=(screen.get_width(),screen.get_height() - self.surface.get_height()))
      self.final=self.surface.get_rect(topleft=(0,screen.get_height() - self.surface.get_height()))

background = pygame.image.load("ledovy.jpg")

Sloup1=Sloup()
Sloup2=Sloup()
player=pygame.image.load("sprite_0.png")
Sloup1.position.topleft=(0,screen.get_height()-Sloup1.surface.get_height())
Sloup2.position.topleft=(Sloup1.surface.get_width()+random.randint(30,width-Sloup1.surface.get_width()-Sloup2.surface.get_width()),screen.get_height()-150)
Sloup2.final=Sloup2.surface.get_rect(topleft=(0,screen.get_height()-150))
screen.blit(background, (0, 0))
screen.blit(player, (0, screen.get_height()-150-player.get_height()))
screen.blit(Sloup1.surface, Sloup1.position)
screen.blit(Sloup2.surface,Sloup2.position)
y=Sloup1.position.topright[1]

tick_counter=0


pygame.display.update()
while True:
    # for event in pygame.event.get():
    #      if event.type == pygame.QUIT: sys.exit()
    #      if event.type == pygame.KEYDOWN:
    #         if event.key == pygame.K_LEFT:
    #             posun=True
    #         if event.key == pygame.K_LEFT:
    #             pass
    #         elif event.type == pygame.KEYDOWN:
    #             if event.key == pygame.K_SPACE:
    #                 posun=True

    #         elif event.type == pygame.KEYUP:
    #             if event.key == pygame.K_SPACE:
    #                 posun=False

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_LEFT:
                posun = True
            elif event.key == pygame.K_SPACE:
                kresleni = True

        elif event.type == pygame.KEYUP:
            if event.key == pygame.K_SPACE:
                kresleni = False
                rotating=True

    if posun==True:
        screen.blit(background, Sloup1.position,Sloup1.position)
        Sloup1.position.x-=speed
        screen.blit(Sloup1.surface,Sloup1.position)
        screen.blit(background, Sloup2.position,Sloup2.position)
        Sloup2.position.x-=speed
        screen.blit(Sloup2.surface,Sloup2.position)

    if Sloup2.position.x<=0:
        Sloup2.position.x=0
        screen.blit(Sloup2.surface,Sloup2.position)
        posun=False
        Sloup1=Sloup2
        Sloup2=Sloup()
        Sloup2.final=Sloup2.surface.get_rect(topleft=(random.randint(Sloup1.surface.get_width()+10,width-Sloup2.surface.get_width()),screen.get_height() - Sloup2.surface.get_height()))
        jedeme=True
        y=Sloup1.position.topright[1]

    if jedeme==True:
        screen.blit(background, Sloup2.position,Sloup2.position)
        Sloup2.position.x-=speed
        screen.blit(Sloup2.surface,Sloup2.position)

    if kresleni==True:
        pygame.draw.rect(screen, black, (Sloup1.position.topright[0]-2,y-2, 2, 2))
        y-=2
        delka_cary+=2
        

    if rotating==True:
        screen.blit(background, (Sloup1.position.topright[0]-2, Sloup1.position.topright[1]-delka_cary-2, delka_cary, delka_cary), (Sloup1.position.topright[0]-2, Sloup1.position.topright[1]-delka_cary-2, delka_cary, delka_cary))
        rot_line=pygame.draw.line(screen,black,(Sloup1.position.topright[0]-2, Sloup1.position.topright[1]-2),(Sloup1.position.topright[0]-2 + int(delka_cary * math.cos(angle)),Sloup1.position.topright[1]-2 + int(delka_cary * math.sin(angle)),),2,)
        angle += 0.03
        if angle>=6.2831:
            screen.blit(background, (Sloup1.position.topright[0]-2, Sloup1.position.topright[1]-delka_cary-2, delka_cary, delka_cary), (Sloup1.position.topright[0]-2, Sloup1.position.topright[1]-delka_cary-2, delka_cary, delka_cary))
            pygame.draw.rect(screen, black, (Sloup1.position.topright[0]-2,Sloup1.position.topright[1]-2, delka_cary, 2))
            rotating=False

    if Sloup2.position<=Sloup2.final:
        jedeme=False


    pygame.display.update()
    clock.tick(60)



