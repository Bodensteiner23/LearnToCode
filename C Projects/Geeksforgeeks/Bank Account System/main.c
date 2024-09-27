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
#include <ctype.h>


/* ================================ Structs ================================= */

/**
 * @brief   Struct containing data from processed user
 */
typedef struct {
    char first_name[50];
    char last_name[50];
    char password[50];
} login_data_t;

/* ================================ Enums =================================== */

/**
 * @brief   Enum containing all possible states of user data
 */
enum Checks {
    NOT_CHECKED,
    PASSWORD_CHECKED,
    NO_VALID_USER, 
    VALID_USER, 
    WRONG_LOGIN_DATA
};

/* =============================== Variables ================================ */

FILE * pFile;

/* ========================= Function Declarations ========================== */

void console_goToXY(uint8_t x, uint8_t y);
void console_clearScreen(void);
void console_startingScreen(void);
void console_accountCreation(void);
void console_getFirstName(login_data_t *_new_person);
void console_getLastName(login_data_t *_new_person);
void console_getPassword(login_data_t *_new_person);
bool console_isValidName(char buffer[50]);
void console_loginUser(void);

void main_getPassword(char *_password);
void main_storeData(login_data_t _new_person);
void main_initDatabase(void);
bool main_checkValidUser(login_data_t *_user_to_check, bool _login);
uint8_t main_createAccount(void);
int main_startMenu(void);


/* ================================ Console ================================= */

/**
 * @brief   Navigate in console
 * 
 * @param x: x - position
 * @param y: y - position
 */
