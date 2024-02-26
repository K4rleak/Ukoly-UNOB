import pygame
import sys
import math

# Initialize Pygame
pygame.init()
kresleni = True

# Set up the display
width, height = 400, 400
screen = pygame.display.set_mode((width, height))
pygame.display.set_caption("Rotating Line Animation")

# Set up colors
black = (0, 0, 0)

# Initial position and angle
x, y = 100, 100
angle = 0

# Boolean flags to control animation
drawing = True
rotating = False

# Main game loop
while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

    # Clear the screen
    screen.fill((255, 255, 255))  # Fill with white background

    # Draw a line
    if drawing:
        rotating=True
        drawing = False
        # pygame.draw.line(screen, black, (x, 100), (x, y + 20), 2)
        # y += 1
        # if y >= 140:
        #     drawing = False
        #     rotating = True

    # Rotate the line
    if rotating:
        pygame.draw.line(screen,black,(x, y),(x + int(50 * math.cos(angle)),y + int(50 * math.sin(angle)),),2,)
        angle += 0.01

    # Update the display
    pygame.display.flip()

    # Cap the frame rate (optional)
    pygame.time.Clock().tick(60)
