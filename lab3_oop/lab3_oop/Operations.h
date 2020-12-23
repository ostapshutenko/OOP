#pragma once

#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"

using namespace std;
class Operations
{
private:

	int _flag = 0;

public:

	// Метод сравнения площадей
	void Compare(Shape* p1, Shape* p2);

	// Метод проверки пересечения площадей
	void IsIntersect(Shape* p1, Shape* p2);

	// Метод проверки включения фигур друг в друга
	void IsInclude(Shape* p1, Shape* p2);

	// Метод проверки включения прямоугольника в треугольник
	bool rec_in_tre(Shape* p1, Shape* p2);

	// Метод проверки включения треугольника в прямоугольник
	bool tre_in_rec(Point A, Point B, Point C, Point P);
};
