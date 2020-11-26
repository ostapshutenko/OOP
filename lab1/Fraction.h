#pragma once
class Fraction

{

public:

	// Конструктор

	Fraction() {};

	// Деструктор

	~Fraction() {};

	// Конструктор присваивания числителя и знаменателя, проверка знаменателя на равенство нулю


	// В переменную а присваивается числитель, в переменную b - знаменатель, но только если он не равен нулю

	Fraction(int numerals, int denominator);



	// Сложение

	Fraction operator+(Fraction& buf);

	// разность

	Fraction operator-(Fraction& buf);

	// Умножение

	Fraction operator*(Fraction& buf);

	// Деление

	Fraction operator/(Fraction& buf);

	// Сокращение

Fraction Reduction();

	// Сравнение

int Comparison(Fraction& buf)const;

	// Вывод

int getNumerals() const;
int getDenominator()const;
bool getException()const;

	// Инициализация дроби(изменение) - числителя и знаменателя 

void set(int numerals, int denominator);
void setNumerals(int numerals);
void setDenominator(int denominator);

private:
	bool except = false;
	int numerals = 0; //a-числитель 
	int denominator = 1; //b-знаменатель

};