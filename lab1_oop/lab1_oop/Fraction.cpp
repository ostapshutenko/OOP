#include "Fraction.h"
#include <cstdlib>

/*
Fraction::Fraction(int numerals, int denominator)
{
	_numerals = numerals;
	_denominator = denominator;
}
*/

/*
Fraction::Fraction(Fraction& f)
{
	_numerals = f._numerals;
	_denominator = f._denominator;
}
*/

Fraction Fraction::operator+(Fraction& buf)
{
	Fraction Sum;

	Sum._numerals = _numerals * buf._denominator + _denominator * buf._numerals;

	Sum._denominator = _denominator * buf._denominator;

	Sum.Reduction();

	return Sum;
}

Fraction Fraction::operator-(Fraction& buf)
{
	Fraction Sum;


	Sum._numerals = _numerals * buf._denominator - _denominator * buf._numerals;

	Sum._denominator = _denominator * buf._denominator;

	Sum.Reduction();

	return Sum;
}

Fraction Fraction::operator*(Fraction& buf)
{
	Fraction Mult;

	Mult._numerals = _numerals * buf._numerals;

	Mult._denominator = _denominator * buf._denominator;
	
	Mult.Reduction();

	return Mult;

}

Fraction Fraction::operator/(Fraction& buf)
{
	Fraction Div;

	Div._numerals = _numerals * buf._denominator;
	Div._denominator = _denominator * buf._numerals;

	Div.Reduction();

	return Div;

}

Fraction Fraction::Reduction()
{
	int containers = _numerals;
	if (_numerals > _denominator)
		containers = _denominator;
	// »щем общий делитель дл€ числител€ и знаменател€, чтобы сократить дробь

	for (int i=1;i<=containers; i++)
	{
		if ((_numerals % i)==0 && (_denominator % i)==0)
		{

			_numerals = _numerals / i;

			_denominator = _denominator / i;

			containers = containers / i;

		}
	}
	
	Fraction Red(_numerals, _denominator);

	return Red;
}

int Fraction::Comparison(Fraction& buf)const
{
	Fraction d1, d2;

	d1._numerals = _numerals * buf._denominator;

	d2._numerals = buf._numerals * _denominator;

	d1._denominator = _denominator * buf._denominator;

	d2._denominator = buf._denominator * _denominator;

	if ( !(d1.getException() || d2.getException()) )
		return -1;

	if (d1._numerals > d2._numerals)

		return 1;

	if (d1._numerals < d2._numerals)

		return 2;

	if (d1._numerals == d2._numerals)

		return 0;

}

bool Fraction::getException()const
{
	if (_denominator == 0)
		return false;
	return true;
}

int Fraction::getNumerals()const
{
	return _numerals;
}

int Fraction::getDenominator()const
{
	return _denominator;
}

//ввод 

/*
Fraction Fraction::setFraction(Fraction& f)
{
	_numerals = f._numerals;
	_denominator = f._denominator;
}
*/
/*
Fraction Fraction::setFraction(int numerals, int denominator)
{
	_numerals = numerals;
	_denominator = denominator;
}
*/
void Fraction::setNumerals(int numerals)
{
	_numerals = numerals;
}

void Fraction::setDenominator(int denominator)
{
	_denominator = denominator;
}
