import random,pygame,math
from var import Button,Sloup,red,presny,skore,screen,white,player,background,Sloup1,Sloup2,black,delka_cary,ypata,angle,clock,height,dosahuje,hampter,hamster_song,width,restart_button,font


def zacatek():
    """
    Inicializuje počáteční stav hry.

    Globalní proměnná skore se inicializuje.
    Sloup1 a Sloup2 se umístí na obrazovku na vhodné pozice.
    Hráč se umístí na prvni sloup.
    Načte pozadí obrazovky a vykreslí se na ní hráč a sloupy.
    Skóre hráče se zobrazí v horní části obrazovky.
    
    Returns:
    None
    """
    global skore
    Sloup1.position.topleft=(0,screen.get_height()-Sloup1.surface.get_height())
    Sloup2.position.topleft=(Sloup1.surface.get_width()+random.randint(30,height-150),screen.get_height()-150)
    #Sloup2.final=Sloup2.surface.get_rect(topleft=(0,screen.get_height()-150))
    player.x=Sloup1.surface.get_width()/2-player.image.get_width()/2
    player.y=screen.get_height()-150-player.image.get_height()
    screen.blit(background, (0, 0))
    #screen.blit(player, (Sloup1.surface.get_width()/2-player.get_width()/2, screen.get_height()-150-player.get_height()))
    screen.blit(player.image,(player.x,player.y))
    screen.blit(Sloup1.surface, Sloup1.position)
    screen.blit(Sloup2.surface,Sloup2.position)
    text = font.render(str(skore), True, red)
    screen.blit(text, (width/2-text.get_width()/2,0))
    pygame.display.update()
    return

def kresleni():
    """
    Vykresluje most když hráč drží tlačítko.

    Každý tick nakresli čtvereček 2*2 a posune y, pro kreslení dalšího čtverečku.
    
    Returns:
        bool: True, pokud je se dostane na hranu obrazovky, jinak False.
    """
    global delka_cary,ypata,clock,height
    pygame.draw.rect(screen, black, (Sloup1.position.topright[0]-2,ypata-2, 2, 3))
    ypata-=3
    delka_cary+=3
    if delka_cary>=height-150:
        delka_cary=height-150
        return True
    return False


def rotace():
    """
    Provádí rotaci mostu a kontroluje, jestli dosáhl dalšího sloupu.

    Tato funkce provádí rotaci mostů a zároveň kontroluje, jestli dosáhl dalšího sloupu.
    

    Returns:
        bool: True po dokončení rotace, jinak False.
    """
    global delka_cary,angle,ypata,dosahuje
    spodek = (Sloup1.position.topright[0]-2,height - 150) 
    line_thickness = 2

    # Calculate the end point of the line based on angle
    end_point = (spodek[0] + delka_cary * math.cos(math.radians(angle)),
                 spodek[1] + delka_cary * math.sin(math.radians(angle)))

    source_rect = pygame.Rect(Sloup1.position.topright[0]-3,height - 150-delka_cary-1, delka_cary+1, delka_cary+1)
    screen.blit(background, (Sloup1.position.topright[0]-3,height - 150-delka_cary-1), area=source_rect)
 
    # Draw the line
    pygame.draw.line(screen, black, spodek, end_point, line_thickness)
    
    angle += 2
    if angle >= 360:
        ypata=screen.get_height()-150
        angle = 270
        screen.blit(background, (Sloup1.position.topright[0]-3,height - 150-delka_cary-1), area=source_rect)
        pygame.draw.line(screen, black, spodek, (Sloup1.position.topright[0]-2+delka_cary,height - 150), line_thickness)
        

        if delka_cary<Sloup2.position.topleft[0]-Sloup1.position.topright[0] or delka_cary>Sloup2.position.topright[0]-Sloup1.position.topright[0]:
            dosahuje=False
        
        
        return False
    dosahuje=True 
    return True

def running():
    """
    Posouvá hráče a rika kam ma dobehnout, taky vraci info jestli dosahne most.

    Tato funkce řídí pohyb hráče vpřed a zároveň kontroluje dosah mostu.
    Pokud most nedosahne, vratime ze hrac nedobehl a zemrel.

    Returns:
        tuple: Dvojice hodnot (bool, bool):
               - První hodnota True, pokud je funkce u konce, jinak False.
               - Druhá hodnota True, pokud jsme dosahli na druhy sloup, jinak False.
    """
    global player,delka_cary,dosahuje,presny
    source_rect = pygame.Rect(player.x, player.y, player.sirka, player.vyska)
    screen.blit(background, (player.x, player.y), area=source_rect)
    player.x+=4
    screen.blit(player.image,(player.x,player.y))
    if dosahuje==True:
        if player.x>=Sloup2.position.topright[0]-Sloup2.surface.get_width()/2-player.image.get_width()/2:
            if delka_cary>=Sloup2.position.centerx-10-Sloup1.position.topright[0] and delka_cary<=Sloup2.position.center[0]+10-Sloup1.position.topright[0]:
                presny=True
            delka_cary=0
            return True,True
    elif dosahuje==False:
        if player.x>=Sloup1.position.topright[0]+delka_cary:
            return True,False
    return False,True

