using System;

namespace Project_Euler.Solution
{
    public class Problem_7
    {

        int primeCounter = 0;
        int numberToCheck = 2;

        /// <summary>
        /// Find 10001 Prime Number.
        /// </summary>
        /// <returns>
        /// Returns 10001 Prime Number, if not found 0.
        /// </returns>
        public int FindPrimeNumber()
        {
            while(primeCounter <= 10001)
            {
                if(IsPrime(numberToCheck))
                {
                    primeCounter++;
                }

                if(primeCounter == 10001)
                {
                    return numberToCheck;
                }

                numberToCheck++;
            }

            return 0;
        }

        /// <summary>
        /// Check if the Number is a Prime Number.
        /// </summary>
        /// <param name="number"> Number to check if Prime </param>
        /// <returns>
        /// True if Number is a Prime Number. Otherwise False.
        /// </returns>
        private bool IsPrime(int number)
        {
            if(number == 2)
            {
                return true;
            }

            // Even Number can't be Prime Numbers
            if(number % 2 == 0)
            {
                return false;
            }

            // Check if Number is Prime
            for(int i = 3; i < number; i += 2)
            {
                if((number % i)== 0)
                {
                    return false;
                }
            }

            // Number is not divisible -> Prime Number 
            return true;

        }
    }
}


