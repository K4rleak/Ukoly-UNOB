import sys, pygame
import random
from motion import rotace,zacatek,kresleni,running,posun,jedeme
from var import screen,width,height,clock,speed,angle,delay,delka_cary,ypata
pygame.init()

is_rotating=False
is_drawing=False
is_running=False
is_moving=False
is_running=False
is_adding=False
pohyb=False


zacatek()


while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_UP:
                is_drawing = True
        elif event.type == pygame.KEYUP:
            if event.key == pygame.K_UP:
                is_drawing = False
                if pohyb==False:
                    is_rotating=True
                pohyb=True
 

    if is_drawing==True and pohyb==False:
        kresleni()


    if is_rotating==True:
        if rotace()==False:
            is_rotating=False
            is_running=True

    if is_running==True:
        if running()==False:
            is_running=False
            is_moving=True

    if is_moving==True:
        if posun()==False:
            is_moving=False
            is_adding=True

    if is_adding==True:
       if jedeme()==False:
           is_adding=False
           pohyb=False




    pygame.display.flip()
    clock.tick(60)