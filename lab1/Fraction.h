#pragma once
class Fraction

{

public:

	// �����������

	Fraction() {};

	// ����������

	~Fraction() {};

	// ����������� ������������ ��������� � �����������, �������� ����������� �� ��������� ����


	// � ���������� � ������������� ���������, � ���������� b - �����������, �� ������ ���� �� �� ����� ����

	Fraction(int numerals, int denominator);



	// ��������

	Fraction operator+(Fraction& buf);

	// ��������

	Fraction operator-(Fraction& buf);

	// ���������

	Fraction operator*(Fraction& buf);

	// �������

	Fraction operator/(Fraction& buf);

	// ����������

Fraction Reduction();

	// ���������

int Comparison(Fraction& buf)const;

	// �����

int getNumerals() const;
int getDenominator()const;
bool getException()const;

	// ������������� �����(���������) - ��������� � ����������� 

void set(int numerals, int denominator);
void setNumerals(int numerals);
void setDenominator(int denominator);

private:
	bool except = false;
	int numerals = 0; //a-��������� 
	int denominator = 1; //b-�����������

};