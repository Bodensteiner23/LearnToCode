import numpy as np
import math

primeRange = 2000000
primeTestArray = np.full(primeRange, False, dtype=bool)
primeNumbersArray = list(range(2, primeRange + 1))


def SieveofEratosthenes():
    primeSum = 0
    for i in range(2, int(math.sqrt(primeRange))):
        if primeTestArray[i]:
            # If it is no Prime Number then delete multiple of number
            for j in range(i * i, primeRange):
                primeTestArray[j] = True

    # Calculate Sum of all remaining values
    for i in primeNumbersArray:
        if not primeTestArray[i - 2]:
            # primeSum += primeNumbersArray[i - 2]
            primeSum += primeNumbersArray[i]

    return primeSum
