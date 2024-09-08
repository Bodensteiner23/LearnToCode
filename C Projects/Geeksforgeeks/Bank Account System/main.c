/***
 *  ToDo:
 *  Programm erstellen das:
 *  - Nutzer soll sich einloggen können / Account erstellen können. Hierbei prüfen ob
 *      -> Der Nutzer schon einen Account hat
 *  - Nutzer soll Geld auf sein Konto einzahlen können, wenn er eingeloggt ist
 *  - Nutzer soll seinen Kontostand prüfen können
 *  - Nutzer soll Geld an einen anderen Nutzer überweisen können. Hierbei auch prüfen ob die Person existiert und
 *  richtig geschrieben wurde
 ***/
#include <stdint.h>
#include <windows.h>
#include <stdio.h>
#include <unistd.h>

void goToXY(uint8_t x, uint8_t y) {
    COORD c;
    c.X = x;
    c.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void clearScreen() {
    system("cls");
}


void starting_screen(void) {

    goToXY(10, 1);
    printf("Test");



}



int main(void) {
    clearScreen();
    starting_screen();
    return 0;
}