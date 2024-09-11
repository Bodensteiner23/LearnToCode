/***
 *  ToDo:
 *  Programm erstellen das:
 *  - Nutzer soll sich einloggen können / Account erstellen können. Hierbei prüfen ob
 *      -> Der Nutzer schon einen Account hat
 *      -> Passwort stark genug ist. Ist quasi noch ein Passwort Prüfer integriert
 *  - Nutzer soll Geld auf sein Konto einzahlen können, wenn er eingeloggt ist
 *  - Nutzer soll seinen Kontostand prüfen können
 *  - Nutzer soll Geld an einen anderen Nutzer überweisen können. Hierbei auch prüfen ob die Person existiert und
 *  richtig geschrieben wurde
 ***/
#include <stdint.h>
#include <windows.h>
#include <stdio.h>
#include <unistd.h>

typedef struct {
    char first_name[50];
    char last_name[50];
    char passwort[50];
} login_data_t;


char getPassword(char *_password);

void goToXY(uint8_t x, uint8_t y) {
    COORD c;
    c.X = x;
    c.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void clearScreen() {
    system("cls");
}


int startingScreen(void) {
    goToXY(2, 0);
    printf("******************************");
    goToXY(10, 1);
    printf("Banking System");
    goToXY(2, 2);
    printf("******************************");

    goToXY(6, 4);
    printf("1... Create Account");
    goToXY(6, 5);
    printf("2... Login");

    int user_input; 
    goToXY(1, 7);
    scanf("%d", &user_input);

    return user_input;
}


uint8_t createAccount(void) {
    login_data_t new_person;
    char buffer[50];

    clearScreen();
    goToXY(2, 0);
    printf("******************************");
    goToXY(9, 1);
    printf("Account Creation");
    goToXY(2, 2);
    printf("******************************");
    
    goToXY(6, 4);
    printf("First name: ");
    scanf("%s", buffer);
    strcpy(new_person.first_name, buffer);
    
    goToXY(6, 5);
    printf("Last name : ");
    scanf("%s", buffer);
    strcpy(new_person.last_name, buffer);

    getPassword(new_person.passwort);

    return 0;
 
}


char getPassword(char *_password) {
    int c = 0;
    uint8_t i = 0;

    // Clear the input buffer
    while ((c = getchar()) != '\n');
    
    goToXY(6, 6);
    printf("Password  : ");
    
    while ((c = getchar()) != '\n' ) {
        if (c == 10) {          // Enter
            break;
        } else if (c == 8) {    // Backspace
            printf("\b\b");
        } else {
            _password[i++] = c;
        } 

    }

    printf(_password);

    return 0;

}

int main(void) {
    setbuf(stdout, 0);

    int user_input = 0;
    // uint8_t operation = 0;

    clearScreen();
    user_input = startingScreen();

    if (user_input == 1) {
        createAccount();
    }
    return 0;
}