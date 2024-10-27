#include "ncurses/ncurses.h"

int main(void)
{
    // Initialize the screen
    initscr();

    // Print "Hello, World!" to the screen
    printw("tete!");

    // Refresh the screen to show the message
    refresh();

    // Wait for user input
    getch();

    // End ncurses mode
    endwin();

    return 0;
}