namespace Project_Euler
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            //Instance of all Problems
            Solution.Problem_1 pb1 = new Solution.Problem_1();
            Solution.Problem_2 pb2 = new Solution.Problem_2();
            Solution.Problem_3 pb3 = new Solution.Problem_3();
            Solution.Problem_4 pb4 = new Solution.Problem_4();
            Solution.Problem_5 pb5 = new Solution.Problem_5();

            //Ask the user which problem to solve
            System.Console.Write("Enter the problem number to solve: ");
            string problem = System.Console.ReadLine();
            long solvedProblem = 0;


            switch (problem)
            {
                case "Problem 1":
                    solvedProblem = pb1.Calculate_Sum();
                    break;
                case "Problem 2":
                    solvedProblem = pb2.Calculate_Fibbonaci_Sum();
                    break;
                case "Problem 3":
                    solvedProblem = pb3.LargestPrimeFactor();
                    break;
                case "Problem 4":
                    solvedProblem = pb4.FindLargestPalindromeProduct();
                    break;
                case "Problem 5":
                    solvedProblem = pb5.FindSmallestMultiple();
                    break;
                default:
                    System.Console.WriteLine("Invalid input. Please enter valid Problem. For example: Problem 1");
                    break;
            }

            System.Console.WriteLine("Result " + problem + ": " + solvedProblem);




            //Create a switch case to select with Problem to solve

            //Output Sum in Console
        }
    }
}