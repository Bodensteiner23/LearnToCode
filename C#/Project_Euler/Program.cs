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

            //Ask the user which problem to solve
            System.Console.Write("Enter the problem number to solve: ");
            string _problem = System.Console.ReadLine();
            long _solvedProblem = 0;


            switch (_problem)
            {
                case "Problem 1":
                    _solvedProblem = pb1.Calculate_Sum();
                    break;
                case "Problem 2":
                    _solvedProblem = pb2.Calculate_Fibbonaci_Sum();
                    break;
                case "Problem 3":
                    _solvedProblem = pb3.SolveProblem();
                    
                    break;

                default:
                    System.Console.WriteLine("Invalid input. Please enter valid Problem. For example: Problem 1");
                    break;
            }

            System.Console.WriteLine("Result " + _problem + ": " + _solvedProblem);




            //Create a switch case to select with Problem to solve

            //Output Sum in Console
        }
    }
}