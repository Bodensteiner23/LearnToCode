def pythagoreanTriplet():
    """Find Pythagorean Triplet for which a + b + c = 1000.

    Returns:
        int: Product of a * b * c = 1000.
    """
    for a in range(0, 1000):
        for b in range(0, 1000):
            c = 1000 - (a + b)
            if pow(c, 2) == pow(a, 2) + pow(b, 2) and a < b and b < c:
                result = a * b * c
                return result
