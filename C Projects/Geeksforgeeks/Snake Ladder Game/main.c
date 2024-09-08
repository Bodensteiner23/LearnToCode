/***
 *  ToDo: 
 *  - Checken ob Position nach Würfeln gleich sind. Wenn ja -> Spieler wird geschmissen und fängt wieder bei 0 an.
 *  - Leitern einfügen. Dies sollte auch in einer Funktion außerhalb der drawBoard passieren.
 *  
 */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#define PLAYER_1    0
#define PLAYER_2    1

void drawBoard(uint8_t _player_positions[2]) {
    uint8_t board[101];
    uint8_t position_player_1 = _player_positions[0];
    uint8_t position_player_2 = _player_positions[1];
    bool row_even = true;

    for (uint8_t i = 1; i < 101; i++) {
        board[i] = i;
    }
    
    for (uint8_t i = 100; i > 0; i -= 10){
        if (row_even) {     // Even rows
            for (uint8_t k = 0; k < 10; k++) {
                uint8_t pos = board[i - k];
                if (position_player_1 == pos) {
                    printf("#P1  ");
                } else if (position_player_2 == pos) {
                    printf("#P2  ");
                } else {
                    printf("%3d  ", pos);
                }
            }
                printf("\n");
                row_even = false;
        } else {            // Odd rows
            for (int8_t k = 9; k > -1; k--) {
                uint8_t pos = board[i - k];
                if (position_player_1 == pos) {
                    printf("#P1  ");
                } else if (position_player_2 == pos) {
                    printf("#P2  ");
                } else {
                    printf("%3d  ", pos);
                }
            }
                printf("\n");
                row_even = true;
        }
    }
}


uint8_t randomNumber(void) {
    uint8_t  random_number = (rand() % (6 + 1 - 1) + 1);

    return random_number;
}


uint8_t rollTheDice(uint8_t _player) {
    uint8_t dice_number;
    char msg[100];

    printf("\n\nPlayer %d rolls the dice. Type Enter!", _player + 1);
    if (fgets(msg, sizeof(msg), stdin)) {
        dice_number = randomNumber();
    }

    return dice_number;
}


void updatePlayerPosition(uint8_t _player_positions[2], uint8_t _playersTurn) {
    uint8_t snakes_and_ladders[101];
    
    for (uint8_t i = 0; i < 100; i++) {
        snakes_and_ladders[i] = 0;
    }

    snakes_and_ladders[6] = 10;
    snakes_and_ladders[9] = 22;
    snakes_and_ladders[63] = -45;
    snakes_and_ladders[80] = 19;
    
    _player_positions[_playersTurn] = _player_positions[_playersTurn] + rollTheDice(_playersTurn);

    _player_positions[_playersTurn] = _player_positions[_playersTurn] + snakes_and_ladders[_player_positions[_playersTurn]];

    if (_player_positions[PLAYER_1] == _player_positions[PLAYER_2]) {
        if (_playersTurn == PLAYER_1) {
            _player_positions[PLAYER_2] = 1;
        } else {
            _player_positions[PLAYER_1] = 1;
        }
    }
}





int main(void) {
    uint8_t player_positions[2] = {0, 0};

    while (1) {
        updatePlayerPosition(player_positions, PLAYER_1);
        drawBoard(player_positions);
        updatePlayerPosition(player_positions, PLAYER_2);
        drawBoard(player_positions);

    }

    return 0;
}

