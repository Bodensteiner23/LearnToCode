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
    positions = {
        "bar_position": [],
        "ball_position": [],
        "shoot_rect_position": []
    }
    # -- Bar Rect -- #
    positions["bar_position"].append((420, 490))
    # -- Ball -- #
    positions["ball_position"].append((500, 480))
    # -- Create Rects to shoot -- #
    for i in range(0, 801, 200):
        for j in range(5, 126, 30):
            positions["shoot_rect_position"].append((i, j))
    
    return positions  # First pos is bar, seccond pos is ball
    

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


def updateBallPositions(_positions):
    current_ball_pos = _positions["ball_position"][0]

    new_ball_pos = [current_ball_pos[0] + ball_speed[0],
                    current_ball_pos[1] + ball_speed[1]]
    

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


def updateMap(_positions, _bar_x_pos):
    rects = {
        "bar_rect": [],
        "ball_rect": [],
        "shoot_rect": []
    }

    rects["bar_rect"].append(py.Rect((_bar_x_pos, _positions["bar_position"][0][1]), (80, 10)))
    py.draw.rect(screen, "red", rects["bar_rect"][0])

    rects["ball_rect"].append(py.Rect(_positions["ball_position"][0][0],
                                        _positions["ball_position"][0][1], 10, 10 ))
    py.draw.circle(screen, "white", (_positions["ball_position"][0][0], 
                                        _positions["ball_position"][0][1]), 10)

    for i in range(0, len(_positions["shoot_rect_position"])):
        rects["shoot_rect"].append(py.Rect((_positions["shoot_rect_position"][i][0], 
                                            _positions["shoot_rect_position"][i][1]), (195, 25)))
        py.draw.rect(screen, "seagreen", rects["shoot_rect"][i])

    return rects


def checkCollision(_positions, _rects):
    # ball_rect = py.Rect(_position_array[1][0], _position_array[1][1], 10, 10)

    # if py.Rect.colliderect(_rects[0], _rects[1]):
    #     ball_speed[1] *= -1
    # elif py.Rect.collidelist(_rects[1], _rects):
    #     print("test")

    if py.Rect.colliderect(_rects["ball_rect"], _rects["bar_rect"]):
        ball_speed[1] *= -1



    return _positions


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

    main_positions = createMap()
    main_rects = []
    bar_x_pos = 0

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


        bar_x_pos, previous_x_bar_position = updateBarPositions(bar_direction, previous_x_bar_position)

        main_positions["ball_position"][0] = updateBallPositions(main_positions)

        rects = updateMap(main_positions, bar_x_pos)

        main_positions = checkCollision(main_positions, main_rects)

        # flip() the display to put your work on screen
        py.display.flip()

        # limits FPS to 60
        # dt is delta time in seconds since last frame, used for framerate-
        # independent physics.
        clock.tick(60)

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