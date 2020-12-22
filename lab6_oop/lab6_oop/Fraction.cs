using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab6_oop
{
	class Fraction

	{
		private int _numerals = 0; //a-числитель 
		private int _denominator = 1; //b-знаменатель
		/*public static void Main()
		{
			int _numerals=0;
			int _denominator=1;
		}*/
		public Fraction()
		{
			this._numerals = 0;
			this._denominator = 1;
		}
		public Fraction(Fraction f)
		{
			this._numerals = (f._numerals);
			this._denominator = (f._denominator);
		}
		public Fraction(int numerals, int denominator)
		{
			this._numerals=(numerals);
			this._denominator=(denominator);
		}
		public Fraction add(Fraction buf)
		{
			Fraction Sum = new Fraction();

			Sum._numerals = _numerals * buf._denominator + _denominator * buf._numerals;

			Sum._denominator = _denominator * buf._denominator;

			Sum.Reduction();

			return Sum;
		}
		public Fraction sub(Fraction buf)
		{
			Fraction Sum = new Fraction();

			// Приводим обе дроби к общему знаменателю

			Sum._numerals = _numerals * buf._denominator - _denominator * buf._numerals;

			Sum._denominator = _denominator * buf._denominator;
			Sum.Reduction();
			return Sum;
		}
		public Fraction mult(Fraction buf)
		{
			Fraction Mult = new Fraction();

			// Числитель конечной дроби равен произведению числителя первой и второй дроби

			Mult._numerals = _numerals * buf._numerals;

			Mult._denominator = _denominator * buf._denominator;

			Mult.Reduction();

			return Mult;

		}
		public Fraction div(Fraction buf)
		{
			Fraction Div = new Fraction();

			// Числитель конечной дроби равен произведению числителя первой дроби и знаменателя второй

			Div._numerals = _numerals * buf._denominator;
			Div._denominator = _denominator * buf._numerals;

			// Возвращаем дробь поделенную на другую

			Div.Reduction();

			return Div;

		}
		public Fraction Reduction()
		{
			int containers = _numerals;
			if (_numerals > _denominator)
				containers = _denominator;
			// Ищем общий делитель для числителя и знаменателя, чтобы сократить дробь

			for (int i = containers; i >1; i--)
			{
				if ((_numerals % i) == 0 && (_denominator % i) == 0)
				{

					_numerals = _numerals / i;

					_denominator = _denominator / i;

					containers = containers / i;

				}
			}

			//Fraction Red(_numerals, _denominator);

			return this;
		}
		public string Comparison(Fraction buf)
		{
			Fraction d1 = new Fraction(), d2 = buf;

			// Приводим обе дроби к общему знаменателю

			d1._numerals = _numerals * buf._denominator;

			d2._numerals = buf._numerals * _denominator;

			if (!(d1.getException() || d2.getException()))
				return "exist";

			if (d1._numerals > d2._numerals)

				return "f1>f2";

			if (d1._numerals < d2._numerals)

				return "f1<f2";

			if (d1._numerals == d2._numerals)

				return "f1=f2";
			return "exist";
		}
		public int getNumerals()
		{
			return _numerals;
		}
		public int getDenominator()
		{
			return _denominator;
		}
		public bool getException()
		{
			if (_denominator == 0)
				return false;
			return true;
		}
		public void setNumerals(int numerals)
		{
			_numerals = numerals;
		}
		public void setDenominator(int denominator)
		{
			_denominator = denominator;
		}



	}
}