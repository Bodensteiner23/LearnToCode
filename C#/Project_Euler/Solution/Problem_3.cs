using System;

namespace Project_Euler.Solution
{
    
    public class Problem_3
    {
        /* ========================== Variables ============================ */
        int[] primeArray = new int[10];
        long _primNumber = 600851475143;
        int _primeArrayCounter = 0;
        /* ======================= Private Functions ======================= */
        private int[] LargestPrimFactor()
        {
            //Get Prime Number
            for(int _isPrim = 2; _isPrim <= _primNumber; _isPrim++)
            {
                if((_primNumber % _isPrim) == 0)
                {

                    _primNumber = _primNumber / _isPrim;

                    primeArray[_primeArrayCounter] = _isPrim;
                    _primeArrayCounter++;

                    _isPrim = 2; 
                }
            }

            return primeArray;
        }
        
        private int FindLargestPrimeInArray()
        {
            int largestNumber = primeArray[0];

            for(int i = 1; i < _primeArrayCounter; i++)
            {
                if(primeArray[i] > largestNumber)
                {
                    largestNumber = primeArray[i];
                }
            }

            return largestNumber;
        }

        /* ======================= Public Functions ======================== */
        public int SolveProblem()
        {
            LargestPrimFactor();
            int largestPrime = FindLargestPrimeInArray();

            return largestPrime;
        }
    }
}

