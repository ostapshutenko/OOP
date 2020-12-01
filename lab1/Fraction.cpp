#include "Fraction.h"
#include <cstdlib>
Fraction::Fraction(int numerals, int denominator)

{
	this->set(numerals, denominator);
	/*
	try
	{
		if (denominator == 0) // Если знаменатель равен нулю, то мы предупреждаем о неправильном вводе данных
			throw 1;
		else
		{
		this->numerals = numerals;
		this->denominator = denominator;
		this->except = false;
		}
	}
	catch (int thr)
	{
		if (thr == 1)
		{
			this->except = true;
		}
	}
	*/
}



// Сложение

Fraction Fraction::operator+(Fraction& buf)

{
	Fraction Sum;

	// Приводим обе дроби к общему знаменателю

	Sum.numerals = numerals * buf.denominator + denominator * buf.numerals;

	Sum.denominator = denominator * buf.denominator;
	this->except = false;
	try
	{
		if (Sum.denominator == 0) // Если знаменатель равен нулю, то мы предупреждаем о неправильном вводе данных
			throw 1;
	}
	catch (int thr)
	{
		
			Sum.except = true;
		
	}

	// Возвращаем новую дробь, являющейся суммой первой и второй дроби

	return Sum.Reduction();
}
// разность
Fraction Fraction::operator-(Fraction& buf)

{
	Fraction Sum;

	// Приводим обе дроби к общему знаменателю

	Sum.numerals = numerals * buf.denominator - denominator * buf.numerals;

	Sum.denominator = denominator * buf.denominator;
	
	Sum.except = false;

	try
	{
		if (Sum.denominator == 0) // Если знаменатель равен нулю, то мы предупреждаем о неправильном вводе данных
			throw 1;
	}
	catch (int thr)
	{
	
			Sum.except = true;
		
	}

	// Возвращаем новую дробь, разностью суммой первой и второй дроби

	return Sum.Reduction();
}
// Умножение

Fraction Fraction::operator*(Fraction& buf)

{

	Fraction Mult;

	// Числитель конечной дроби равен произведению числителя первой и второй дроби

	Mult.numerals = numerals * buf.numerals;

	
	Mult.denominator = denominator * buf.denominator;
	
	Mult.except = false;
	// Возвращаем новую дробь, являющейся произведением первой и второй дроби

	try
	{
		if (Mult.denominator == 0) // Если знаменатель равен нулю, то мы предупреждаем о неправильном вводе данных
			throw 1;
	}
	catch (int thr)
	{

			Mult.except = true;
		
	}

	return Mult.Reduction();

}

// Деление

Fraction Fraction::operator/(Fraction& buf)

{

	Fraction Div;

	// Числитель конечной дроби равен произведению числителя первой дроби и знаменателя второй

	Div.numerals = numerals * buf.numerals;
	Div.denominator = denominator * buf.numerals;
	Div.except = false;
	// Проверка на то что числитель второй дроби не равен 0

	try
	{
		if (Div.denominator == 0 || buf.denominator) // Если знаменатель равен нулю, то мы предупреждаем о неправильном вводе данных
			throw 1;
	}
	catch(int thr)
	{

			Div.except = true;
		
	}

	// Возвращаем дробь поделенную на другую

	return Div.Reduction();

}

// Сокращение

Fraction Fraction::Reduction()

{

	Fraction Red;

	Red.numerals = numerals;

	Red.denominator = denominator;
	int containers = numerals;
	if (numerals > denominator)
		containers = denominator;
	// Ищем общий делитель для числителя и знаменателя, чтобы сократить дробь

	for (int i=1;i<=containers; i++)

	{

		if ((numerals % i)==0 && (denominator % i)==0)

		{

			Red.numerals = numerals / i;

			Red.denominator = denominator / i;

		}

	}

	if (Red.denominator == 0)
		Red.except = true;
	// Возвращаем сокращённую дробь

	return Red;
}

// Сравнение

int Fraction::Comparison(Fraction& buf)const

{

	Fraction d1, d2;

	// Приводим обе дроби к общему знаменателю

	d1.numerals = numerals * buf.denominator;

	d1.denominator = denominator * buf.denominator;

	d2.numerals = buf.numerals * denominator;

	d2.denominator = buf.denominator * denominator;

	if (this->except || buf.except)
		return -1;

	if (d1.numerals > d2.numerals)

		return 1;

	if (d1.numerals < d2.numerals)

		return 2;

	if (d1.numerals == d2.numerals)

		return 0;

}

// Вывод


bool Fraction::getException()const
{
	return this->except;
}

int Fraction::getNumerals()const
{
	return this->numerals;
}
int Fraction::getDenominator()const
{
	return this->denominator;
}

// Инициализация дроби(изменение) - числителя и знаменателя 

void Fraction::set(int numerals, int denominator)

{
	this->numerals = numerals;
	this->denominator = denominator;
	this->except = false;

	try
	{
		if (denominator == 0) // Если знаменатель равен нулю, то мы предупреждаем о неправильном вводе данных
			throw 1;
	}
	catch (int thr)
	{

			this->except = true;

	}
}
void Fraction::setNumerals(int numerals)

{
	this->numerals = numerals;
}
void Fraction::setDenominator(int denominator)
{
	this->denominator = denominator;
	this->except = false;
	try
	{
		if (denominator == 0)
			throw 1;
	}
	catch (int thr)
	{

			this->except = true; 

	}
}
