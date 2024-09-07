#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

void initBoard(void) {
    uint8_t board[101];
    bool row_even = true;

    for (uint8_t i = 1; i < 101; i++) {
        board[i] = i;
    }
    
    for (uint8_t i = 100; i > 0; i -= 10){
        if (row_even) {     // Even rows
            for (uint8_t k = 0; k < 10; k++) {
                printf("%3d  ", board[i - k]);
            }
                printf("\n");
                row_even = false;
        } else {            // Odd rows
            for (int8_t k = 9; k > -1; k--) {
                printf("%3d  ", board[i - k]);
            }
                printf("\n");
                row_even = true;
        }
    }
}



int main(void) {

    initBoard();


    return 0;
}
