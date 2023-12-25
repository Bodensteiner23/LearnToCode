using System.Globalization;

namespace Project_Euler.Solution
{
    
    public class Problem_2
    {
        /* ========================== Variables ============================ */
        long _number1 = 1;
        long _number2 = 2;
        long _sum = 0;
        long _fibonacci_Sum = 2;
        
        /* ======================= Private Functions ======================= */
        public long Calculate_Fibbonaci_Sum()
        {
            //Ceck if the higher Number is smaller than 4000000
            while(_number2 <= 4000000)
            {
                _sum = _number1 + _number2;
                
                //Set new Value for Number1 and Number2
                _number1 = _number2;
                _number2 = _sum;
                
                //Check if sum is equal
                if((_sum % 2) == 0)
                {       
                    //Add sum to the fibonacci sum
                    _fibonacci_Sum += _number2;
                }
                
            }

            return _fibonacci_Sum;
        }
    }
}

