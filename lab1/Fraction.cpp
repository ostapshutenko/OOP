#include "Fraction.h"
//#include <iostream>
Fraction::Fraction(int chislit, int znamenat)

{

	try
	{
		if (znamenat == 0) // Если знаменатель равен нулю, то мы предупреждаем о неправильном вводе данных
			throw 1;
		else
		{
		this->a = chislit;
		this->b = znamenat;
		}
	}
	catch (int thr)
	{
		this->a = chislit;
		this->b = 1;
	}
}



// Сложение

Fraction Fraction::operator+(Fraction& s)

{
	Fraction Sum;

	// Приводим обе дроби к общему знаменателю

	Sum.a = a * s.b + b * s.a;

	Sum.b = b * s.b;

	try
	{
		if (Sum.b == 0) // Если знаменатель равен нулю, то мы предупреждаем о неправильном вводе данных
			throw 1;

		// Знаменатель конечной дроби равен произведению числителя второй дроби и числителя второй

		else {
			// Знаменатель конечной дроби равен произведению знаменателя первой и второй дроби
			Sum.b = b * s.b;
		}

	}
	catch (int thr)
	{
		Sum.b = 1;
	}

	// Возвращаем новую дробь, являющейся суммой первой и второй дроби

	return Sum.Reduction();
}
// разность
Fraction Fraction::operator-(Fraction& s)

{
	Fraction Sum;

	// Приводим обе дроби к общему знаменателю

	Sum.a = a * s.b - b * s.a;

	Sum.b = b * s.b;

	try
	{
		if (Sum.b == 0) // Если знаменатель равен нулю, то мы предупреждаем о неправильном вводе данных
			throw 1;

		// Знаменатель конечной дроби равен произведению числителя второй дроби и числителя второй

		else {
			// Знаменатель конечной дроби равен произведению знаменателя первой и второй дроби
			Sum.b = b * s.b;
		}

	}
	catch (int thr)
	{
		Sum.b = 1;
	}

	// Возвращаем новую дробь, разностью суммой первой и второй дроби

	return Sum.Reduction();
}
// Умножение

Fraction Fraction::operator*(Fraction& s)

{

	Fraction Mult;

	// Числитель конечной дроби равен произведению числителя первой и второй дроби

	Mult.a = a * s.a;

	
	Mult.b = b * s.b;

	// Возвращаем новую дробь, являющейся произведением первой и второй дроби

	try
	{
		if (Mult.b == 0) // Если знаменатель равен нулю, то мы предупреждаем о неправильном вводе данных
			throw 1;

		// Знаменатель конечной дроби равен произведению числителя второй дроби и числителя второй

		else {
			// Знаменатель конечной дроби равен произведению знаменателя первой и второй дроби
			Mult.b = b * s.b;
		}

	}
	catch (int thr)
	{
		Mult.b = 1;
	}

	return Mult.Reduction();

}

// Деление

Fraction Fraction::operator/(Fraction& s)

{

	Fraction Div;

	// Числитель конечной дроби равен произведению числителя первой дроби и знаменателя второй

	Div.a = a * s.b;

	// Проверка на то что числитель второй дроби не равен 0

	try
	{
		if (Div.b == 0) // Если знаменатель равен нулю, то мы предупреждаем о неправильном вводе данных
			throw 1;

		// Знаменатель конечной дроби равен произведению числителя второй дроби и числителя второй

		else {
			Div.b = b * s.a;
		}

	}
	catch(int thr)
	{
		Div.b = 1;
	}

	// Возвращаем дробь поделенную на другую

	return Div.Reduction();

}

// Сокращение

Fraction Fraction::Reduction()

{

	Fraction Red;

	Red.a = a;

	Red.b = b;

	// Ищем общий делитель для числителя и знаменателя, чтобы сократить дробь

	for (int i = 1; i <= a && i <= b; i++)

	{

		int aa = a % i;

		int bb = b % i;

		if (!(a % i) && !(b % i))

		{

			Red.a = a / i;

			Red.b = b / i;

		}

	}

	// Возвращаем сокращённую дробь

	return Red;

}

// Сравнение

int Fraction::Comparison(Fraction& s)

{

	Fraction d1, d2;

	// Приводим обе дроби к общему знаменателю

	d1.a = a * s.b;

	d1.b = b * s.b;

	d2.a = s.a * b;

	d2.b = s.b * b;

	// Сравниваем числителя после приведения к общему знаменателю

	if (d1.a > d2.a)

		return 1;

	if (d1.a < d2.a)

		return 2;

	if (d1.a == d2.a)

		return 0;

}

// Вывод

int Fraction::getChis()
{
	return this->a;
}
int Fraction::getZnam()
{
	return this->b;
}

// Инициализация дроби(изменение) - числителя и знаменателя 

void Fraction::set(int a, int b)

{
	this->a = a;

	try
	{
		if (b == 0) // Если знаменатель равен нулю, то мы предупреждаем о неправильном вводе данных
			throw 1;
		else
		{
			this->b = b;
		}
	}
	catch (int thr)
	{
		this->b = 1;
	}

	
}
void Fraction::setChisl(int a)

{
	this->a = a;
}
void Fraction::setZnam(int b)
{
	try
	{
		if (b == 0)
			throw 1;
		else
		{
		this->b = b;
		}
	}
	catch (int thr)
	{
		this->b = 1;
	}
}
