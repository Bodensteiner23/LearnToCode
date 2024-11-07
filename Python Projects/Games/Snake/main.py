import pygame






    




def main():
    x_coord = 640
    y_coord = 360

    # pygame setup
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
        
        keys_pressed = pygame.key.get_pressed()

        if keys_pressed[pygame.K_w]:
            print("w")
            y_coord -= 10
        if keys_pressed[pygame.K_a]:
            print("a")
            x_coord -= 10

        if keys_pressed[pygame.K_s]:
            print("s")
            y_coord += 10

        if keys_pressed[pygame.K_d]:
            print("d")
            x_coord += 10

        print(f"x: {x_coord}")
        print(f"y: {y_coord}")

        # fill the screen with a color to wipe away anything from last frame
        screen.fill("#d3b4d4")

        # RENDER YOUR GAME HERE
        
        pygame.draw.circle(screen, "#254545", (x_coord, y_coord), 100, 0)

                

        
        # flip() the display to put your work on screen
        pygame.display.flip()

        clock.tick(60)  # limits FPS to 60

    pygame.quit()




if __name__ == "__main__":

    main()