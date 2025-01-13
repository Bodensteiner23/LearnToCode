import json
import os
 

def processCurrentHabbits(_data):
    current_habbits = _data["habbits"]
    happy_user = False
    valid_input = False
    add_or_remove = False
    while happy_user == False:
        if current_habbits:
            printCurrentHabbits(current_habbits)
        else:
            _data = checkForAddHabbit(_data)
        
        valid_input = False
        user_input = input("Do you want to add or remove habbits? (y/n): ")

        while valid_input == False:
            if not checkValidInput(user_input, "yn"):
                continue
            elif user_input == "y":
                valid_input = True
                add_or_remove = True
            elif user_input == "n":
                valid_input = True
                add_or_remove = False
        
        if add_or_remove == True:
            user_input = input("Add or remove? (a/r): ")
            if not checkValidInput(user_input, "ar"):
                continue
            elif user_input == "a":
                _data = addHabbit(_data)
            elif user_input == "r":
                _data = removeHabbit(_data)



    return _data


def checkForAddHabbit(_data):
    valid_input = False
    while valid_input == False:
        user_input = input("You have no habbits at the moment. Do you want to add them? (y/n): ")
        if not checkValidInput(user_input, "yn"):
            continue
        elif user_input == "n":
            valid_input = True
            break
        elif user_input == "y":
            valid_input = True
            _data = addHabbit(_data)

    return _data
    

def addHabbit(_data):
    _data["habbits"].append(input("Input habit: "))

    no_more_habbit = False
    while no_more_habbit == False:
        user_input = input("Do you want to add another habit? (y/n): ")
        if not checkValidInput(user_input, "yn"):
            continue
        if user_input == "n":
            no_more_habbit = True
        elif user_input == "y":
            _data["habbits"].append(input("Input habit: "))
            no_more_habbit = False
    
    current_habbits = _data["habbits"]
    printCurrentHabbits(current_habbits)

    return _data

def removeHabbit(_data):
    print("Ich entferne")


def checkValidInput(_user_input, _checkString):
    if (_user_input == "y" or _user_input == "n") and _checkString == "yn":
        return True
    elif ((_user_input == "a" or _user_input == "r") and _checkString == "ar"):
        return True
    print("Invalid input. Try again.")
    return False


def printCurrentHabbits(_current_habbits):
    working = True
    print("Your current habbits are as follows: ", end="")
    while working == True:
        if _current_habbits:
            for i in range(0, len(_current_habbits)):
                if i == (len(_current_habbits) - 1):
                    print(_current_habbits[i])
                else:
                    print(_current_habbits[i], end=" ,")
        else:
            print("\nNo habbits defined!")
        user_input = input("Go back? (y): ")
        if user_input == "y":
            working = False


def processHabbits(_data):
    working = True
    while working == True:
        print("")
# Menus --------------------------------------------------------------------- #
def openHabbitMenu():
    with open('data.json') as f:
        data = json.load(f)
    while True:
        os.system("cls")
        print("Daily Habbit Menu")
        print("1. Show Habbits")
        print("2. Add Habbits")
        print("3. Remove Habbits")
        print("4. Exit Menu")
        user_input = input("Choose an option: ")
        
        while user_input != "4":
            os.system("cls")
            if user_input == "1":
                printCurrentHabbits(data["habbits"])
                break
            elif user_input == "2":
                pass
            elif user_input == "3":
                pass
            else:
                print("Invalid Input")


def openDailyVlogMenu():

    pass

def main():
    working = True
    # with open('data.json') as f:
    #     data = json.load(f)
    while True:
        os.system("cls")
        print("Main Menu")
        print("1. Habbits")
        print("2. DailyVlog")
    	
        user_input = input("Choose an option: ")
        
        if user_input == "1":
            openHabbitMenu()
        elif user_input == "2":
            openDailyVlogMenu()
        else:
            print("Invalid Input")

    # with open("data.json", "w") as f:
    #     json.dump(data, f, indent=4)

    


main()
