import pygame
from random import randrange


# Variables -------------------------------------------------------------------- #

WINDOW_X_SIZE = 1000
WINDOW_Y_SIZE = 500


# -- Pygame Setupt -- #
pygame.init()
screen = pygame.display.set_mode((WINDOW_X_SIZE, WINDOW_Y_SIZE))
pygame.display.set_caption("Bricks")

clock = pygame.time.Clock()

ARCADE_FONT_PATH = "./Assets/ARCADECLASSIC.TTF"

# -- Game specific variables -- #
previous_x_bar_position = randrange(0, 420, 1)

# Functions -------------------------------------------------------------------- #

def startingScreen():
    screen.fill("black")
    starting_screen_font1 = pygame.font.Font(ARCADE_FONT_PATH, 200)     # Big Font
    starting_screen_font2 = pygame.font.Font(ARCADE_FONT_PATH, 70)      # Small Font
    
    startFont1 = starting_screen_font1.render("BRICKS", True, "white")
    screen.blit(startFont1, (170, 120))

    startFont2 = starting_screen_font2.render("press   s   to  start", True, "white")
    screen.blit(startFont2, (220, 320))


def createMap():
    position_array = []
    # -- Create Rects to shoot -- #
    for i in range(2, 803, 200):
        for j in range(5, 131, 30):
            position_array.append((i, j))
    # -- Bar Rect -- #
    position_array.insert(0, (420, 490))
    
    return position_array # First pos is bar
    

def updateBarPositions(_bar_direction, _previous_x_bar_position):
    move_bar_dir = 0
    if _bar_direction[0] == "right":
        move_bar_dir += 8
        print("right")
    elif _bar_direction[1] == "left":
        move_bar_dir -= 8
        print("left")

    bar_x_pos = _previous_x_bar_position + move_bar_dir
    _previous_x_bar_position = bar_x_pos
    
    return bar_x_pos, _previous_x_bar_position


def updateMap(_position_array, _x_pos):
    rect_array = []

    rect_array.append(pygame.Rect((_x_pos, _position_array[0][1]), (80, 10)))
    pygame.draw.rect(screen, "red", rect_array[0])

    for i in range(1, len(_position_array)):
        rect_array.append(pygame.Rect((_position_array[i][0], _position_array[i][1]), (195, 25)))
        pygame.draw.rect(screen, "seagreen", rect_array[i])



if __name__ == "__main__":
    
    starting_screen = True
    game_running = False

    # -- Starting screen -- #
    while starting_screen:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                starting_screen = False
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_q:
                    starting_screen = False
                if event.key == pygame.K_s:
                    game_running = True
                    starting_screen = False
        
        startingScreen()
        pygame.display.flip()

    
    position_array = createMap()

    while game_running:
        bar_direction = [None, None]
        # poll for events
        # pygame.QUIT event means the user clicked X to close your window
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                game_running = False
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_q:
                    game_running = False



        # Background
        screen.fill("black")

        keys = pygame.key.get_pressed()
        if keys[pygame.K_RIGHT] and keys[pygame.K_LEFT]:
            # -- Stop the bar if both keys are pressed -- #
            pass
        elif keys[pygame.K_RIGHT]:
            bar_direction[0] = "right"
        elif keys[pygame.K_LEFT]:
            bar_direction[1] = "left"

        bar_x_pos, previous_x_bar_position = updateBarPositions(bar_direction, previous_x_bar_position)
        updateMap(position_array, bar_x_pos)

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