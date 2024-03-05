import pygame
import random

size = width, height = 720,540
screen = pygame.display.set_mode(size)
clock = pygame.time.Clock()
pygame.display.set_caption("Ninja runner")
pygame.mixer.init()
pygame.init()

class Sloup:
    """    
    Reprezentuje sloupek ve hře.

    Attributes:
        surface (pygame.Surface): Plocha sloupku.
        position (pygame.Rect): Pozice sloupku na obrazovce.
        final (pygame.Rect): Konečná pozice sloupku po posunu.
    """
    def __init__(self):
        """
        Inicializuje nový sloupek.

        Sloupek má náhodnou šířku mezi 50 a 90 pixely a výšku 150 pixelů.
        Na ploše sloupku je vykreslen červený čtverec, který označuje
        místo, které hráč musí nejlépe trefit.

        """
        self.surface=pygame.Surface((random.randint(50,90), 150))
        self.surface.fill(black)
        fill_rect = pygame.Rect(self.surface.get_width()/2-5, 0, 10, 10)
        self.surface.fill(red,fill_rect)
        self.position=self.surface.get_rect(topleft=(screen.get_width(),screen.get_height() - self.surface.get_height()))
        self.final=self.surface.get_rect(topleft=(0,screen.get_height() - self.surface.get_height()))

class Player:
    """
    Reprezentuje hráče ve hře Flappy Bird.

    Attributes:
        image (pygame.Surface): Obrázek hráče.
        x (int): Pozice hráče na ose x.
        y (int): Pozice hráče na ose y.
        sirka (int): Šířka hráče.
        vyska (int): Výška hráče.
    """
    def __init__(self, image_path):
        """
        Inicializuje nového hráče.

        Args:
            image_path (str): Cesta k souboru s obrázkem hráče.
        """
        self.image = pygame.image.load(image_path)
        self.x = Sloup1.surface.get_width()/2-self.image.get_width()/2
        self.y = screen.get_height()-150-self.image.get_height()
        self.sirka = self.image.get_width()
        self.vyska = self.image.get_height()
    def restart(self):
        """        
        Restartuje pozici hráče.

        Metoda nastaví pozici hráče na počáteční hodnotu.
        
        Returns:
            None
        """
        self.x = Sloup1.surface.get_width()/2-self.image.get_width()/2
        self.y = screen.get_height()-150-self.image.get_height()

class Button:
    """
    Reprezentuje tlačítko .

    Attributes:
        image (pygame.Surface): Obrázek tlačítka.
        rect (pygame.Rect): Obdélníková oblast tlačítka.
        visible (bool): Určuje, zda je tlačítko viditelné.
    """
    def __init__(self,image_path):
        """
        Inicializuje nové tlačítko.

        Args:
            image_path (str): Cesta k souboru s obrázkem tlačítka.
        """
        self.image = pygame.image.load(image_path)
        self.rect = self.image.get_rect()
        self.rect.center = (width // 2, 100)
        self.visible=False

    def is_clicked(self, pos):
        """        
        Kontroluje, zda bylo tlačítko kliknuto.

        Args:
            pos (tuple): Pozice kliknutí myší ve formátu (x, y).

        Returns:
            bool: True, pokud bylo tlačítko kliknuto a je viditelné, jinak False.
        """
        if not self.visible:
            return False
        self.visible=False
        return self.rect.collidepoint(pos)


black=0,0,0
red=255,0,0
brown=139,69,19
white=255,255,255
font = pygame.font.SysFont(None, 60)


speed=15
angle=270
delay=0
delka_cary=0
ypata=screen.get_height()-150
dosahuje=False
presny=False
skore=0

Sloup1=Sloup()
Sloup2=Sloup()
player=Player("sprite_0.png")
hampter=pygame.image.load("hampter.png")
hamster_song=pygame.mixer.Sound('hamstersong.mp3')
restart_button=Button("restart.png")
music=pygame.mixer.Sound("music.mp3")


background = pygame.image.load("ledovy.jpg")

