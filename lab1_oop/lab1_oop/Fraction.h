#pragma once
class Fraction

{
public:

	Fraction() {};
	//Fraction(int numerals, int denominator);
	Fraction(Fraction& f) :_numerals(f._numerals), _denominator(f._denominator) {};
	Fraction(int numerals, int denominator) :_numerals(numerals), _denominator(denominator) {};

	~Fraction() {};

	Fraction operator+(Fraction& buf);

	Fraction operator-(Fraction& buf);

	Fraction operator*(Fraction& buf);

	Fraction operator/(Fraction& buf);

	Fraction Reduction();

	int Comparison(Fraction& buf)const;

	int getNumerals()const;
	int getDenominator()const;
	bool getException()const;

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