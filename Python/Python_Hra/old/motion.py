import random,pygame,math
from var import Sloup,screen,width,player,background,Sloup1,Sloup2,black,delka_cary,ypata,angle,clock,height

def zacatek():
    Sloup1.position.topleft=(0,screen.get_height()-Sloup1.surface.get_height())
    Sloup2.position.topleft=(Sloup1.surface.get_width()+random.randint(30,height-150),screen.get_height()-150)
    #Sloup2.final=Sloup2.surface.get_rect(topleft=(0,screen.get_height()-150))
    screen.blit(background, (0, 0))
    #screen.blit(player, (Sloup1.surface.get_width()/2-player.get_width()/2, screen.get_height()-150-player.get_height()))
    screen.blit(player.image,(player.x,player.y))
    screen.blit(Sloup1.surface, Sloup1.position)
    screen.blit(Sloup2.surface,Sloup2.position)
    pygame.display.update()
    return

def kresleni():
        global delka_cary,ypata,clock
        pygame.draw.rect(screen, black, (Sloup1.position.topright[0]-2,ypata-2, 2, 2))
        ypata-=2
        delka_cary+=2
        return

def rotace():
    global delka_cary,angle,ypata
    spodek = (Sloup1.position.topright[0]-2,height - 150) 
    line_thickness = 2

    # Calculate the end point of the line based on angle
    end_point = (spodek[0] + delka_cary * math.cos(math.radians(angle)),
                 spodek[1] + delka_cary * math.sin(math.radians(angle)))

    source_rect = pygame.Rect(Sloup1.position.topright[0]-3,height - 150-delka_cary-1, delka_cary+1, delka_cary+1)
    screen.blit(background, (Sloup1.position.topright[0]-3,height - 150-delka_cary-1), area=source_rect)
 
    # Draw the line
    pygame.draw.line(screen, black, spodek, end_point, line_thickness)
    
    angle += 1
    if angle >= 360:
        ypata=screen.get_height()-150
        angle = 270
        screen.blit(background, (Sloup1.position.topright[0]-3,height - 150-delka_cary-1), area=source_rect)
        pygame.draw.line(screen, black, spodek, (Sloup1.position.topright[0]-2+delka_cary,height - 150), line_thickness)
        return False
       
    return True

def running():
    global player
    source_rect = pygame.Rect(player.x, player.y, player.sirka, player.vyska)
    screen.blit(background, (player.x, player.y), area=source_rect)
    player.x+=4
    screen.blit(player.image,(player.x,player.y))
    if player.x>=Sloup2.position.topright[0]-Sloup2.surface.get_width()/2-player.image.get_width()/2:
         return False

def posun():
    global Sloup1,Sloup2
    screen.blit(background,(0,0))
    Sloup1.position.x -= 3
    Sloup2.position.x -= 3
    player.x-=3

    screen.blit(Sloup1.surface, Sloup1.position)
    screen.blit(Sloup2.surface, Sloup2.position)
    screen.blit(player.image,(player.x,player.y))
    if Sloup2.position.x<=0:
        Sloup2.position.x=0
        screen.blit(Sloup2.surface,Sloup2.position)
        Sloup1=Sloup2
        Sloup2=Sloup()
        Sloup2.final=Sloup2.surface.get_rect(topleft=(Sloup1.surface.get_width()+random.randint(30,height-150),screen.get_height()-150))
        return False
    

def jedeme():
    screen.blit(background, Sloup2.position,Sloup2.position)
    Sloup2.position.x-=3
    screen.blit(Sloup2.surface,Sloup2.position)
    if Sloup2.position.x<=Sloup2.final.x:
        return False


    




    #pygame.draw.rect(screen, black, (random.randint(0, 200), random.randint(0, 200), 3, 3))
