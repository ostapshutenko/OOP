using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace lab6_oop
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Add_Click(object sender, EventArgs e)
        {
            int num1, num2;
            int dnum1=1, dnum2=1;
            if (int.TryParse(Numerals1.Text,out num1) && int.TryParse(Numerals2.Text, out num2) &&
                (int.TryParse(Denumerals1.Text, out dnum1) || Denumerals1.Text =="") && 
                (int.TryParse(Denumerals2.Text, out dnum2) || Denumerals2.Text == "")) 
            {
                if (Denumerals2.Text == "")
                    dnum2 = 1;
                if (Denumerals1.Text == "")
                    dnum1 = 1;
                    Fraction Frac1 = new Fraction(num1, dnum1);
                Fraction Frac2 = new Fraction(num2, dnum2);
                Frac1 = Frac1.add(Frac2);
                Numerals.Text = Frac1.getNumerals().ToString();
                Denumerals.Text = Frac1.getDenominator().ToString();
                isExist.Text = Frac1.getException().ToString() + ":Ex"; 
            }
            else isExist.Text = "error";
        }


        private void Exist_Click(object sender, EventArgs e)
        {

            int num1, num2;
            int dnum1 = 1, dnum2 = 1;
            if (int.TryParse(Numerals1.Text, out num1) && int.TryParse(Numerals2.Text, out num2) &&
                (int.TryParse(Denumerals1.Text, out dnum1) || Denumerals1.Text == "") &&
                (int.TryParse(Denumerals2.Text, out dnum2) || Denumerals2.Text == ""))
            {
                if (Denumerals2.Text == "")
                    dnum2 = 1;
                if (Denumerals1.Text == "")
                    dnum1 = 1;
                Fraction Frac1 = new Fraction(num1, dnum1);
                Fraction Frac2 = new Fraction(num2, dnum2);

                isExist.Text = Frac1.getException().ToString() + ":Ex 1" + Frac2.getException().ToString() + ":Ex 2";

            }
            else if (int.TryParse(Numerals1.Text, out num1) &&
                (int.TryParse(Denumerals1.Text, out dnum1) || Denumerals1.Text == ""))
            {
                Fraction Frac1 = new Fraction(num1, dnum1);
                isExist.Text = Frac1.getException().ToString() + ":Ex 1"; 
            }

            else isExist.Text = "error";

        }

        private void Sub_Click(object sender, EventArgs e)
        {
            int num1, num2;
            int dnum1 = 1, dnum2 = 1;
            if (int.TryParse(Numerals1.Text, out num1) && int.TryParse(Numerals2.Text, out num2) &&
                (int.TryParse(Denumerals1.Text, out dnum1) || Denumerals1.Text == "") &&
                (int.TryParse(Denumerals2.Text, out dnum2) || Denumerals2.Text == ""))
            {
                if (Denumerals2.Text == "")
                    dnum2 = 1;
                if (Denumerals1.Text == "")
                    dnum1 = 1;
                Fraction Frac1 = new Fraction(num1, dnum1);
                Fraction Frac2 = new Fraction(num2, dnum2);
                Frac1 = Frac1.sub(Frac2);
                Numerals.Text = Frac1.getNumerals().ToString();
                Denumerals.Text = Frac1.getDenominator().ToString();
                isExist.Text = Frac1.getException().ToString() + ":Ex";
            }
            else isExist.Text = "error";
        }

        private void Mult_Click(object sender, EventArgs e)
        {
            int num1, num2;
            int dnum1 = 1, dnum2 = 1;
            if (int.TryParse(Numerals1.Text, out num1) && int.TryParse(Numerals2.Text, out num2) &&
                (int.TryParse(Denumerals1.Text, out dnum1) || Denumerals1.Text == "") &&
                (int.TryParse(Denumerals2.Text, out dnum2) || Denumerals2.Text == ""))
            {
                if (Denumerals2.Text == "")
                    dnum2 = 1;
                if (Denumerals1.Text == "")
                    dnum1 = 1;
                Fraction Frac1 = new Fraction(num1, dnum1);
                Fraction Frac2 = new Fraction(num2, dnum2);
                Frac1 = Frac1.mult(Frac2);
                Numerals.Text = Frac1.getNumerals().ToString();
                Denumerals.Text = Frac1.getDenominator().ToString();
                isExist.Text = Frac1.getException().ToString() + ":Ex";
            }
            else isExist.Text = "error";
        }

        private void Div_Click(object sender, EventArgs e)
        {
            int num1, num2;
            int dnum1 = 1, dnum2 = 1;
            if (int.TryParse(Numerals1.Text, out num1) && int.TryParse(Numerals2.Text, out num2) &&
                (int.TryParse(Denumerals1.Text, out dnum1) || Denumerals1.Text == "") &&
                (int.TryParse(Denumerals2.Text, out dnum2) || Denumerals2.Text == ""))
            {
                if (Denumerals2.Text == "")
                    dnum2 = 1;
                if (Denumerals1.Text == "")
                    dnum1 = 1;
                Fraction Frac1 = new Fraction(num1, dnum1);
                Fraction Frac2 = new Fraction(num2, dnum2);
                Frac1 = Frac1.div(Frac2);
                Numerals.Text = Frac1.getNumerals().ToString();
                Denumerals.Text = Frac1.getDenominator().ToString();
                isExist.Text = Frac1.getException().ToString() + ":Ex";
            }
            else isExist.Text = "error";
        }

        private void Comp_Click(object sender, EventArgs e)
        {
            int num1, num2;
            int dnum1 = 1, dnum2 = 1;
            if (int.TryParse(Numerals1.Text, out num1) && int.TryParse(Numerals2.Text, out num2) &&
                (int.TryParse(Denumerals1.Text, out dnum1) || Denumerals1.Text == "") &&
                (int.TryParse(Denumerals2.Text, out dnum2) || Denumerals2.Text == ""))
            {
                if (Denumerals2.Text == "")
                    dnum2 = 1;
                if (Denumerals1.Text == "")
                    dnum1 = 1;
                Fraction Frac1 = new Fraction(num1, dnum1);
                Fraction Frac2 = new Fraction(num2, dnum2);
                isExist.Text =  Frac1.Comparison(Frac2);;
            }
            else isExist.Text = "error";
        }
    }
}
