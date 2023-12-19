namespace Project_Euler.Solution
{
    public class Problem_5
    {
        /* ======================= Public Functions ======================== */
        public long FindSmallestMultiple()
        {

            long numberToCheck = 1;
            int divider = 1;
            
            // Check if the number is divisible by all numbers from 1 to 20
            while (divider <= 20)
            {
                // If the number is divisible by the divider, increment the divider 
                if (numberToCheck % divider == 0)
                {
                    divider++;
                }
                // If the number is not divisible by the divider, reset the divider and increment the number
                else
                {
                    numberToCheck++;
                    divider = 1;
                }
            }

            return numberToCheck;
        }
    }
}
