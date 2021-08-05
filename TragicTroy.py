# +-------------+
# | TRAGIC TROY |
# +-------------+
# A game about a boy named Troy.
# Troy is a nerd with very little going for him except for his computer hacking skills.
# Troy wants to get back at his bullies by hacking them, but how?
#

# Libraries
import time
import pygame as pg

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
	while True:
		print("Beep boop beep!")
		time.sleep(2.5)

# Run the main function as the program starts.
if __name__ == "__main__":
    main()