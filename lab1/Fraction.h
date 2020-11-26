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

	Fraction(int chislit, int znamenat);



	// ��������

	Fraction operator+(Fraction& s);

	// ��������

	Fraction operator-(Fraction& s);

	// ���������

	Fraction operator*(Fraction& s);

	// �������

	Fraction operator/(Fraction& s);

	// ����������

Fraction Reduction();

	// ���������

int Comparison(Fraction& s);

	// �����

int getChis();
int getZnam();

	// ������������� �����(���������) - ��������� � ����������� 

void set(int a, int b);
void setChisl(int a);
void setZnam(int b);

private:

	int a = 0; //a-��������� 
	int b = 1; //b-�����������

};