def posun():
    """
    Posouvá celý obraz kromě pozadí vlevo a vytváří nový pár trubek po opuštění obrazovky.

    Tato funkce posouvá sloupy a hráče vlevo o určitou rychlost. Pokud je vše hotovo,
    vytvoří se nový Sloup na pravém okraji obrazovky.

    Returns:
        bool: True, pokud je funkce hotová, jinak False.
    """
    global Sloup1,Sloup2
    screen.blit(background,(0,0))
    Sloup1.position.x -= 7
    Sloup2.position.x -= 7
    player.x-=7

    screen.blit(Sloup1.surface, Sloup1.position)
    screen.blit(Sloup2.surface, Sloup2.position)
    screen.blit(player.image,(player.x,player.y))
    if Sloup2.position.x<=0:
        Sloup2.position.x=0
        screen.blit(Sloup2.surface,Sloup2.position)
        Sloup1=Sloup2
        Sloup2=Sloup()
        Sloup2.final=Sloup2.surface.get_rect(topleft=(Sloup1.surface.get_width()+random.randint(30,height-150-Sloup2.surface.get_width()-20),screen.get_height()-150))
        return False
    

def jedeme():
    """
    Řídí pohyb druhého sloupku a kontroluje překonání překážky.

    Tato funkce řídí pohyb druhého sloupku a kontroluje, zda hráč
    překonal překážku. Pokud hráč úspěšně překoná překážku, zvyšuje se
    skóre a v případě přesného překonání se skóre zvyšuje dvojnásobně.

    Returns:
        bool: True, pokud je posun u konce, jinak False.
    """
    global skore,presny
    screen.blit(background, Sloup2.position,Sloup2.position)
    Sloup2.position.x-=10
    screen.blit(Sloup2.surface,Sloup2.position)
    if Sloup2.position.x<=Sloup2.final.x:
        skore+=1
        if presny==True:
            skore+=1
            presny=False
        return False
    
def game_over():
    """
    Zobrazuje obrazovku Game Over a umožňuje restart hry.

    Tato funkce zobrazuje obrazovku Game Over, resetuje hodnotu délky mostu hráče,
    přehrává zvukový efekt a umožňuje restart hry pomocí tlačítka.

    Returns:
        None
    """
    global delka_cary,restart_button,font,text,skore
    delka_cary=0
    screen.fill(black)
    screen.blit(hampter,(20,0))
    text = font.render("GAME OVER!", True, white)
    screen.blit(text, (width/2-text.get_width()/2,0))
    hamster_song.set_volume(0.1)
    hamster_song.play()
    restart_button.image=pygame.transform.scale(restart_button.image,(100,100))
    restart_button.rect = restart_button.image.get_rect()
    restart_button.rect.center = (width // 2, 100)
    restart_button.visible=True
    screen.blit(restart_button.image,restart_button.rect)
    skore=0

def score():
    """
    Vykresluje aktuální skóre na obrazovku.

    Tato funkce vykresluje aktuální skóre na obrazovku ve středu horní části obrazovky.
    
    Returns:
        None
    """
    global skore
    text = font.render(str(skore), True, red)
    screen.blit(background, (width // 2 - text.get_width() // 2, 0), (width // 2 - text.get_width() // 2, 0, text.get_width(), text.get_height()))
    screen.blit(text, (width/2-text.get_width()/2,0))

def smrt():
    """
    Simuluje pád hráče po jeho smrti.

    Tato funkce simuluje pád hráče po jeho smrti. Postupně snižuje
    vertikální pozici hráče a vykresluje jeho novou pozici na obrazovce.

    Returns:
        None
    """
    for i in range(player.y):
        source_rect = pygame.Rect(player.x, player.y, player.sirka, player.vyska)
        screen.blit(background, (player.x, player.y), area=source_rect)
        screen.blit(Sloup2.surface,Sloup2.position)
        player.y+=0.5
        screen.blit(player.image,(player.x,player.y))
        pygame.display.flip()
        i+=1


