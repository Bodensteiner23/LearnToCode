##
#
#


def pythagoreanTriplet():
    for a in range(1, 999):
        for b in range(2, 999):
            checkSum = a + b

            if checkSum > 1000:
                break

            for c in range(3, 999):
                testSumPow = pow(a, 2) + pow(b, 2)
                testC = pow(c, 2)

                if testSumPow == testC:
                    testResult = a + b + c

                    if testResult == 1000:
                        result = a * b * c

                        return result
