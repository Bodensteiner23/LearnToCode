import pygame

# Variables ---------------------------------------------------------------------- #

SCREEN_X_SIZE = 1300
SCREEN_Y_SIZE = 700

# Place snake in the middle
x_coord_snake = 650
y_coord_snake = 450

snake_in_border = False

# Snake Class -------------------------------------------------------------------- #

class Snake:
    def __init__(self):
        self.x_pos = 0
        self.y_pos = 0
        

    def updatePosition(self, _x_coord, _y_coord):
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

        return _x_coord, _y_coord


class Field:
    def __init__(self):
        pass

    def drawField(self, screen):
        # outer_rect = pygame.draw.rect(self.screen, "darkgray", (100, 100, 1300, 800), 40)

        # -- Borders -- #
        left_rect_border = pygame.draw.rect(screen, "darkgray", (100, 100, 50, 800))
        right_rect_border = pygame.draw.rect(screen, "darkgray", (1300, 100, 50, 800))
        upper_rect_border = pygame.draw.rect(screen, "darkgray", (100, 100, 800, 50))
        lower_rect_border = pygame.draw.rect(screen, "darkgray", (100, 800, 1300, 100))
        
        
        

        heading_screen = heading_font.render("Score: ", False, "black")
        screen.blit(heading_screen, (20, 10))
        score_screen = score_font.render("10", False, "black")
        screen.blit(score_screen, (190, 10))
        snake_rect = pygame.draw.rect(screen, "seagreen4", (x_coord_snake, y_coord_snake, 50, 50))


# Main Loop ---------------------------------------------------------------------- #

# -- Init Module -- #
snake = Snake()
field = Field()

pygame.init()
pygame.display.set_caption("Snake")

screen = pygame.display.set_mode((SCREEN_X_SIZE, SCREEN_Y_SIZE))
heading_font = pygame.font.SysFont("Comic Sans MS", 50)
score_font = pygame.font.SysFont("Comic Sans MS", 50)

clock = pygame.time.Clock()
running = True

# -- Main Loop -- #
while running:
    # poll for events
    # pygame.QUIT event means the user clicked X to close your window
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
    
    screen.fill("plum2")

    # RENDER YOUR GAME HERE
    x_coord_snake, y_coord_snake = snake.updatePosition(x_coord_snake, y_coord_snake)

    field.drawField(screen)
    
    # ToDo: Many of them must be removed, because they don't need to be rendered all the time
    # snake_in_border = pygame.Rect.colliderect(border_rect, snake_rect)
    
    # Plot on screen
    pygame.display.flip()

    clock.tick(5)  # limits FPS to 60

pygame.quit()

