using System;

namespace lab6_oop
{
	class Fraction

	{

		Fraction(Fraction f)
		{
			this._numerals = (f._numerals);
			this._denominator = (f._denominator);
		}
		Fraction(int numerals, int denominator)
		{
			this._numerals(numerals);
			this._denominator(denominator);
		}
		public Fraction add(Fraction buf)
		{
			Fraction Sum;

			Sum._numerals = _numerals * buf._denominator + _denominator * buf._numerals;

			Sum._denominator = _denominator * buf._denominator;

			Sum.Reduction();

			return Sum;
		}
		public Fraction sub(Fraction buf)
		{
			Fraction Sum;

			// Приводим обе дроби к общему знаменателю

			Sum._numerals = _numerals * buf._denominator - _denominator * buf._numerals;

			Sum._denominator = _denominator * buf._denominator;
			Sum.Reduction();
			return Sum;
		}
		public Fraction mult(Fraction buf)
		{
			Fraction Mult;

			// Числитель конечной дроби равен произведению числителя первой и второй дроби

			Mult._numerals = _numerals * buf._numerals;

			Mult._denominator = _denominator * buf._denominator;

			Mult.Reduction();

			return Mult;

		}
		public Fraction div(Fraction buf)
		{
			Fraction Div;

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

			for (int i = 1; i <= containers; i++)
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
		public int Comparison(Fraction buf)
		{
			Fraction d1, d2;

			// Приводим обе дроби к общему знаменателю

			d1._numerals = _numerals * buf._denominator;

			d1._denominator = _denominator * buf._denominator;

			d2._numerals = buf._numerals * _denominator;

			d2._denominator = buf._denominator * _denominator;

			if (!(d1.getException() || d2.getException()))
				return -1;

			if (d1._numerals > d2._numerals)

				return 1;

			if (d1._numerals < d2._numerals)

				return 2;

			if (d1._numerals == d2._numerals)

				return 0;

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


		private int _numerals = 0; //a-числитель 
		private int _denominator = 1; //b-знаменатель
	}
}