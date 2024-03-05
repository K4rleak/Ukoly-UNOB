import sys, pygame
import random
from motion import rotace,zacatek,kresleni,running,posun,jedeme,game_over,score,smrt
from var import screen,width,height,clock,speed,angle,delay,delka_cary,ypata,restart_button,hamster_song,music
pygame.init()
pygame.mixer.init()

is_rotating=False
is_drawing=False
is_running=False
is_moving=False
is_running=False
is_adding=False
dosahuje=True
pohyb=False
umrel=False


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
        elif event.type == pygame.MOUSEBUTTONDOWN:
            if restart_button.is_clicked(pygame.mouse.get_pos()):
                hamster_song.stop()
                umrel=False
                zacatek()
 
    

    if is_drawing==True and pohyb==False:
        dosahuje=True
        if kresleni()==True:
            is_drawing = False
            if pohyb==False:
                is_rotating=True
            pohyb=True



    if is_rotating==True:
        if rotace()==False:
            is_rotating=False
            is_running=True

    if is_running==True:
        hotovo,dosahuje = running()
        if hotovo==True:
            if dosahuje==True:
                is_running=False
                is_moving=True
            elif dosahuje==False:
                smrt()
                is_running=False
                pohyb=False
                umrel=True
                music.stop()
                game_over()


    if is_moving==True:
        if posun()==False:
            is_moving=False
            is_adding=True

    if is_adding==True:
       if jedeme()==False:
           is_adding=False
           pohyb=False
    
    if umrel==False and not pygame.mixer.music.get_busy():
        music.set_volume(0.1)
        music.play()


    if dosahuje:
        score()
    pygame.display.flip()
    clock.tick(60)