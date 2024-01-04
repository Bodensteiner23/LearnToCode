import math


def is_prime(num):
    """Checks if a number is prime or not.

    Args:
        num (int): Number to check.

    Returns:
        bool: True if prime, False otherwise.
    """
    for i in range(2, math.floor(math.sqrt(num) + 1)):
        if num % i == 0:
            return False
    return True


def find_10001st_prime():
    """Finds the 10001st prime number.

    Returns:
        int: The 10001st prime number.
    """
    count = 0
    the_prime = 0
    nb = 2
    while True:
        if is_prime(nb):
            the_prime = nb
            count += 1
        if count == 10001:
            return the_prime
        nb += 1
