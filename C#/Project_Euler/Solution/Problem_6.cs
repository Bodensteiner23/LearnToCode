using System;

namespace Project_Euler.Solution
{
    /// <summary>
    /// Calculate difference for Sum and Square Difference Problem
    /// </summary>
    /// <returns>
    /// Difference between Sum and Square.
    /// </returns>
    public class Problem_6
    {
        public int SumSquareDifference()
        {
            int sumOfSquare = 0;
            int squareOfSum = 0;

            // Iterate through 1 to 100
            for(int increment = 1; increment < 101; increment++)
            {
                sumOfSquare = sumOfSquare + (int)Math.Pow(increment, 2);
                
                squareOfSum = squareOfSum + increment;
            }

            squareOfSum = (int)Math.Pow(squareOfSum, 2);

            // Calculate the difference
            int difference = squareOfSum - sumOfSquare;

            return difference;
        }


    }
}