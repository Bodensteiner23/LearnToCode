namespace Project_Euler
{
    internal class Program
    {
        public static void Main(string[] args)
        {
        
            Solution.Problem_1 pb1 = new Solution.Problem_1();
            
            
            pb1.Calculate_Sum();

            //Output Sum in Console
            System.Console.WriteLine(pb1._sum);
        }
    }
}