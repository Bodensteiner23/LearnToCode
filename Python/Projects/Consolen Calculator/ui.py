class Ui:

    # ================= Class Methods =================
    def display_menu(self):
        """Display the Menu in Console."""

        print("**********************")
        print("      Calculator\n")
        print("Choose one Option:\n")
        print("1. Basic Arithmetic")
        print("2. Calculate Term")
        print("3. Solve Expression")
        print("4. Function Plotter")
        print("5. Unit Converter")
        print("6. Exit Program\n")
        print("**********************\n")

    def basic_arithmetic(self):
        first_number = int(input("Input your first Number: "))
        second_number = int(input("Input your first Number: "))

        arithmetic_sign = input("Choose your Calculation Type ( + ; - ; * ; / ): ")

        arithmetic_choice = {
            "+": lambda x,y: x+y,
            # "-": self.subt_two_numbers,
            # "*": self.mult_two_numbers,
            # "/": self.div_two_numbers
        }

        try:
            print(arithmetic_choice[arithmetic_sign](first_number, second_number))
        except KeyError:
            pass
          #  default()

        # arithmetic_result = arithmetic_choice[]
        # print(arithmetic_result)

    def default(self):
        print("Incorrect Input!")
   
        

    def get_user_choice(self) -> int:
        """Read out user choice and process it. 

        Returns:
            int: Returns user Choice as int.
        """
        user_choice = input("Input your Choice: ")
        user_choice = int(user_choice)

        menu_options = {
            1: self.basic_arithmetic
            }
        
        if user_choice in menu_options:
            menu_options[user_choice]()

        return user_choice





    def display_result(self):
        # Add Code for display here

        pass


    # def display_result(self, a: int, b: float) -> float:
