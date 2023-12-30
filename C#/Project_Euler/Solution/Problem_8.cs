
namespace Project_Euler.Solution
{
    public class Problem_8
    {
        
        public int ConvertStringToInt(string number)
        {
            int numberToCheck = 0;
            for(int i = 0; i < 13; i++)
            {
                numberToCheck += int.Parse(number[i].ToString());
            }

            return numberToCheck;
        }




    }
}