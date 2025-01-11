import json
 

def processCurrentHabbits(_data):
    current_habbits = _data["habbits"]
    valid_input = False
    if current_habbits:
        print("Your current habbits are as follows: ", end="")
        for i in range(0, len(current_habbits)):
            if i == (len(current_habbits) - 1):
                print(current_habbits[i])
            else:
                print(current_habbits[i], end=" ,")
    else:
        while valid_input == False:
            user_input = input("You have no habbits at the moment. Do you want to add them? (y/n): ")
            if not checkValidInput(user_input):
                continue
            elif user_input == "n":
                valid_input = True
                return _data
            elif user_input == "y":
                valid_input = True
                _data = addHabbit(_data)

    return _data


def addHabbit(_data):
    _data["habbits"].append(input("Input habit: "))

    no_more_habbit = False
    while no_more_habbit == False:
        user_input = input("Do you want to add another habit? (y/n): ")
        if not checkValidInput(user_input):
            continue
        if user_input == "n":
            no_more_habbit = True
        elif user_input == "y":
            _data["habbits"].append(input("Input habit: "))
            no_more_habbit = False

    return _data

def checkValidInput(_user_input):
    if _user_input == "y" or _user_input == "n":
        return True
    print("Invalid input. Try again.")
    return False


def main():

    with open('data.json') as f:
        data = json.load(f)

    data = processCurrentHabbits(data)





    with open("data.json", "w") as f:
        json.dump(data, f, indent=4)

main()
