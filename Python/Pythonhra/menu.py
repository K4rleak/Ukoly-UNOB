import pygame
import random
import math
from var import Sloup,screen,width,player,background,Sloup1,Sloup2,black,delka_cary,ypata,angle,clock

def menu():
    print("aaa")
    pygame.time.delay(5000)
    return
def zacatek():
    Sloup1.position.topleft=(0,screen.get_height()-Sloup1.surface.get_height())
    Sloup2.position.topleft=(Sloup1.surface.get_width()+random.randint(30,width-Sloup1.surface.get_width()-Sloup2.surface.get_width()),screen.get_height()-150)
    Sloup2.final=Sloup2.surface.get_rect(topleft=(0,screen.get_height()-150))
    screen.blit(background, (0, 0))
    screen.blit(player, (Sloup1.surface.get_width()/2-player.get_width()/2, screen.get_height()-150-player.get_height()))
    screen.blit(Sloup1.surface, Sloup1.position)
    screen.blit(Sloup2.surface,Sloup2.position)
    global ypata 
    ypata=screen.get_height()-150
    pygame.display.update()
    return

def kresleni():
        global delka_cary,ypata,clock
        pygame.draw.rect(screen, black, (Sloup1.position.topright[0]-2,ypata-2, 2, 2))
        ypata-=2
        delka_cary+=2
        return

def rotace():
    global delka_cary,ypata,angle,clock
    #if angle<6.2831:
    screen.blit(background, (Sloup1.position.topright[0]-2, Sloup1.position.topright[1]-delka_cary-2, delka_cary, delka_cary), (Sloup1.position.topright[0]-2, Sloup1.position.topright[1]-delka_cary-2, delka_cary, delka_cary))
    pygame.draw.line(screen,black,(Sloup1.position.topright[0]-2, Sloup1.position.topright[1]-2),(Sloup1.position.topright[0]-2 + int(delka_cary * math.cos(angle)),Sloup1.position.topright[1]-2 + int(delka_cary * math.sin(angle)),),2,)
    pygame.display.flip()
    angle += 0.03
    return
    if angle>=6.2831:
        screen.blit(background, (Sloup1.position.topright[0]-2, Sloup1.position.topright[1]-delka_cary-2, delka_cary, delka_cary), (Sloup1.position.topright[0]-2, Sloup1.position.topright[1]-delka_cary-2, delka_cary, delka_cary))
        pygame.draw.rect(screen, black, (Sloup1.position.topright[0]-2,Sloup1.position.topright[1]-2, delka_cary, 2))
        angle=4.712
        delka_cary=0
        return
    return

    
    
    #running=True