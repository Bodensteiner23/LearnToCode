using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.VisualStyles;

namespace Calculator
{
    public partial class Form1 : Form
    {
        /* ========================== Variables ============================ */
        string[] _operatorList = { "+", "-", "x", "*" };
        string _operator = null;
        private int _reservedNumbers1 = 0;
        private int _reservedNumbers2 = 0;
        string _userNumber = null;
        private int _change = 0  ;
        bool _newNumberEntry = false;
        

        public Form1()  //Constructor for the class, sets up the Object
        {
            InitializeComponent();
        }

        /* ======================= Private Functions ======================= */
        private void button_clicked(object sender, EventArgs e)
        {

            if (sender is Button button)
            {
                _userNumber = button.Text;

                if(_reservedNumbers1 == 0){
                        outputData.Text += _userNumber;
                }
                else{
                    switch(_operator){
                        //Readout Operator that is input by user
                        case "+":
                            if(_newNumberEntry == true){
                                _reservedNumbers2 = Convert.ToInt32(_userNumber);
                                _change = _reservedNumbers1 + _reservedNumbers2;                            
                                outputData.Text = Convert.ToString(_change);

                                _operator = null;

                                //If Operation is done, reset _newNumberEntry
                                _newNumberEntry = false;
                            }
                           
                            
                            break;
                        case "-":
                            
                            break;
                        case "x":

                            break;
                        case "/":

                            break;
                        default:
                            outputData.Text += _userNumber; 
                            break;
                    }
                }    
            }
            //Output clicked number into 
            // outputData.Text += _userNumber;
            
        }

        private void operator_clicked(object sender, EventArgs e)
        {
            if (sender is Button button)
            {
                //Check if Operator is valid
                if (_operatorList.Contains(button.Text))
                {
                    //Readout Number that is stored in Label
                    _reservedNumbers1 = Convert.ToInt32(outputData.Text);
                    
                    //Save Operator
                    _operator = button.Text;
                    
                    //Output Operator
                    cachingValue.Text += _reservedNumbers1 + " " + _operator + " ";
                    
                   
                    _newNumberEntry = true;
                }

                
            }
            
            
            
            //Save Label Number into _reservedNumbers1 and start new to output in label
        }

    }
}