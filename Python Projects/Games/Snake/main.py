import pygame
from random import randrange

# Variables ---------------------------------------------------------------------- #
SCREEN_X_SIZE = 1300
SCREEN_Y_SIZE = 700

x_coord_snake = randrange(150, 850, 50)
y_coord_snake = randrange(150, 500, 50)

previous_x_coord_snake =  0
previous_y_coord_snake =  0

x_coord_food = randrange(150, 850, 50)
y_coord_food = randrange(150, 500, 50)

previous_snake_direction = None

snake_in_border = False

key_pressed = None

food_on_screen = False

snake_lenght = 1
snake_position_array = []
snake_in_body = False

score = 0

game_over = False

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

# Init Module -------------------------------------------------------------------- #
pygame.init()
pygame.display.set_caption("Snake")
screen = pygame.display.set_mode((SCREEN_X_SIZE, SCREEN_Y_SIZE))
clock = pygame.time.Clock()
running = True




# Functions ---------------------------------------------------------------------- #

def updateSnake(_x_coord, _y_coord, _previous_snake_direction, _snake_in_body, _game_over):

    snake_direction = updateDirection(_previous_snake_direction)
    
    game_has_start = True
    
    if snake_direction == "w":
        _y_coord -= 50
    elif snake_direction == "a":
        _x_coord -= 50
    elif snake_direction == "s":
        _y_coord += 50
    elif snake_direction == "d":
        _x_coord += 50
    else:
        game_has_start = False
        
    if game_has_start == True:
        # -- Check for Collision with Border and Body-- #
        snake_rect = pygame.Rect(_x_coord, _y_coord, 50, 50)
        collision_with_border = pygame.Rect.collidelist(snake_rect, border_rect_list)
        
        for i in range (0, len(snake_position_array)):
            if (_x_coord  == snake_position_array[i][0] and
                        _y_coord == snake_position_array[i][1]):

                _snake_in_body = True
                # print(snake_position_array)
                break
            else:
                continue

        if collision_with_border != -1:
            _x_coord = previous_x_coord_snake
            _y_coord = previous_y_coord_snake
            _game_over = True
        elif _snake_in_body == True:
            _game_over = True

    snake_rect = pygame.Rect(_x_coord, _y_coord, 50, 50)
    _previous_snake_direction = snake_direction


    return snake_rect, _x_coord, _y_coord, _previous_snake_direction, _snake_in_body, _game_over


def updateDirection(_previous_snake_direction):

    if key_pressed == pygame.K_w:
        snake_direction = "w"
    elif key_pressed == pygame.K_a:
        snake_direction = "a"
    elif key_pressed == pygame.K_s:
        snake_direction = "s"
    elif key_pressed == pygame.K_d:
        snake_direction = "d"
    else:
        # -- No button pressed -- #
        snake_direction = _previous_snake_direction

    # -- Check if snake is moving in opposite direction -- #
    if snake_direction == "w" and _previous_snake_direction == "s":
        snake_direction = _previous_snake_direction
    elif snake_direction == "s" and _previous_snake_direction == "w":
        snake_direction = _previous_snake_direction
    elif snake_direction == "a" and _previous_snake_direction == "d":
        snake_direction = _previous_snake_direction
    elif snake_direction == "d" and _previous_snake_direction == "a":
        snake_direction = _previous_snake_direction


    return snake_direction


def drawField(_snake_rect, _food_rect):
    # ToDo: Later add a smaller rect in the middle of the rect and only that is being filled everytime
    screen.fill("plum2")
    
    # -- Borders -- #
    pygame.draw.rect(screen, "darkgray", left_rect_border)
    pygame.draw.rect(screen, "darkgray", right_rect_border)
    pygame.draw.rect(screen, "darkgray", upper_rect_border)
    pygame.draw.rect(screen, "darkgray", lower_rect_border)

    # -- Text -- #
    # score_font = ARCADE_CLASSIC.render("Comic Sans MS", 50)
    score_font = pygame.font.Font("./Assets/ARCADECLASSIC.TTF", 60)
    
    snake_heading = score_font.render("Snake ", True, "black")
    screen.blit(snake_heading, (1000, 85))

    score_text = score_font.render("Score ", True, "black")
    screen.blit(score_text, (1000, 200))

    score_number = score_font.render(f"{score}", True, "black")
    screen.blit(score_number, (1190, 200))

    # -- Draw Food -- #
    pygame.draw.rect(screen, "red", _food_rect)

    # -- Draw Snake -- #
    # Head
    pygame.draw.rect(screen, "green", _snake_rect)
    # Body
    for i in range(1, snake_lenght):
        snake_rect = pygame.Rect(snake_position_array[i][0], snake_position_array[i][1], 50, 50)
        pygame.draw.rect(screen, "seagreen4", snake_rect) 
        

def generateFood(_food_on_screen, _x_coord_food, _y_coord_food):
    food_on_snake = False

    while _food_on_screen == False:
        _x_coord_food = randrange(150, 850, 50)
        _y_coord_food = randrange(150, 500, 50)

        for i in range (0, len(snake_position_array)):
            if (_x_coord_food == snake_position_array[i][0] and
                        _y_coord_food == snake_position_array[i][1]):

                food_on_snake = True
                break
            else:
                continue
        
        if food_on_snake == True:
            food_on_snake = False
        else:
            _food_on_screen = True

    food_rect = pygame.Rect(_x_coord_food, _y_coord_food, 50, 50)

    return _food_on_screen, food_rect, _x_coord_food, _y_coord_food





if __name__ == "__main__":
    while running:
        # poll for events
        # pygame.QUIT event means the user clicked X to close your window
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if event.type == pygame.KEYDOWN:
                key_pressed = event.key
            

        # RENDER YOUR GAME HERE
        snake_rect, x_coord_snake, y_coord_snake, previous_snake_direction, snake_in_body, game_over = updateSnake(x_coord_snake, y_coord_snake, previous_snake_direction, snake_in_body, game_over)

        food_on_screen, food_rect, x_coord_food, y_coord_food  = generateFood(food_on_screen, x_coord_food, y_coord_food)

        # -- Check if snake eats food -- #
        if x_coord_snake == x_coord_food and y_coord_snake == y_coord_food:
            snake_lenght += 1
            food_on_screen = False
            score += 1


        previous_x_coord_snake = x_coord_snake
        previous_y_coord_snake = y_coord_snake

        # -- Delete old position entrys -- #
        snake_position_array.insert(0, [x_coord_snake, y_coord_snake])
        for i in range(snake_lenght, len(snake_position_array)):
            snake_position_array.pop(i)

        drawField(snake_rect, food_rect)


        # -- Plot on screen -- #
        pygame.display.flip()


        clock.tick(5)  # Limit FPS

        while game_over == True:

            game_over_font = pygame.font.Font("./Assets/ARCADECLASSIC.TTF", 120)
            game_over_screen = game_over_font.render("Game Over", True, "black")
            screen.blit(game_over_screen, (200, 85))
            pygame.display.flip()

            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    pygame.quit()
                    exit()
                if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_r:
                        # Reset game state and restart the game
                        game_over = False
                        # Reset snake position, length, and other game variables here
                        snake_position_array = [[x_coord_snake, y_coord_snake]]
                        snake_lenght = 1
                        # Reset other necessary variables
                        break
                    elif event.key == pygame.K_q:
                        pygame.quit()
                        exit()



    pygame.quit()









"""
ToDo:
- 
"""