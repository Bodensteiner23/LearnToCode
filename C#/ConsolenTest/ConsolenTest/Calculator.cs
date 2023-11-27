namespace ConsolenTest;

public class Calculator
{
    /* ======================== Variables ======================== */


    private string[] _operatorList = { "+", "-", "*", "/" };
    private float _userFirstNumber = 0;
    private float _userSecondNumber = 0;
    private float _result = 0;
    private string _userOperator = null!;
    
    /* ======================== Functions ======================== */

    private float UserEnterNumber()
    {
        float userNumber = 0;
        
        Console.Write("Enter your Number: ");
        userNumber = Convert.ToSingle(Console.ReadLine());

        return userNumber;

    }

    private string UserEnterOperator()
    {
        string userOperator = null!;
        
        Console.Write("Enter your Operator: ");
        userOperator = Console.ReadLine()!;

        return userOperator;
    }

    private void CheckForOperator()
    {
        switch (_userOperator)
        {
            case "+":
                _result = _userFirstNumber + _userSecondNumber;
                break;
            case "-":
                _result = _userFirstNumber - _userSecondNumber;
                break;
            case "*":
                _result = _userFirstNumber * _userSecondNumber;
                break;
            case "/":
                _result = _userFirstNumber / _userSecondNumber;
                break;
        }
    }

    private void OutputResult()
    {
        Console.WriteLine("The Result is: " + _result + "\n");
        
    }
    
    public void CalculatorLoop()
    {
        while (true)
        {
            _userFirstNumber = UserEnterNumber();

            _userOperator = UserEnterOperator();

            _userSecondNumber = UserEnterNumber();

            CheckForOperator();

            OutputResult();

        }
    }
    
    
    
    
}