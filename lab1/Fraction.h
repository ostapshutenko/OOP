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

	Fraction(int chislit, int znamenat);



	// Сложение

	Fraction operator+(Fraction& s);

	// разность

	Fraction operator-(Fraction& s);

	// Умножение

	Fraction operator*(Fraction& s);

	// Деление

	Fraction operator/(Fraction& s);

	// Сокращение

Fraction Reduction();

	// Сравнение

int Comparison(Fraction& s);

	// Вывод

int getChis();
int getZnam();

	// Инициализация дроби(изменение) - числителя и знаменателя 

void set(int a, int b);
void setChisl(int a);
void setZnam(int b);

private:

	int a = 0; //a-числитель 
	int b = 1; //b-знаменатель

};