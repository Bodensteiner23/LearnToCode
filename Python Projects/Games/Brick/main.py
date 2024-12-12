import pygame as py
import random

# Variables -------------------------------------------------------------------- #

# -- Window Size -- #
WINDOW_X_SIZE = 1000
WINDOW_Y_SIZE = 500
window_x_min, window_x_max = 0, 1000
window_y_min, window_y_max = 0, 500

# -- py Setupt -- #
py.init()
screen = py.display.set_mode((WINDOW_X_SIZE, WINDOW_Y_SIZE))
py.display.set_caption("Bricks")

clock = py.time.Clock()

ARCADE_FONT_PATH = "./Assets/ARCADECLASSIC.TTF"

# -- Game specific variables -- #
previous_x_bar_position = 460
# ToDo: Add random starting direction
ball_speed = [8, 8]


# Functions -------------------------------------------------------------------- #

def startingScreen():
    screen.fill("black")
    starting_screen_font1 = py.font.Font(ARCADE_FONT_PATH, 200)     # Big Font
    starting_screen_font2 = py.font.Font(ARCADE_FONT_PATH, 70)      # Small Font
    
    startFont1 = starting_screen_font1.render("BRICKS", True, "white")
    screen.blit(startFont1, (170, 120))

    startFont2 = starting_screen_font2.render("press   s   to  start", True, "white")
    screen.blit(startFont2, (220, 320))


def createMap():
    position_array = []
    # -- Bar Rect -- #
    position_array.append((420, 490))
    # -- Ball -- #
    position_array.append((500, 480))
    # -- Create Rects to shoot -- #
    for i in range(2, 803, 200):
        for j in range(5, 131, 30):
            position_array.append((i, j))
    
    return position_array # First pos is bar, seccond pos is ball
    

def updateBarPositions(_bar_direction, _previous_x_bar_position):
    move_bar_dir = 0
    if _bar_direction[0] == "right":
        move_bar_dir += 8
    elif _bar_direction[1] == "left":
        move_bar_dir -= 8

    bar_x_pos = _previous_x_bar_position + move_bar_dir
    if bar_x_pos >= 920 or bar_x_pos <= 0:  
        bar_x_pos = _previous_x_bar_position    # Don't leave the window
    else : 
        _previous_x_bar_position = bar_x_pos
    
    return bar_x_pos, _previous_x_bar_position


def updateBallPositions(_ball_pos):
    new_ball_pos = [_ball_pos[0] + ball_speed[0], _ball_pos[1] + ball_speed[1]]

    if new_ball_pos[0] >= window_x_max:
        ball_speed[0] *= -1
        new_ball_pos[0] = window_x_max
    elif new_ball_pos[0] <= window_x_min:
        ball_speed[0] *= -1
        new_ball_pos[0] = window_x_min

    if new_ball_pos[1] >= window_y_max:
        ball_speed[1] *= -1
        new_ball_pos[1] = window_y_max
    elif new_ball_pos[1] <= window_y_min:
        ball_speed[1] *= -1
        new_ball_pos[1] = window_y_min
    
    return new_ball_pos


def updateMap(_position_array, _bar_x_pos):
    rect_array = []

    rect_array.append(py.Rect((_bar_x_pos, _position_array[0][1]), (80, 10)))
    py.draw.rect(screen, "red", rect_array[0])

    py.draw.circle(screen, "white", (_position_array[1][0], _position_array[1][1]), 10)

    for i in range(2, len(_position_array)):
        rect_array.append(py.Rect((_position_array[i][0], _position_array[i][1]), (195, 25)))
        py.draw.rect(screen, "seagreen", rect_array[i - 1])

    return rect_array


def checkCollision(_position_array, _rect_array):
    ball_rect = py.Rect(_position_array[1][0], _position_array[1][1], 10, 10)

    for i in range(2, len(_rect_array)):
        if ball_rect.colliderect(_rect_array[i]):
            print(f"Länge: {len(_rect_array)}")
            print(i)
            _position_array.pop(i)
            break

    return _position_array


if __name__ == "__main__":
    
    starting_screen = True
    game_running = False

    # -- Starting screen -- #
    while starting_screen:
        for event in py.event.get():
            if event.type == py.QUIT:
                starting_screen = False
            if event.type == py.KEYDOWN:
                if event.key == py.K_q:
                    starting_screen = False
                if event.key == py.K_s:
                    game_running = True
                    starting_screen = False
        
        startingScreen()
        py.display.flip()

    position_array = createMap()
    rect_array = []

    while game_running:
        bar_direction = [None, None]
        # poll for events
        # py.QUIT event means the user clicked X to close your window
        for event in py.event.get():
            if event.type == py.QUIT:
                game_running = False
            if event.type == py.KEYDOWN:
                if event.key == py.K_q:
                    game_running = False



        # Background
        screen.fill("black")

        keys = py.key.get_pressed()
        if keys[py.K_RIGHT] and keys[py.K_LEFT]:
            # -- Stop the bar if both keys are pressed -- #
            pass
        elif keys[py.K_RIGHT]:
            bar_direction[0] = "right"
        elif keys[py.K_LEFT]:
            bar_direction[1] = "left"

        position_array = checkCollision(position_array ,rect_array)

        bar_x_pos, previous_x_bar_position = updateBarPositions(bar_direction, previous_x_bar_position)
        position_array[1] = updateBallPositions(position_array[1])

        rect_array = updateMap(position_array, bar_x_pos)


        # flip() the display to put your work on screen
        py.display.flip()

        # limits FPS to 60
        # dt is delta time in seconds since last frame, used for framerate-
        # independent physics.
        clock.tick(10)

    py.quit()







'''
###############################################################################
                                Brick Game
###############################################################################
- Ball ist auf Balken unten und fängt erst an sich zu bewegen, wenn user sich bewegt
- Ball springt an Wände und verlässt das Spielfeld nicht
- Ball prallt von rechtecken ab
- Rechtecke werden gelöscht


'''