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
        private int _reservedNumbers1 = 0;
        private int _reservedNumbers2 = 0;
        

        public Form1()  //Constructor for the class, sets up the Object
        {
            InitializeComponent();
        }

        /* ======================= Private Functions ======================= */
        private void button_clicked(object sender, EventArgs e)
        {
            string _userNumber = null;
            
            if (sender is Button button)
            {
                _userNumber = button.Text;
            }
            //Output clicked number into 
            outputData.Text += _userNumber;
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
                    
                }
            }
            
            
            
            //Save Label Number into _reservedNumbers1 and start new to output in label
        }
    }
}