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
        if (row_even) { // Even rows
            for (uint8_t k = 0; k < 11; k++) {
                if (k == 10) {
                    printf("\n");
                    row_even = false;
                    continue;
                }
                printf("%3d  ", board[i - k]);
            }
        } else {    // Odd rows
            for (int8_t k = 9; k > -1; k--) {
                if (k == 0) {
                    printf("%3d  ", board[i]);
                    printf("\n");
                    row_even = true;
                    continue;
                }
                if (i == 10) {
                    printf("%3d  ", board[i - k]);
                    continue;
                }
                printf("%3d  ", board[i - k]);
            }
        }
    }


}












int main(void) {

    initBoard();


    return 0;
}
