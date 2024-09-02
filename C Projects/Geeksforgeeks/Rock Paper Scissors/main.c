#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"


void gameLoop(void) {
    char valid_inputs[] = {'r', 'p', 's'};
    const char* game_inputs[] = {"Rock", "Paper", "Scissor"};

    uint8_t points_player = 0;
    uint8_t points_bot = 0;

    while ((points_player != 3) & (points_bot != 3)) {

        char player_turn = 0;
        printf("Pick your symbol (r,p,s): ");
        fflush(stdout);
        player_turn = getchar();
        getchar();      // Handle enter key input

        if (validInput(player_turn, valid_inputs) != true) {
            printf("Your input was not correct. Try again.\n");
            fflush(stdout);
            continue;
        }

        // Get random number of for bot turn
        const char* bot_turn = game_inputs[rand() % 3];
        printf("Bot picked: %s\n", bot_turn);
        fflush(stdout);
    }
}   


bool validInput(char _player_turn, char _valid_inputs[]) {

    for (uint8_t i = 0; i < 3; i++) {
        if (_player_turn == _valid_inputs[i]) {
            return true;
        }
    }
    return false;
}

int main(void) {

    printf("##########################################\n"
    "           Rock Paper Sciccors\n"
    "##########################################\n");
    fflush(stdout);

    gameLoop();


    return 0;
}


