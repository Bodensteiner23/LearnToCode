
from Problem_7 import find_10001st_prime


def solve_problem():
    """User chooses which problem to solve.

    Returns:
        string: Problem to solve.
        long  : Solution of the Problem.
    """
    problem = input("Enter the problem number to solve: ")

    if problem == "Problem 7":
        solved_problem = find_10001st_prime()
    
    elif problem == "Problem 8":
        # Fill in missing Code
        pass
    
    else:
        print("Invalid input. Please enter valid Problem. For example: Problem 1")
    
    return problem, solved_problem





def main():
    
    # Hand over what problem should be solved
    problem, solved_problem = solve_problem()
    print(f"Result {problem}: {solved_problem}")

if __name__ == "__main__":
    main()