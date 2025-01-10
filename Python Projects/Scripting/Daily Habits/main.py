import json
 

def processCurrentHabbits(_data):
    current_habbits = _data["habbits"]
    if current_habbits:
        print("Your current habbits are as follows: ", end="")
        for i in range(0, len(current_habbits)):
            if i == (len(current_habbits) - 1):
                print(current_habbits[i])
            else:
                print(current_habbits[i], end=" ,")
    else:
        user_input = input("You have no habbits at the moment. Do you want to add them? (y/n): ")
        if user_input == "n":
            return False
        elif user_input == "y":
            addHabbit(_data)




def addHabbit(_data):

    user_input = input("Input habit: ")
    



def main():

    with open('data.json') as f:
        data = json.load(f)

    processCurrentHabbits(data)





    with open("data.json", "w") as f:
        json.dump(data, f, indent=4)

main()
