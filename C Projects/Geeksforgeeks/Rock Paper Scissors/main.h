#ifndef MAIN_H
#define MAIN_H

const char* convertInput(char _player_turn);

uint8_t convertInputToInt( const char* _input);
uint8_t calculateTheWinner(uint8_t _player_int, uint8_t _bot_int);

bool validInput(char _user_input);

void plotScore(uint8_t _points_player, uint8_t _points_bot);

#endif //MAIN_H
