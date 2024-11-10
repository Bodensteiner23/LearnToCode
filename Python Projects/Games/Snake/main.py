import pygame

# Variables ---------------------------------------------------------------------- #
SCREEN_X_SIZE = 1300
SCREEN_Y_SIZE = 700


x_coord_snake = 650
y_coord_snake = 450
previous_x_coord_snake =  0
previous_y_coord_snake =  0

previous_snake_direction = 0

snake_in_border = False

# -- Borders -- #
# ToDo: Only make one inner rect and check if snake is outside of that
left_rect_border = pygame.Rect(100, 100, 50, 500)      # Left, Top, Width, Height
right_rect_border = pygame.Rect(900, 100, 50, 500)
upper_rect_border = pygame.Rect(150, 100, 750, 50)
lower_rect_border = pygame.Rect(150, 550, 750, 50)

border_rect_list = [left_rect_border,
                    right_rect_border,
                    upper_rect_border,
                    lower_rect_border]


# Functions ---------------------------------------------------------------------- #

def updateSnake(_x_coord, _y_coord, _previous_snake_direction):
    key_pressed = pygame.key.get_pressed()

    snake_direction = updateDirection(key_pressed, _previous_snake_direction)
    print(f"Snake Direction: {snake_direction}")

    if snake_direction == "w":
        _y_coord -= 50
    elif snake_direction == "a":
        _x_coord -= 50
    elif snake_direction == "s":
        _y_coord += 50
    elif snake_direction == "d":
        _x_coord += 50
    
    # -- Check for Collision -- #
    snake_rect = pygame.Rect(_x_coord, _y_coord, 50, 50)
    collision_with_border = pygame.Rect.collidelist(snake_rect, border_rect_list)

    if collision_with_border != -1:
        _x_coord = previous_x_coord_snake
        _y_coord = previous_y_coord_snake
        # print(f"Border!!")

    snake_rect = pygame.Rect(_x_coord, _y_coord, 50, 50)
    _previous_snake_direction = snake_direction

    return snake_rect, _x_coord, _y_coord, _previous_snake_direction


def updateDirection(_key_pressed, _previous_snake_direction):
    if _key_pressed[pygame.K_w]:
        snake_direction = "w"
    elif _key_pressed[pygame.K_a]:
        snake_direction = "a"
    elif _key_pressed[pygame.K_s]:
        snake_direction = "s"
    elif _key_pressed[pygame.K_d]:
        snake_direction = "d"
    else:
        snake_direction = _previous_snake_direction

    return snake_direction


def drawField(_snake_rect):
    # ToDo: Later add a smaller rect in the middle of the rect and only that is being filled everytime
    screen.fill("plum2")
    
    # -- Borders -- #
    pygame.draw.rect(screen, "darkgray", left_rect_border)
    pygame.draw.rect(screen, "darkgray", right_rect_border)
    pygame.draw.rect(screen, "darkgray", upper_rect_border)
    pygame.draw.rect(screen, "darkgray", lower_rect_border)

    # -- Text -- #
    score_font = pygame.font.SysFont("Comic Sans MS", 50)
    
    snake_heading = score_font.render("Snake ", True, "black")
    screen.blit(snake_heading, (1000, 85))

    score_text = score_font.render("Score: ", True, "black")
    screen.blit(score_text, (1000, 200))

    score_number = score_font.render("10", True, "black")
    screen.blit(score_number, (1170, 200))

    # -- Draw Snake -- #
    pygame.draw.rect(screen, "seagreen4", _snake_rect) 

def generateFood(_food_on_screen):

    # ToDo: Food darf nicht auf Schlange generiert werden
    # Auch checken ob Food schon generiert wurde und noch nicht aufgesammelt wurde



    pass





if __name__ == "__main__":

    # -- Init Module -- #
    pygame.init()
    pygame.display.set_caption("Snake")
    screen = pygame.display.set_mode((SCREEN_X_SIZE, SCREEN_Y_SIZE))
    clock = pygame.time.Clock()
    running = True
    
    # -- Main Loop -- #
    while running:
        # poll for events
        # pygame.QUIT event means the user clicked X to close your window
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
        
        # RENDER YOUR GAME HERE
        snake_rect, x_coord_snake, y_coord_snake, previous_snake_direction = updateSnake(x_coord_snake, y_coord_snake, previous_snake_direction)

        previous_x_coord_snake = x_coord_snake
        previous_y_coord_snake = y_coord_snake
        
        drawField(snake_rect)


        # -- Plot on screen -- #
        pygame.display.flip()


        clock.tick(5)  # limits FPS to 60

    pygame.quit()









"""
ToDo:
- Schlange in eine Richtung bewegen bis eine neue Rechung eingeschlagen wird
- Food generieren
- Schlange am Anfang an random Positon platzieren
- Schlange updaten wenn sie länger wird
- Schlange kleiner machen?

"""