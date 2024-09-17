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
/* ================================ Includes ================================ */
#include <stdint.h>
#include <windows.h>
#include <stdio.h>
#include <unistd.h>
#include <conio.h>
#include <stdbool.h>

/* ================================ Structs ================================= */
typedef struct {
    char first_name[50];
    char last_name[50];
    char passwort[50];
} login_data_t;


/* ========================= Function Declarations ========================== */
void getPassword(char *_password);
void storeData(login_data_t _new_person);
bool checkValidUser(login_data_t _user_to_check);


/* =============================== Variables ================================ */
FILE * pFile;


/* ============================== Application =============================== */
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

/***
 *  ToDo:
 *  - Checken ob der Nutzer schon existiert und falls nicht hinzufügen.
 ***/
uint8_t createAccount(void) {
    login_data_t new_person;
    char buffer[50];
    bool valid_user = false;


    clearScreen();
    goToXY(2, 0);
    printf("******************************");
    goToXY(9, 1);
    printf("Account Creation");
    goToXY(2, 2);
    printf("******************************");
    
    while (valid_user == false) {
        goToXY(6, 4);
        printf("First name: ");
        scanf("%s", buffer);
        strcpy(new_person.first_name, buffer);
        
        goToXY(6, 5);
        printf("Last name : ");
        scanf("%s", buffer);
        strcpy(new_person.last_name, buffer);
        
        valid_user = true;
        // valid_user = checkValidUser(new_person);
        // Clear Screen after that
    }
    // ToDo: Hier muss gecheckt werden ob Nutzer schon existiert

    goToXY(6, 6);
    printf("Password  : ");
    getPassword(new_person.passwort);

    storeData(new_person);
    valid_user = checkValidUser(new_person);

    return 0;
}

bool checkValidUser(login_data_t _user_to_check) {
    pFile = fopen("Login Data.csv", "r");  
    char line[1024];
    uint8_t check_valid_user[3];

    while (fgets(line, 1024, pFile) != NULL) {


    }
    fclose(pFile);


    return true;
}


/***
 *  ToDo:
 *  - Passwort auf Stärke und Gültigkeit prüfen
 ***/
void getPassword(char *_password) {
    int user_input = 0;
    uint8_t i = 0;

    // Clear the input buffer
    while ((user_input = getchar()) != '\n');
    
    while (1) {
        user_input = getch();
        if (user_input == '\r') {           // Enter
            break;
        } else if (user_input == '\b') {    // Backspace 
            if (i > 0) {
                i--;
            printf("\b \b");
            }
        } else if (i < 10) {
            _password[i++] = user_input;
            printf("*");
        } 
    }
    _password[i] = '\0';
}


void storeData(login_data_t _new_person) {

    pFile = fopen("Login Data.csv", "a");
    
    if (pFile != NULL) {
        fputs(_new_person.first_name, pFile);
        fprintf(pFile, ",");
        fputs(_new_person.last_name, pFile);
        fprintf(pFile, ",");
        fputs(_new_person.passwort, pFile);
        fprintf(pFile, ",\n");
    }
    fclose(pFile);
}


void initDatabase(void) {
    pFile = fopen("Login Data.csv", "w");
    if (pFile != NULL) {
        fprintf(pFile,
        "First name, Last name, Password,\n");
    }
    fclose(pFile);
}


int main(void) {
    setbuf(stdout, 0);      // Clear Buffer for debug reason
    initDatabase();

    int user_input = 0;

    clearScreen();
    user_input = startingScreen();

    if (user_input == 1) {
        createAccount();
    }
    return 0;
}