void console_goToXY(uint8_t x, uint8_t y) {
    COORD c;
    c.X = x;
    c.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

/**
 * @brief   Clear console screen
 */
void console_clearScreen(void) {
    system("cls");
}

/**
 * @brief   Plot start menu
 */
void console_startingScreen(void) {
    console_goToXY(2, 0);
    printf("******************************");
    console_goToXY(10, 1);
    printf("Banking System");
    console_goToXY(2, 2);
    printf("******************************");

    console_goToXY(6, 4);
    printf("1... Create Account");
    console_goToXY(6, 5);
    printf("2... Login");
}

/**
 * @brief   Plot account creation menu  
 */
void console_accountCreation(void) {
    console_clearScreen();
    console_goToXY(2, 0);
    printf("******************************");
    console_goToXY(9, 1);
    printf("Account Creation");
    console_goToXY(2, 2);
    printf("******************************");
}


void console_loginUser(void) {
    console_clearScreen();
    console_goToXY(2, 0);
    printf("******************************");
    console_goToXY(14, 1);
    printf("Login");
    console_goToXY(2, 2);
    printf("******************************");
}

/**
 * @brief   Get first name of console
 * 
 * @param _new_person: New person 
 */
void console_getFirstName(login_data_t *_new_person) {
    char buffer[50];
    bool valid = true;
    // ToDo: Only allow one word
    do {
        console_goToXY(6, 4);
        printf("First name: ");
        for (uint8_t i = 0; i < 50; i++) {
            printf(" ");
        }
        console_goToXY(18, 4);
        scanf("%s", buffer);
        valid = console_isValidName(buffer);

        if (valid) {
            strcpy(_new_person->first_name, buffer);
        }
    } while (valid != true);
}

/**
 * @brief   Get last name of console
 * 
 * @param _new_person: New person
 */
void console_getLastName(login_data_t *_new_person) {
    char buffer[50];
    bool valid = true;
    // ToDo: Only allow one word
    do {
        console_goToXY(6, 5);
        printf("Last name : ");
        for (uint8_t i = 0; i < 50; i++) {
            printf(" ");
        }
        console_goToXY(18, 5);
        scanf("%s", buffer);
        valid = console_isValidName(buffer);

        if (valid) {
            strcpy(_new_person->last_name, buffer);
        }
    } while (valid != true);
}

/**
 * @brief   Get password of console
 * 
 * @param _new_person: New peron
 */
void console_getPassword(login_data_t *_new_person) {

    console_goToXY(6, 6);
    printf("Password  : "); 
    main_getPassword(_new_person->password);
}

/**
 * @brief   Check if first/last name input is valid and contains only letters
 * 
 * @param buffer: Buffer with name to check 
 * 
 * @return false -> Not valid. Name contains letters
 */
bool console_isValidName(char buffer[50]) {

    for (uint8_t i = 0; i < strlen(buffer); i++) {
        if ((isalpha(buffer[i]) == 0)) {
            return false;
        } 
    }
    return true;
}
/* ============================== Application =============================== */

/**
 * @brief   Get User choice in starting menu
 * 
 * @return  User choice in start menu 
 */
int main_startMenu(void) {
    console_startingScreen();

    int user_input; 
    console_goToXY(1, 7);
    scanf("%d", &user_input);

    return user_input;
}


/**
 * @brief   Add a new user to the database
 */
uint8_t main_createAccount(void) {
    login_data_t new_person = {0};
    bool valid_user = false;
    
    while (valid_user == false) {
        console_accountCreation();
        
        console_getFirstName(&new_person);
        console_getLastName(&new_person);

        valid_user = main_checkValidUser(&new_person, false);

        if (valid_user == false) {
            char user_input;
            printf("User already exists! Try again? (y / n): ");
            scanf(" %c", &user_input);

            if (user_input == 'y') {
                console_clearScreen();
                continue;       // User trys to input new data
            } else if (user_input == 'n') {
                return 1;   // Back to main menu
            }
        }
    }
    console_getPassword(&new_person);

    main_storeData(new_person);

    return 0;
}


/**
 * @brief   Check if user already exists in database or if login data is valid   
 * 
 * @param _user_to_check: User Data
 * @param _login: true -> Also check password; false -> Only check first/last name
 * 
 * @return false -> Wrong login Data / User already exists in database
 */
bool main_checkValidUser(login_data_t *_user_to_check, bool _login) {
    pFile = fopen("Output/Login Data.csv", "r");  
    enum Checks Check_User = NOT_CHECKED; 
    char row[1024];
    char *tok;
    bool finished_iterations = false;

    // ToDo Program crasht wenn First name eingegeben wird. Vermutlich einfach keine Leerzeichen zulassen
    while (fgets(row, sizeof(row), pFile) != NULL) {
        tok = strtok(row, ",");

        while ((tok != NULL) && (finished_iterations == false)) {

            if (strncmp(tok, _user_to_check->first_name, 
                    strlen(_user_to_check->first_name)) == 0 ) {
                tok = strtok(NULL, ","); 

                if (strncmp(tok, _user_to_check->last_name,
                        strlen(_user_to_check->last_name)) == 0) {
                
                    if (_login == true) {

                        if (strncmp(tok, _user_to_check->password,
                                strlen(_user_to_check->password)) == 0) {
                            
                            Check_User = PASSWORD_CHECKED;
                            finished_iterations = true;
                        } else {
                            Check_User = WRONG_LOGIN_DATA;
                            finished_iterations = true;
                        }

                    } else {
                        Check_User = NO_VALID_USER;
                        finished_iterations = true;
                        break;
                    }
                } else {
                    Check_User = NOT_CHECKED;
                    break;
                }
            } else {
                Check_User = NOT_CHECKED;
                break;
            }
        }
    }
    fclose(pFile);

    if ((Check_User == WRONG_LOGIN_DATA) || (Check_User == NO_VALID_USER)) {
        return false;
    }

    return true;
}


/**
 * @brief   Get password and check if it is valid and strong enough 
 * 
 * @param _password: Password to check 
 */
void main_getPassword(char *_password) {
    // ToDo: Passwort auf Stärke und Gültigkeit prüfen
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


/**
 * @brief   Store new user in database
 * 
 * @param _new_person: Data from new person 
 */
void main_storeData(login_data_t _new_person) {

    pFile = fopen("Output/Login Data.csv", "a");
    
    if (pFile != NULL) {
        fputs(_new_person.first_name, pFile);
        fprintf(pFile, ",");
        fputs(_new_person.last_name, pFile);
        fprintf(pFile, ",");
        fputs(_new_person.password, pFile);
        fprintf(pFile, ",\n");
    }
    fclose(pFile);
}


/**
 * @brief   Init first rows of Database 
 */
void main_initDatabase(void) {
    pFile = fopen("Output/Login Data.csv", "w");
    if (pFile != NULL) {
        fprintf(pFile,
        "First name,Last name,Password,\n");
    }
    fclose(pFile);
}


void main_loginUser(login_data_t *_working_user) {

    login_data_t *working_user = _working_user;


    console_loginUser();
    while (1) {

    }



}


int main(void) {
    main_initDatabase();

    login_data_t working_user = {0};

    int user_input = 0;
    
    while (1) {
        console_clearScreen();
        user_input = main_startMenu();

        if (user_input == 1) {
            main_createAccount();
            user_input = 0;
        } else if (user_input == 2) {
            // ToDo: Login. Hier working user zuweisen
            main_loginUser(&working_user);
        }

    }
    return 0;
}