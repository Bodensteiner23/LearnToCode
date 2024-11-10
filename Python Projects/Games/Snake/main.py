import pygame

# Variables ---------------------------------------------------------------------- #
SCREEN_X_SIZE = 1300
SCREEN_Y_SIZE = 700

# Place snake in the middle
x_coord_snake = 650
y_coord_snake = 450
previous_x_coord_snake =  0
previous_y_coord_snake =  0

snake_in_border = False

# -- Borders -- #
left_rect_border = pygame.Rect(100, 100, 50, 500)      # Left, Top, Width, Height
right_rect_border = pygame.Rect(900, 100, 50, 500)
upper_rect_border = pygame.Rect(150, 100, 750, 50)
lower_rect_border = pygame.Rect(150, 550, 750, 50)

border_rect_list = [left_rect_border,
                    right_rect_border,
                    upper_rect_border,
                    lower_rect_border]


# Functions ---------------------------------------------------------------------- #

def updateCoords(_x_coord, _y_coord):
    keys_pressed = pygame.key.get_pressed()

    if keys_pressed[pygame.K_w]:
        print("w")
        _y_coord -= 50
    elif keys_pressed[pygame.K_a]:
        print("a")
        _x_coord -= 50
    elif keys_pressed[pygame.K_s]:
        print("s")
        _y_coord += 50
    elif keys_pressed[pygame.K_d]:
        print("d")
        _x_coord += 50

    # -- Check for Collision -- #
    snake_rect = pygame.Rect(_x_coord, _y_coord, 50, 50)
    collision_with_border = pygame.Rect.collidelist(snake_rect, border_rect_list)

    if collision_with_border != -1:
        _x_coord = previous_x_coord_snake
        _y_coord = previous_y_coord_snake
        print(f"Border!!")

    snake_rect = pygame.Rect(_x_coord, _y_coord, 50, 50)

    return snake_rect, _x_coord, _y_coord


def drawField(snake_rect):
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
    pygame.draw.rect(screen, "seagreen4", snake_rect) 



def checkCollision(snake_rect, x_coord_snake, y_coord_snake):
    collision_with_border = pygame.Rect.collidelist(snake_rect, border_rect_list)

    if collision_with_border != -1:
        x_coord_snake = previous_x_coord_snake
        y_coord_snake = previous_y_coord_snake
        print(f"Border!!")

    return x_coord_snake, y_coord_snake



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
        snake_rect, x_coord_snake, y_coord_snake = updateCoords(x_coord_snake, y_coord_snake)

        previous_x_coord_snake = x_coord_snake
        previous_y_coord_snake = y_coord_snake
        
        drawField(snake_rect)


        # if collision != -1:
        #     print("Border")
        # snake_in_border = pygame.Rect.colliderect(border_rect, snake_rect)
        
        # Plot on screen
        pygame.display.flip()


        clock.tick(5)  # limits FPS to 60

    pygame.quit()