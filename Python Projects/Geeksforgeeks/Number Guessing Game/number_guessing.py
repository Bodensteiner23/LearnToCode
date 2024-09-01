# Build a Number guessing game, in which the user selects a range.
# Let’s say User selected a range, i.e., from A to B, where A and B belong to Integer.
# Some random integer will be selected by the system and the user has to guess that integer in the minimum number of guesses

# User selects Range from A to B
# Random Number between A and B is chosen
# User will iterate with inputs
# Player has 5 trys to get the number


import random


def generate_number_to_guess():
    range_values = [None, None]
    valid_input = False

    while valid_input != True:
        try: 
            start_value = int(input("Input value of starting Range: "))
            end_value = int(input("Input value of end Range: "))
        except ValueError:
            print("Thats not an Integer. Try again.")
            continue

        range_values[0] = start_value
        range_values[1] = end_value

        if start_value > end_value:
            print("Your start value bigger then your end value. Try again.")
        elif start_value == end_value:
            print("Your start value == end value. Please try again.")
        else:
            random_number = random.randint(start_value, end_value)
            valid_input = True
    
    return random_number


def user_finds_number(number_to_guess):

    correct_number = False
    remaining_trys = 5
    try_counter = 1
    
    print(f"Remaining trys: {remaining_trys}")

    while (correct_number != True):
        user_guess = int(input("Type your guess: "))

        if remaining_trys == 1:
            print(f"No more trys left. You lost! Correct Number was: {number_to_guess}")
            break
        elif user_guess > number_to_guess:
            remaining_trys -= 1
            try_counter += 1
            print(f"Your number is too high.  Remaining trys: {remaining_trys}")
        elif user_guess < number_to_guess:
            remaining_trys -= 1
            try_counter += 1
            print(f"Your number is too low.   Remaining trys: {remaining_trys}")
        else:
            print("Correct number!!")
            print(f"You needed {try_counter} trys!")
            correct_number =True
            





def main():
    number_to_guess = generate_number_to_guess()

    user_finds_number(number_to_guess)




if __name__ == "__main__":
    main()