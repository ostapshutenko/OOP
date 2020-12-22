#pragma once
class Fraction

{
public:

	// Конструктор

	Fraction() {};
	//Fraction(int numerals, int denominator);
	Fraction(Fraction& f) :_numerals(f._numerals), _denominator(f._denominator) {};
	Fraction(int numerals, int denominator) :_numerals(numerals), _denominator(denominator) {};
	// Деструктор

	~Fraction() {};

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

	int getNumerals()const;
	int getDenominator()const;
	bool getException()const;

	// Инициализация дроби(изменение) - числителя и знаменателя 

	/*
	Fraction setFraction(Fraction& f);
	Fraction setFraction(int numerals, int denominator);
	*/
	void setNumerals(int numerals);
	void setDenominator(int denominator);

private:
	int _numerals = 0; //a-числитель 
	int _denominator = 1; //b-знаменатель
};