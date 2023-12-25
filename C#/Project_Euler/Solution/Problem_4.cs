using System;
using System.Linq;

namespace Project_Euler.Solution
{
    
    public class Problem_4
    {
        /* ======================= Public Functions ======================= */
        /// <summary>
        /// Find the largest palindrome made from the product of two 3-digit numbers.
        /// </summary>
        /// <returns>
        /// Largest Palindrome.
        /// </returns>
        public int FindLargestPalindromeProduct()
        {
            int _largestPalindrome = 0;
            // Iterate through all products of two 3-digit numbers
            for(int _firstNumber = 1; _firstNumber < 1000; _firstNumber++)
            {
                for(int _seccondNumber = 1; _seccondNumber < 1000; _seccondNumber++)
                {
                    int _product = (_firstNumber * _seccondNumber);
                    
                    // Check if the product is a Palindrome
                    bool _isPalindrom = IsPalindrome(_product);
                    if(_isPalindrom && _product > _largestPalindrome)
                    {
                        // If larger, upate _largestPalindrome
                        _largestPalindrome = _product;
                    }

                }
            }

            return _largestPalindrome;
        }

        /* ======================= Private Functions ======================= */
        /// <summary>
        /// Check if a number is a Palindrome.
        /// </summary>
        /// <param name="number"> Number you want to check </param>
        /// <returns>
        /// True if it is a Palindrome Number.
        /// False if it is not a Palindrome Number.
        /// </returns>
        private bool IsPalindrome(int number)
        {
            string numberString = number.ToString();
            string reversedNumberString = new string(numberString.Reverse().ToArray());
            
            // Return true if it is a Palindrom Number
            return numberString == reversedNumberString;
        }
        
    }
}

