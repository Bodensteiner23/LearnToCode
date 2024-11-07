import pygame


def updatePosition(_x_coord, _y_coord):
    keys_pressed = pygame.key.get_pressed()

    if keys_pressed[pygame.K_w]:
        print("w")
        _y_coord -= 10
    if keys_pressed[pygame.K_a]:
        print("a")
        _x_coord -= 10

    if keys_pressed[pygame.K_s]:
        print("s")
        _y_coord += 10

    if keys_pressed[pygame.K_d]:
        print("d")
        _x_coord += 10

    return _x_coord, _y_coord



def main():
    x_coord = 640
    y_coord = 360

    # Init Modul
    pygame.init()
    screen = pygame.display.set_mode((1280, 720))
    clock = pygame.time.Clock()
    running = True


    while running:
        # poll for events
        # pygame.QUIT event means the user clicked X to close your window
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
        
        screen.fill("#d3b4d4")

        # RENDER YOUR GAME HERE
        x_coord, y_coord = updatePosition(x_coord, y_coord)
        
        pygame.draw.circle(screen, "#254545", (x_coord, y_coord), 100, 0)
        
        # Plot on screen
        pygame.display.flip()

        clock.tick(60)  # limits FPS to 60

    pygame.quit()


if __name__ == "__main__":

    main()