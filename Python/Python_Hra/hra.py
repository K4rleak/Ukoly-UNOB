import sys, pygame
import random
import math
from var import screen,width,height,clock,speed,angle,delay,delka_cary,ypata
import menu
pygame.init()

jedeme=False
rotating=False
posun=False
kresleni = False
running=True


menu.zacatek()


while True:
  

  for event in pygame.event.get():
    if event.type == pygame.QUIT:
        pygame.quit()
        sys.exit()

    elif event.type == pygame.KEYDOWN:
        if event.key == pygame.K_LEFT:
            posun = True
        elif event.key == pygame.K_SPACE:
            ypata=screen.get_height()-150
            kresleni = True

    elif event.type == pygame.KEYUP:
        if event.key == pygame.K_SPACE:
            kresleni = False
            rotating=True
    if kresleni==True:
        menu.kresleni()
    if rotating==True:
        menu.rotace()
        #rotating=False

    pygame.display.update()
    clock.tick(60)
#   if kresleni==True:
#       ypata=screen.get_height()-150
#       menu.kresleni()
      
      

