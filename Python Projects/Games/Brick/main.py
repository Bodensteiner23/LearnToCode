import pygame


WINDOW_X_SIZE = 1000
WINDOW_Y_SIZE = 500


# -- Pygame Setupt -- #
pygame.init()
screen = pygame.display.set_mode((WINDOW_X_SIZE, WINDOW_Y_SIZE))
pygame.display.set_caption("Bricks")


clock = pygame.time.Clock()
starting_screen = True
game_running = False

ARCADE_FONT_PATH = "./Assets/ARCADECLASSIC.TTF"

position_array = []



def startingScreen():

    screen.fill("black")
    starting_screen_font1 = pygame.font.Font(ARCADE_FONT_PATH, 200)     # Big Font
    starting_screen_font2 = pygame.font.Font(ARCADE_FONT_PATH, 70)      # Small Font
    
    startFont1 = starting_screen_font1.render("BRICKS", True, "white")
    screen.blit(startFont1, (170, 120))

    startFont2 = starting_screen_font2.render("press   s   to  start", True, "white")
    screen.blit(startFont2, (220, 320))


def createMap():

    for i in range(2, 803, 200):
        for j in range(10, 131, 30):
            position_array.append((i, j))
    





if __name__ == "__main__":
    
    # -- Starting screen -- #
    while starting_screen:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                starting_screen = False
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_s:
                    game_running = True
                    starting_screen = False
        
        startingScreen()
        pygame.display.flip()

    createMap()
    print(position_array)

    while game_running:
        # poll for events
        # pygame.QUIT event means the user clicked X to close your window
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                game_running = False

        # Background
        screen.fill("snow2")

        for i in range(0, len(position_array)):
            map_rect = pygame.Rect((position_array[i][0], position_array[i][1]), (195, 25))
            pygame.draw.rect(screen, "seagreen", map_rect)

        # flip() the display to put your work on screen
        pygame.display.flip()

        # limits FPS to 60
        # dt is delta time in seconds since last frame, used for framerate-
        # independent physics.
        clock.tick(60)

    pygame.quit()







'''
###############################################################################
                                Brick Game
###############################################################################
- Map generieren mit arrays mit [x-pos][y-pos]
- Ball ist auf Balken unten und fängt erst an sich zu bewegen, wenn user sich bewegt
                                
'''