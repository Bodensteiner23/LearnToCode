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
 * 
 * 
 *  ToRework:
 *  Aktuell funktioniert das csv parsen nicht. Wenn man Geld einzahlt, dann wird es nicht in der .csv Datei geupdated.
 *  Man muss reworken, dass man zum Beispiel aus der csv Datei alle Nutzer ausliest und sich dann mit Name 
 *  die richtigen zusammen sucht. Wird aber wohl nochmal ein großer Rework von dem ganzem Program.
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
    int32_t balance;
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
    WRONG_LOGIN_DATA,
    USER_NOT_EXISTING, 
    WORKING_USER
};

/* =============================== Variables ================================ */

FILE * pFile;

/* ========================= Function Declarations ========================== */

void console_goToXY(uint8_t x, uint8_t y);
void console_clearScreen(void);
void console_startingScreen(login_data_t _working_user);
void console_accountCreation(void);
void console_getFirstName(login_data_t *_new_person);
void console_getLastName(login_data_t *_new_person);
void console_getPassword(login_data_t *_new_person);
bool console_isValidName(char buffer[50]);
void console_loginUser(void);
void console_showWorkingUser(login_data_t  *_working_user);
void console_showDeposit(void);

void main_getPassword(char *_password);
void main_storeData(login_data_t _new_person);
void main_initDatabase(void);
enum Checks main_checkValidUser(login_data_t *_user_to_check, bool _login);
uint8_t main_createAccount(void);
uint8_t main_loginUser(login_data_t *_working_user);
int main_startMenu(login_data_t _working_user);


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
void console_startingScreen(login_data_t _working_user) {
    console_goToXY(2, 0);
    printf("******************************");
    console_goToXY(10, 1);
    printf("Banking System");
    console_goToXY(2, 2);
    printf("******************************");

    console_goToXY(6, 4);
    if (_working_user.first_name[0] == 0) {
        printf("1... Login");
    } else {
        printf("1... Logout");
    } 
    console_goToXY(6, 5);
    printf("2... Transfer");
    console_goToXY(6, 6);
    printf("3... Deposit/Withdraw");
    console_goToXY(6, 7);
    printf("4... Balance");
    console_goToXY(6, 8);
    if (_working_user.first_name[0] == 0) {
        printf("5... Create Account");
    }
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

/**
 * @brief   Plot login user menu
 * 
 */
void console_loginUser(void) {
    console_clearScreen();
    console_goToXY(2, 0);
    printf("******************************");
    console_goToXY(14, 1);
    printf("Login");
    console_goToXY(2, 2);
    printf("******************************");
}

void console_showBalance(void) {
    console_clearScreen();
    console_goToXY(2, 0);
    printf("******************************");
    console_goToXY(14, 1);
    printf("Balance");
    console_goToXY(2, 2);
    printf("******************************");
}

void console_showDeposit(void) {
    console_clearScreen();
    console_goToXY(2, 0);
    printf("******************************");
    console_goToXY(14, 1);
    printf("Deposit");
    console_goToXY(2, 2);
    printf("******************************");
}

void console_transferMoney(void) {
    console_clearScreen();
    console_goToXY(2, 0);
    printf("******************************");
    console_goToXY(14, 1);
    printf("Transfer");
    console_goToXY(2, 2);
    printf("******************************");
}


void console_showWorkingUser(login_data_t  *_working_user) {

    if (_working_user->first_name[0] != 0) {      // User is logged in
            console_goToXY(36, 1);
            printf("User: %s %s", _working_user->first_name, _working_user->last_name);
        }
}

/**
 * @brief   Get first name of console
 * 
 * @param _new_person: New person 
 */
void console_getFirstName(login_data_t *_new_person) {
    bool valid = true;
    // ToDo: Nur ein Wort erlauben
    do {
        char buffer[50];

        console_goToXY(6, 6);
        printf("First name: ");
        for (uint8_t i = 0; i < 50; i++) {
            printf(" ");
        }
        console_goToXY(18, 6);
        scanf("%s", buffer);
        valid = console_isValidName(buffer);

        if (valid) {
            strcpy(_new_person->first_name, buffer);
        } else {
            console_goToXY(18, 6);
            printf("Only Letters allowed. Press any key to try again.");
            if (getch()) {
                continue;
            }
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
        console_goToXY(6, 7);
        printf("Last name : ");
        for (uint8_t i = 0; i < 50; i++) {
            printf(" ");
        }
        console_goToXY(18, 7);
        scanf("%s", buffer);
        valid = console_isValidName(buffer);

        if (valid) {
            strcpy(_new_person->last_name, buffer);
        } else {
            console_goToXY(18, 7);
            printf("Only Letters allowed. Press any key to try again.");
            if (getch()) {
                continue;
            }
        }
    } while (valid != true);
}

/**
 * @brief   Get password of console
 * 
 * @param _new_person: New peron
 */
void console_getPassword(login_data_t *_new_person) {

    console_goToXY(6, 8);
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
int main_startMenu(login_data_t _working_user) {
    console_startingScreen(_working_user);

    int user_input = 0; 
    console_goToXY(1, 11);
    scanf("%d", &user_input);   // ToDo: Don't allow strings

    return user_input;
}


/**
 * @brief   Add a new user to the database
 */
uint8_t main_createAccount(void) {
    login_data_t new_person = {0};
    enum Checks user_state = NOT_CHECKED;
    bool valid_user = false;
    
    while (valid_user == false) {
        console_accountCreation();
        
        console_getFirstName(&new_person);
        console_getLastName(&new_person);

        user_state = main_checkValidUser(&new_person, false);

        if (user_state == NO_VALID_USER) {
            char user_input;
            printf("User already exists! Try again? (y / n): ");
            scanf(" %c", &user_input);

            if (user_input == 'y') {
                console_clearScreen();
                continue;       // User trys to input new data
            } else if (user_input == 'n') {
                return 1;       // Back to main menu
            }
        } else {
            valid_user = true;
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
 * @return  State of user
 */
enum Checks main_checkValidUser(login_data_t *_user_to_check, bool _login) {
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
                        tok = strtok(NULL, ","); 
                        
                        if (strncmp(tok, _user_to_check->password,
                                strlen(_user_to_check->password)) == 0) {
                            Check_User = PASSWORD_CHECKED;
                            tok = strtok(NULL, ",");
                            _user_to_check->balance = atoi(tok);      // Add balance to working_user
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

    return Check_User;
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
    _new_person.balance = 0;

    pFile = fopen("Output/Login Data.csv", "a");
    
    if (pFile != NULL) {
        fprintf(pFile, "%s", _new_person.first_name);
        fprintf(pFile, ",");
        fprintf(pFile, "%s", _new_person.last_name);
        fprintf(pFile, ",");
        fprintf(pFile, "%s", _new_person.password);
        fprintf(pFile, ",");
        fprintf(pFile, "%d", _new_person.balance);
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
        "asd,asd,asd,1000,\n");
    }
    fclose(pFile);
}



uint8_t main_loginUser(login_data_t *_working_user) {
    enum Checks user_input = NOT_CHECKED;

    while (user_input != PASSWORD_CHECKED) {

        console_loginUser();

        console_getFirstName(_working_user);
        console_getLastName(_working_user);
        console_getPassword(_working_user);

        user_input = main_checkValidUser(_working_user, true); 

        if (user_input != PASSWORD_CHECKED) {
            char user_input;
            printf("\nWrong login data or user does not exist! Try again? (y / n): ");
            scanf(" %c", &user_input);

            if (user_input == 'y') {
                console_clearScreen();
                continue;       // User trys to input new data
            } else if (user_input == 'n') {
                memset(_working_user, 0, sizeof(login_data_t)); 
                return 1;       // Back to main menu
            }
        }
    } 
    
    return 0;
}


void main_showBalance(login_data_t *_working_user) {
    console_showBalance();
    console_showWorkingUser(_working_user);

    console_goToXY(6, 6);
    printf("Balance: %d Euro", _working_user->balance);

    console_goToXY(1, 11);
    printf("Go back to main menu? Press any key.");

    if (getch()) {
        // Just wait for Keypress
    }

}


void main_depositMoney(login_data_t *_working_user) {
    int amount_money = 0;

    console_showDeposit();
    console_showWorkingUser(_working_user);

    console_goToXY(6, 6);
    printf("How much money you want to deposit or withdraw: ");
    scanf("%d", &amount_money);

    _working_user->balance = _working_user->balance + amount_money;

    console_goToXY(1, 11);
    printf("Go back to main menu? Press any key.");

    if (getch()) {
        // Just wait for Keypress
    }
}


uint8_t main_transferMoney(login_data_t *_working_user) {
    login_data_t transfered_user = {0};
    enum Checks user_state = NOT_CHECKED;
    bool valid_user = false;
    int transfer_money = 0;

    while(valid_user == false) {
        console_transferMoney();
        console_showWorkingUser(_working_user);

        console_goToXY(6, 4);
        printf("Enter data of user you want to transfer to");

        console_getFirstName(&transfered_user);
        console_getLastName(&transfered_user);
        
        user_state = main_checkValidUser(&transfered_user, false);
        
        if (user_state != NO_VALID_USER) {  // Confusing. User exists..
            char user_input;
            printf("User does not exist! Try again? (y / n): ");
            scanf(" %c", &user_input);

            if (user_input == 'y') {
                console_clearScreen();
                continue;       // User trys to input new data
            } else if (user_input == 'n') {
                return 1;       // Back to main menu
            }
        } else {
            valid_user = true;
        }
    }
    console_goToXY(6, 9);
    printf("Money to transfer: ");
    scanf("%d", &transfer_money);

    _working_user->balance = _working_user->balance - transfer_money;
    transfered_user.balance = transfered_user.balance + transfer_money;
    
    return 1;
}


int main(void) {
    main_initDatabase();

    login_data_t working_user = {0};

    int user_input = 0;
    
    while (1) {
        console_clearScreen();
        console_showWorkingUser(&working_user);
        user_input = main_startMenu(working_user);

        switch(user_input){
            case 1:
                if (working_user.first_name[0] == 0) {
                    main_loginUser(&working_user);
                } else {
                    memset(&working_user, 0, sizeof(login_data_t));    //Logout user
                }
                user_input = 0;
                break;
            case 2:
                if (working_user.first_name[0] == 0) {
                    console_goToXY(1, 13);
                    printf("You need to login first. Type any key to try again: ");
                    if (getch()) {
                       continue;
                    }
                } else {
                    main_transferMoney(&working_user);
                }
                user_input = 0;
                break;
            case 3:
                if (working_user.first_name[0] == 0) {
                    console_goToXY(1, 13);
                    printf("You need to login first. Type any key to try again: ");
                    if (getch()) {
                       continue;
                    }
                } else {
                    main_depositMoney(&working_user);
                }
                user_input = 0;
                break;
            case 4:
                if (working_user.first_name[0] == 0) {
                    console_goToXY(1, 13);
                    printf("You need to login first. Type any key to try again: ");
                    if (getch()) {
                       continue;
                    }
                } else {
                    main_showBalance(&working_user);
                }
                user_input = 0;
                break;
            case 5:
                main_createAccount();
                user_input = 0;
                break;    
            // ToDo: Add case to exit programm        
        }
    }

    return 0;
}