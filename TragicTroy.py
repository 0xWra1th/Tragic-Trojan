# +-------------+
# | TRAGIC TROY |
# +-------------+
# A game about a boy named Troy.
# Troy is a nerd with very little going for him except for his computer hacking skills.
# Troy wants to get back at his bullies by hacking them, but how?

# Libraries
import time, os
import pygame as pg

# Constants
WIDTH, HEIGHT = 900, 500
FPS = 60
SPEED = 3
TROY_WIDTH, TROY_HEIGHT = 50, 67

# Window 
WINDOW = pg.display.set_mode((WIDTH, HEIGHT))
pg.display.set_caption("Tragic Troy")

# Colors
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
LIGHT_GREEN = (125, 255, 125)
GREEN = (0, 255, 0)
DARK_GREEN = (0, 125, 0)

# Images
TROY_IMAGE_DOWN = pg.image.load(os.path.join('assets', 'troy_forward.png'))
TROY_IMAGE_UP = pg.image.load(os.path.join('assets', 'troy_back.png'))
TROY_IMAGE_LEFT = pg.image.load(os.path.join('assets', 'troy_left.png'))
TROY_IMAGE_RIGHT = pg.image.load(os.path.join('assets', 'troy_right.png'))


# Main function, it all starts here...
def main():
    print("+-------------+\n| TRAGIC TROY |\n+-------------+")
    gameSetup()
    gameLoop()

# Initialise a new game
def gameSetup():
	print("The game is starting up...")

# Standard game update loop
def gameLoop():
	# Game Objects
	TROY = pg.transform.scale(TROY_IMAGE_DOWN, (TROY_WIDTH, TROY_HEIGHT))
	troy = pg.Rect((WIDTH/2)-(TROY_WIDTH/2), (HEIGHT/2)-(TROY_HEIGHT/2), TROY_WIDTH, TROY_HEIGHT)
	clock = pg.time.Clock()
	run = True

	while run:
		# Limit FPS
		clock.tick(FPS)

		# Handle Events
		for event in pg.event.get():
			if event.type == pg.QUIT:
				run = False
				pg.quit()
				exit()

		# Handle Movement
		keys = pg.key.get_pressed()
		if keys[pg.K_a]:  # LEFT
			troy.x -= SPEED
			TROY = pg.transform.scale(TROY_IMAGE_LEFT, (TROY_WIDTH, TROY_HEIGHT))
		if keys[pg.K_d]:  # RIGHT
			troy.x += SPEED
			TROY = pg.transform.scale(TROY_IMAGE_RIGHT, (TROY_WIDTH, TROY_HEIGHT))
		if keys[pg.K_w]:  # UP
			troy.y -= SPEED
			TROY = pg.transform.scale(TROY_IMAGE_UP, (TROY_WIDTH, TROY_HEIGHT))
		if keys[pg.K_s]:  # DOWN
			troy.y += SPEED
			TROY = pg.transform.scale(TROY_IMAGE_DOWN, (TROY_WIDTH, TROY_HEIGHT))

		# Update Window
		WINDOW.fill(DARK_GREEN)
		WINDOW.blit(TROY, (troy.x, troy.y))
		pg.display.update()


# Run the main function as the program starts.
if __name__ == "__main__":
    main()