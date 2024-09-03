#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

const char valid_inputs[] = {'r', 'p', 's'};
const char* game_inputs[] = {"Rock", "Paper", "Scissor"};


void gameLoop(void) {

    uint8_t points_player = 0;
    uint8_t points_bot = 0;

    while ((points_player != 3) && (points_bot != 3)) {

        char player_input = 0;
        printf("Pick your symbol (r,p,s): ");
        fflush(stdout);
        player_input = getchar();
        getchar();      // Handle enter key input
        const char* player_turn_string = convertInput(player_input);
        uint8_t player_turn_int = convertInputToInt(player_turn_string);

        if (validInput(player_input) != true) {
            printf("Your input was not correct. Try again.\n");
            fflush(stdout);
            continue;
        }

        // Get random number of for bot turn
        const char* bot_turn_string = game_inputs[rand() % 3];
        uint8_t bot_turn_int = convertInputToInt(bot_turn_string);
        printf("Bot picked: %s\n", bot_turn_string);
        fflush(stdout);

        // Calculate winner
        uint8_t winner = calculateTheWinner(player_turn_int, bot_turn_int);

        if (winner == 0) {
            printf("Draw. Try again.");
        } else if (winner == 1) {
            printf("Player wins!");
        } else {
            printf("Bot wins!");
        } 

        
        printf("%s vs %s --> %s wins!\n", player_turn_string, bot_turn_string, winner);
    }
}


bool validInput(char _player_turn) {

    for (uint8_t i = 0; i < 3; i++) {
        if (_player_turn == valid_inputs[i]) {
            return true;
        }
    }
    return false;
}


const char* convertInput(char _player_input) {
    const char* converted_input = 0;
    if (_player_input == 'r') {
        converted_input = game_inputs[0];
    } else if (_player_input == 'p') {
        converted_input = game_inputs[1];
    } else if (_player_input == 's') {
        converted_input = game_inputs[2];
    }
    
    return converted_input;
}

uint8_t convertInputToInt( const char* _input) {
    uint8_t input_integer = 0;
    if (_input == "Rock") {
        return 1;
    } else if (_input == "Paper") {
        return 2;
    } else {
        return 3;
    }
}


uint8_t calculateTheWinner(uint8_t _player_int, uint8_t _bot_int) {
    // 1 == Rock, 2 == Paper, 3 == Scissor
    // Return 0: Draw
    // Return 1: Player wins
    // Return 2: Bot wins
    if (_player_int == _bot_int) {
        return 0;
    } else if ((_player_int == 1) && (_bot_int == 2)) {     // Rock vs Paper
        return 2;
    } else if ((_player_int == 1) && (_bot_int == 3)) {     // Rock vs Scissor
        return 1;
    } else if ((_player_int == 2) && (_bot_int == 1)) {     // Paper vs Rock
        return 1;
    } else if ((_player_int == 2) && (_bot_int == 3)) {     // Paper vs Scissor
        return 2;
    } else if ((_player_int == 3) && (_bot_int == 1)) {     // Scissor vs Rock
        return 2;
    } else if ((_player_int == 3) && (_bot_int == 2)) {     // Scissor vs Paper
        return 1;
    } 
    
}



int main(void) {

    printf("##########################################\n"
    "           Rock Paper Sciccors\n"
    "##########################################\n");
    fflush(stdout);

    gameLoop();


    return 0;
}


