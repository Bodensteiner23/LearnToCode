using System;

namespace Project_Euler.Solution
{
    
    public class Problem_3
    {
        /* ========================== Variables ============================ */
        int _biggestPrim = 0;
        long _primNumber = 600851475143;

        /* ======================= Public Functions ======================= */
        
        /// <summary>
        /// Calculates the largest prime factor.
        /// </summary>
        /// <returns>
        /// Biggest Prime Factor.
        /// </returns>
        public int LargestPrimeFactor()
        {
            // Iterate through Prime Numbers
            for(int _isPrime = 2; _isPrime <= _primNumber; _isPrime++)
            {
                if((_primNumber % _isPrime) == 0)
                {
                    // If Prime Number is found, update _primNumber and divide by itself
                    _primNumber = _primNumber / _isPrime;

                    // Store biggest Prime Number
                    if(_biggestPrim < _isPrime)
                    {
                        _biggestPrim = _isPrime;
                    }
                    // Reset Prime Number and search for next Prime
                    _isPrime = 2; 
                }
            }
            
            return _biggestPrim;
        }
        
    }
}
