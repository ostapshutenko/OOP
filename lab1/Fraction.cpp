#include "Fraction.h"
//#include <iostream>
Fraction::Fraction(int chislit, int znamenat)

{

	try
	{
		if (znamenat == 0) // ���� ����������� ����� ����, �� �� ������������� � ������������ ����� ������
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



// ��������

Fraction Fraction::operator+(Fraction& s)

{
	Fraction Sum;

	// �������� ��� ����� � ������ �����������

	Sum.a = a * s.b + b * s.a;

	Sum.b = b * s.b;

	try
	{
		if (Sum.b == 0) // ���� ����������� ����� ����, �� �� ������������� � ������������ ����� ������
			throw 1;

		// ����������� �������� ����� ����� ������������ ��������� ������ ����� � ��������� ������

		else {
			// ����������� �������� ����� ����� ������������ ����������� ������ � ������ �����
			Sum.b = b * s.b;
		}

	}
	catch (int thr)
	{
		Sum.b = 1;
	}

	// ���������� ����� �����, ���������� ������ ������ � ������ �����

	return Sum.Reduction();
}
// ��������
Fraction Fraction::operator-(Fraction& s)

{
	Fraction Sum;

	// �������� ��� ����� � ������ �����������

	Sum.a = a * s.b - b * s.a;

	Sum.b = b * s.b;

	try
	{
		if (Sum.b == 0) // ���� ����������� ����� ����, �� �� ������������� � ������������ ����� ������
			throw 1;

		// ����������� �������� ����� ����� ������������ ��������� ������ ����� � ��������� ������

		else {
			// ����������� �������� ����� ����� ������������ ����������� ������ � ������ �����
			Sum.b = b * s.b;
		}

	}
	catch (int thr)
	{
		Sum.b = 1;
	}

	// ���������� ����� �����, ��������� ������ ������ � ������ �����

	return Sum.Reduction();
}
// ���������

Fraction Fraction::operator*(Fraction& s)

{

	Fraction Mult;

	// ��������� �������� ����� ����� ������������ ��������� ������ � ������ �����

	Mult.a = a * s.a;

	
	Mult.b = b * s.b;

	// ���������� ����� �����, ���������� ������������� ������ � ������ �����

	try
	{
		if (Mult.b == 0) // ���� ����������� ����� ����, �� �� ������������� � ������������ ����� ������
			throw 1;

		// ����������� �������� ����� ����� ������������ ��������� ������ ����� � ��������� ������

		else {
			// ����������� �������� ����� ����� ������������ ����������� ������ � ������ �����
			Mult.b = b * s.b;
		}

	}
	catch (int thr)
	{
		Mult.b = 1;
	}

	return Mult.Reduction();

}

// �������

Fraction Fraction::operator/(Fraction& s)

{

	Fraction Div;

	// ��������� �������� ����� ����� ������������ ��������� ������ ����� � ����������� ������

	Div.a = a * s.b;

	// �������� �� �� ��� ��������� ������ ����� �� ����� 0

	try
	{
		if (Div.b == 0) // ���� ����������� ����� ����, �� �� ������������� � ������������ ����� ������
			throw 1;

		// ����������� �������� ����� ����� ������������ ��������� ������ ����� � ��������� ������

		else {
			Div.b = b * s.a;
		}

	}
	catch(int thr)
	{
		Div.b = 1;
	}

	// ���������� ����� ���������� �� ������

	return Div.Reduction();

}

// ����������

Fraction Fraction::Reduction()

{

	Fraction Red;

	Red.a = a;

	Red.b = b;

	// ���� ����� �������� ��� ��������� � �����������, ����� ��������� �����

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

	// ���������� ����������� �����

	return Red;

}

// ���������

int Fraction::Comparison(Fraction& s)

{

	Fraction d1, d2;

	// �������� ��� ����� � ������ �����������

	d1.a = a * s.b;

	d1.b = b * s.b;

	d2.a = s.a * b;

	d2.b = s.b * b;

	// ���������� ��������� ����� ���������� � ������ �����������

	if (d1.a > d2.a)

		return 1;

	if (d1.a < d2.a)

		return 2;

	if (d1.a == d2.a)

		return 0;

}

// �����

int Fraction::getChis()
{
	return this->a;
}
int Fraction::getZnam()
{
	return this->b;
}

// ������������� �����(���������) - ��������� � ����������� 

void Fraction::set(int a, int b)

{
	this->a = a;

	try
	{
		if (b == 0) // ���� ����������� ����� ����, �� �� ������������� � ������������ ����� ������
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
