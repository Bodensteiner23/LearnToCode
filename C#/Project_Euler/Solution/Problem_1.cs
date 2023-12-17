namespace Project_Euler.Solution
{
    public class Problem_1
    {
        /* ========================== Variables ============================ */
        int _limitNumber = 1001;
        public int _sum = 0;

        /* ======================= Private Functions ======================= */
        public int Calculate_Sum()
        {
            for(int i = 0; i < _limitNumber; i++)
            {
                if((i % 3 == 0) || (i % 5 == 0) || (i % 6 == 0) || (i % 9 == 0))
                {
                    _sum = _sum + i;
                }
            }

            return _sum;
        }


    }
}