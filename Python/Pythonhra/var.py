import pygame
import random

size = width, height = 720,540
screen = pygame.display.set_mode(size)
clock = pygame.time.Clock()

class Sloup:
  def __init__(self):
      self.surface=pygame.Surface((random.randint(50,90), 150))
      self.surface.fill(black)
      fill_rect = pygame.Rect(self.surface.get_width()/2-5, 0, 10, 10)
      self.surface.fill(red,fill_rect)
      self.position=self.surface.get_rect(topleft=(screen.get_width(),screen.get_height() - self.surface.get_height()))
      self.final=self.surface.get_rect(topleft=(0,screen.get_height() - self.surface.get_height()))

black=0,0,0
red=255,0,0
brown=139,69,19

speed=15
angle=4.712
delay=0
delka_cary=0
ypata=0

Sloup1=Sloup()
Sloup2=Sloup()

background = pygame.image.load("ledovy.jpg")
player=pygame.image.load("sprite_0.png")
